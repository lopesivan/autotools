# "testlib" is the name used as "PROJECT" in the androgenizer line
# in Makefile.am. It creates a "LOCAL_MODULE:=testlib" in Android.mk, which is
# the one referenced here

# Actually this is not needed. If APP_MODULES doesn't appear or if there's no
# Application.mk files, all the modules defined in Android.mk are built

# APP_MODULES := testlib testapp

