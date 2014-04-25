#include <stdio.h>
#include <stdlib.h>
#include <testlib.h>

int main(char *argc[], int argv)
{
	char *buf = malloc(1024);
	printf("%s", sayhello(buf, 1024, "world"));
}
