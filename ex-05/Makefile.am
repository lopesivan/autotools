# We don't want to follow GNU file setup (no README, no AUTHORS, etc)
AUTOMAKE_OPTIONS = foreign

ACLOCAL_AMFLAGS  = -I m4 --install
#
SUBDIRS = common/a
#
# = Program =
#
bin_PROGRAMS    = hello

include_HEADERS = \
	config.h

hello_SOURCES   = \
	hello.c

