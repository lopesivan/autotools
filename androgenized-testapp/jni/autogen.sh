#!/bin/bash

function insert_after() {
  FILE="$1"
  PATTERN="$2"
  LINES_TO_INSERT="$3"

  LINE_NUM=`grep -n "$PATTERN" "$FILE" \
  | (IFS=":"; read LINE_NUM _; echo $LINE_NUM;);`

  head -n $LINE_NUM "$FILE"
  echo "$LINES_TO_INSERT"
  tail -n "+`expr $LINE_NUM + 1`" "$FILE"
}


autoscan

insert_after configure.scan "AC_INIT" "
AM_INIT_AUTOMAKE
AC_PROG_LIBTOOL
" > configure.ac
rm configure.scan

autoheader
aclocal
touch NEWS README AUTHORS ChangeLog
libtoolize
automake --add-missing --copy
autoconf

./configure
make Android.mk

cd ..

# ndk-build has to be in the PATH for this to work
${ANDROID_NDK}/ndk-build V=1
