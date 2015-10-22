# We don't want to follow GNU file setup (no README, no AUTHORS, etc)
AUTOMAKE_OPTIONS = foreign

ACLOCAL_AMFLAGS  = -I m4 --install
#
SUBDIRS = \
	source \
	examples/list
#
# = Program =
#
bin_PROGRAMS    = about
include_HEADERS = \
	config.h
about_SOURCES   = \
	about.c

