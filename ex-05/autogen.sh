#!/usr/bin/env sh

autoheader               &&
  aclocal                &&
    autoconf             &&
      mkdir -p build-aux &&
        automake --add-missing

exit 0

