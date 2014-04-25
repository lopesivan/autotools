lib_LTLIBRARIES = libtestlib.la
libtestlib_la_HEADERS = testlib.h
libtestlib_la_SOURCES = testlib.c
libtestlib_ladir = $(includedir)

# LDFLAGS documented here:
# http://sourceware.org/autobook/autobook/autobook_88.html
# http://sourceware.org/autobook/autobook/autobook_172.html#SEC172
#libtestlib_la_LDFLAGS = -avoid-version

bin_PROGRAMS = testapp
testapp_SOURCES = testapp.c
testapp_LDADD = libtestlib.la
testappdir = $(includedir)

all-local: Android.mk

Android.mk: Makefile.am
	androgenizer -:PROJECT testlib \
	\
	-:REL_TOP $(top_srcdir) -:ABS_TOP $(abs_top_srcdir) \
	-:SHARED testlib \
	-:SOURCES $(libtestlib_la_SOURCES) \
	-:LDFLAGS $(libtestlib_la_LDFLAGS) \
	\
	-:PROJECT testapp \
	-:REL_TOP $(top_srcdir) -:ABS_TOP $(abs_top_srcdir) \
	-:EXECUTABLE testapp \
	-:LDFLAGS -ltestlib \
	-:SOURCES $(testapp_SOURCES) \
> $@
