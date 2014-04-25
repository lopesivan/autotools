# usando autotools

Nosso projeto consiste de uma biblioteca definida em *B1.h* e implementada em
*B1.cpp*.  O programa principal ou seja aquele que utiliza a biblioteca
definida em *B1.h* foi escrito em *A1.cpp*.

arquivos presentes em src:

```bash
A1.cpp
B1.cpp
B1.h
```
Na pasta *src* criamos um makefile descritivo descritivo nomeado como
*Makefile.am* que informa quem é o progarama principal e quem é a biblioteca.

```makefile
lib_LTLIBRARIES=libsimples.la # lib de nome simples
libsimples_la_SOURCES=B1.cpp  # código que implementa a lib de nome simples

include_HEADERS=B1.h          # adição da header que define a lib simples

bin_PROGRAMS=app              # app é o nome do programa compilado
app_SOURCES=A1.cpp            # código que implementa o programa app
app_LDADD=libsimples.la       # biblioteca lincada pelo programa app
```

No raiz do projeto, ou seja um nível acima de *src* criamos um arquivo
makefifile apontador também chamado de *Makefile.am* informando o diretório
que possui o código.

```makefile
SUBDIRS=src
```

Nossa árvore até o momento é essa:

```bash
$ find .
.
./src
./src/A1.cpp
./src/B1.cpp
./src/B1.h
./src/Makefile.am
./Makefile.am
./README.md
```

Rodamos o autoscan para analizar o projeto e gerar um esboço de como devemos
configurar o autotools.

```bash
$ autoscan .
```
O programa *autoscan* gera dois arquivos, um com o log e um segundo chamado
*configure.scan* que é um modelo de como deve ficar o arquivo de configuração
do *autotools*.

```bash
autoscan.log  configure.scan
```
Arquivo *configure.scan*:

```bash
#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.68])
AC_INIT([FULL-PACKAGE-NAME], [VERSION], [BUG-REPORT-ADDRESS])
AC_CONFIG_SRCDIR([src/A1.cpp])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC

# Checks for libraries.

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_CONFIG_FILES([Makefile
                 src/Makefile])
AC_OUTPUT
```

É interessante notar que nosso arquivo possui definições de qual linguagem
estamos usando e onde deve gerar os Makefiles.

Agora, movemos o arquivo *configure.scan* para *configure.ac* midando sua
extensão e adicionamos definições como nome do pacote e verção do programa.

```bash
$ mv configure.scan configure.ac
```

Arquivo *configure.ac*:

```bash
#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.68])
AC_INIT([Exemplo], [1.0], [/dev/null])
AC_CONFIG_SRCDIR([src/A1.cpp])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CXX
AM_INIT_AUTOMAKE($PACKAGE_NAME,$PACKAGE_VERSION)

# Checks for libraries.
LT_INIT

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_CONFIG_FILES([Makefile
                 src/Makefile])
AC_OUTPUT
```

