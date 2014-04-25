#!/usr/bin/env bash

touch NEWS README AUTHORS ChangeLog COPYING
autoreconf -i -v && ./configure && make

exit 0
