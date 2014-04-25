#!/bin/bash

touch NEWS README AUTHORS ChangeLog

autoreconf -i -v

./configure

find . -type f -name Makefile.am -printf "%h\n" |
	while read line; do
		d=$line
		(cd $d; make Android.mk)
	done

cd ..

# ndk-build has to be in the PATH for this to work
${ANDROID_NDK}/ndk-build V=1
