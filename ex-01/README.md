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

Na pasta do projeto, ou seja um nível acima de *src* criamos um arquivo
makefifile apontador também chamado de *Makefile.am* informando o diretório
que possui o código.

```makefile
SUBDIRS=src
```

Nossa árvore até o momento é essa:

```bash
find .
.
./src
./src/A1.cpp
./src/B1.cpp
./src/B1.h
./src/Makefile.am
./Makefile.am
./README.md
```

Rode o autoscan para analizar o projeto.

```bash
$ autoscan
```

