# configure.ac
# vim:set foldmethod=expr foldexpr=getline(v\:lnum)=~'^##'?'>1'\:'=':

# Process this file with autoconf to produce a configure script.
AC_INIT([hello], [0.02], [ivan@42algoritmos.com.br],
        [hello], [http://42algoritmos.com.br/])

# Force autoconf to be at least this version number:
AC_PREREQ([2.68])

# Put autotools auxiliary files in a subdir, so they don't clutter top dir:
AC_CONFIG_AUX_DIR([build-aux])

# The modern autotools convention is that you should use an “m4” subdirectory
# for internal “m4” files, instead of the default aclocal.m4.
AC_CONFIG_MACRO_DIR([m4])

# Enable "automake" to simplify creating makefiles:
AM_INIT_AUTOMAKE([1.11 -Wall -Werror])

# Checks for programs.
AC_PROG_CC
AC_PROG_CC_C_O

PKG_PROG_PKG_CONFIG
# INCFLAGS = `pkg-config --cflags gtk+-3.0`
# LIBS     = `pkg-config --libs gtk+-3.0`
PKG_PROG_PKG_CONFIG
PKG_CHECK_MODULES(GTK, [gtk+-3.0])

AC_SUBST(GTK_CFLAGS)
AC_SUBST(GTK_LIBS)

AC_CONFIG_FILES([
    Makefile
    src/hello/Makefile
])
AC_OUTPUT

AC_MSG_RESULT(
[
-------------------------------------------------
${PACKAGE_NAME} Version ${PACKAGE_VERSION}
Prefix: '${prefix}'.
Compiler: '${CC} ${CFLAGS} ${GTK_CFLAGS}'
Package features:
Async Execution: ${async_exec}
Now type 'make @<:@<target>@:>@'
where the optional <target> is:
all
- build all binaries
install
- install everything
--------------------------------------------------
])
