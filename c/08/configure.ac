AC_PREREQ([2.69])
AC_INIT([hello], [3.0.1], [seuemail@example.com])

AM_INIT_AUTOMAKE([-Wall -Werror foreign])

# Verificações para compiladores e ferramentas
AC_PROG_CC


AC_CONFIG_SRCDIR([src/main.c])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_HEADERS([config.h])

# Verificar GTK+
PKG_CHECK_MODULES([GTK], [gtk+-3.0])

# Onde colocar os arquivos gerados
AC_CONFIG_FILES([Makefile
                 src/Makefile ])

AC_OUTPUT

