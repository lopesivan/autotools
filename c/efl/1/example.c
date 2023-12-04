//cc example.c -o example `pkg-config --cflags --libs elementary`
// export PKG_CONFIG_PATH=/usr/local/lib/pkgconfig:$PKG_CONFIG_PATH
//
#include <Elementary.h>

EAPI_MAIN int
elm_main (int argc, char **argv)
{
    elm_run();
    return 0;
}
ELM_MAIN()
