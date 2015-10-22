#!/usr/bin/env sh

autoheader               &&
  aclocal                &&
    autoconf             &&
      mkdir -p build-aux &&
        automake --add-missing && ./configure

exit 0

