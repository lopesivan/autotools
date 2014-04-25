#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.68])

# AC_INIT(package, version, [bug-report], [tarname], [url])
AC_INIT([Taylor_series],
        [1.0],
        [code.bug@unite.com.br],
        [taylor-maple],
        [math.unite.com.br])

AC_CONFIG_HEADERS([config.h])

# Checks for programs.
# Checks for programs.
AC_PROG_CC
AC_PROG_CXX
AC_PROG_CPP

AM_INIT_AUTOMAKE($PACKAGE_NAME,$PACKAGE_VERSION)

# Checks for libraries.
LT_INIT

dnl Criando função
# AC_DEFINE_SUBST(NAME, VALUE, DESCRIPTION)
# -----------------------------------------
AC_DEFUN([AC_DEFINE_SUBST], [
AC_DEFINE([$1], [$2], [$3])
AC_SUBST([$1], ['$2'])
])

AC_DEFINE_SUBST(CONF_XDISP, "Here...", X screen number)
AC_DEFINE_SUBST(III, "JJJJJHere...", screen number)
AC_DEFINE_SUBST(UNITE_MODE, "red mode on", modo vermelho ativo)

# AC_CHECK_PROG( [variable],
#     [prog-to-check-for],
#     [value-if-found],
#     [value-if-not-found],
#     [path],
#     [reject])

AC_CHECK_PROG([HAS_TP],
              [tp],
              [eu encopntrei o programa tp],
              [eu nao encopntrei o programa tp],
              [],
              [])

# AC_SEARCH_LIBS([function],
#                [search-libs],
#                [action-if-found],
#                [action-if-not-found],
#                [other-libraries])

#AC_SEARCH_LIBS([pthread_create], [pthread])
# Checks for libraries.
AC_CHECK_LIB(readline,
             readline)

# Checks for header files.
AC_CHECK_HEADERS(readline/history.h readline/readline.h)
#if HAVE_READLINE_HISTORY_H
#if HAVE_READLINE_READLINE_H
#endif

dnl Crio uma variável no config.h de nome `ABCD' e seto como 1.
AC_DEFINE(ABCD, [1], [Essa variável aparece no config.h])

dnl Criando comando
AC_CONFIG_COMMANDS([abc],
                   [echo \
"esse comando é rodado no final do ./configure, e a variável definida dentro
dele é $mypkgname, é bom lembrar que os comandos são separados por ;(ponto e
vírgula)."; echo "chamando outro comando shell"; pwd],
                 [mypkgname=$PACKAGE_NAME])

# Checks for libraries.
AC_SEARCH_LIBS([pthread_create],
               [pthread],
         [have_pthreads=yes],
         [have_pthreads=no])

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h])

if test "x${have_pthreads}" = xyes; then
  AC_CHECK_HEADERS([pthread.h], [], [have_pthreads=no])
fi

if test "x${have_pthreads}" = xno; then
  AC_MSG_ERROR([
------------------------------------------
UUUnable to find pthreads on this system.
Building a single-threaded version.
------------------------------------------])
fi

if test "x${have_pthreads}" = xyes; then
  AC_MSG_WARN([
------------------------------------------
Unable to find pthreads on this system.
Building a single-threaded version.
------------------------------------------])
fi

# AC_MSG_CHECKING(feature-description)
# AC_MSG_RESULT(result-description)
# AC_MSG_NOTICE(message)
# AC_MSG_ERROR(error-description[, exit-status])
# AC_MSG_FAILURE(error-description[, exit-status])
# AC_MSG_WARN(problem-description)

### begin: pkg-config
PKG_PROG_PKG_CONFIG
PKG_CHECK_MODULES(FFMPEG, libavformat libavcodec libavutil)

AC_SUBST(FFMPEG_CFLAGS)
AC_SUBST(FFMPEG_LIBS)
#### end: pkg-config

### begin: pkg-config
PKG_PROG_PKG_CONFIG
PKG_CHECK_MODULES(XXX, QtDBus libpostproc)

AC_SUBST(XXX_CFLAGS)
AC_SUBST(XXX_LIBS)
#### end: pkg-config

AC_PROG_LN_S    # faz LN_S="ln -s"
AC_PROG_SED     # faz SED=/bin/sed
AC_PROG_MKDIR_P # faz MKDIR_P="mkdir -p"

dnl Verifico se o programa existe no PATH, se existe carrego a variável de
dnl mesmo nome mas em maiúscula com o nome do programa

AC_PATH_PROG(LATEX,     latex,     "")
AC_PATH_PROG(PDFLATEX,  pdflatex,  "")
AC_PATH_PROG(PS2PDF,    ps2pdf,    "")
AC_PATH_PROG(MAKEINDEX, makeindex, "")
AC_PATH_PROG(DVIPS,     dvips,     "")

dnl se as variáveia abaixo não forem vazias eu crio a variável
dnl `CONFIG_TEX' do Makefile.am.
AM_CONDITIONAL(CONFIG_TEX, [
  test ! \( -z "$LATEX"     -o \
              -z "$MAKEINDEX" -o \
              -z "$PDFLATEX"  -o \
              -z "$DVIPS" \)])

AS_IF([test -z "$LATEX"    -o \
            -z "$PDFLATEX" -o \
      -z "$DVIPS"    -o \
      -z "$PS2PDF"],
    [AC_MSG_WARN([Some documentation formats may not build, because latex/pdflatex/dvips is missing.])])

AC_ARG_VAR([JAVA_HOME],
           [Path to the root of the Java environment])

# Checks for command-line options
AC_ARG_ENABLE([async-exec],
  AS_HELP_STRING([--disable-async-exec], [Disable async execution feature]),
  [async_exec=${enableval}],
  [async_exec=yes])

if test "x${async_exec}" = xyes; then
  AC_DEFINE([ASYNC_EXEC], 1, [async execution enabled])
fi

AC_MSG_RESULT(
[
-------------------------------------------------
${PACKAGE_NAME} Version ${PACKAGE_VERSION}
Prefix: '${prefix}'.
Compiler: '${CC} ${CFLAGS} ${CPPFLAGS}'
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

AC_CONFIG_FILES([Makefile
                 maple/Makefile
                 maple/exemplo01/Makefile])
AC_OUTPUT

