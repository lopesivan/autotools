#!/bin/bash

cat << EOF > configure.ac
#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.68])
AC_INIT([exemplo], [1.0], [lopesivan.ufrj@gmail.com])

AM_INIT_AUTOMAKE($PACKAGE_NAME,$PACKAGE_VERSION)

# Checks for libraries.
LT_INIT

AC_CONFIG_SRCDIR([config.h.in])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CXX
AC_PROG_AWK
AC_PROG_CC
AC_PROG_CPP
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_MAKE_SET

# Checks for libraries.
# FIXME: Replace main with a function in `-ltestlib':
AC_CHECK_LIB([testlib], [main])

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h string.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_SIZE_T

# Checks for library functions.
AC_FUNC_MALLOC

AC_CONFIG_FILES([Makefile
                 src/Makefile])
AC_OUTPUT
###
EOF

rm configure.scan

touch NEWS README AUTHORS ChangeLog
autoreconf -i -v

./configure
make Android.mk

cd ..

# ndk-build has to be in the PATH for this to work
${ANDROID_NDK}/ndk-build V=1
