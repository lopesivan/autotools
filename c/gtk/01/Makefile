sources := exemplo.c
CC = gcc
LD = $(CC)

INCFLAGS = `pkg-config --cflags gtk+-2.0`
LIBS     = `pkg-config --libs gtk+-2.0`
CFLAGS   = -Wall -c
LDFLAGS  = -o
GDBFLAGS = -g

target  := main
targets := $(target)

# Compile
.c.o:
	$(CC) $(GDBFLAGS) $(INCFLAGS) $(CFLAGS) $<

all: $(targets)
main: $(sources:.c=.o)
	$(CC) $(LDFLAGS) $@ $(notdir $^) $(LIBS)

clean:
	/bin/rm -rf $(target) $(notdir $(sources:.c=.o))
# END OF FILE
