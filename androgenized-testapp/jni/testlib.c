#include <testlib.h>
#include <stdlib.h>
#include <string.h>

char *sayhello(char *buf, size_t buflen, const char *name)
{
	snprintf(buf, buflen, "Hello %s!\n", name);
	return buf;
}
