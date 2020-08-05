TARGET=i686-elf

CC=$(TARGET)-gcc
AR=$(TARGET)-ar

CFLAGS=-std=gnu11 -O2 -g -ffreestanding -Wall -Wextra -Iinclude

LIBK_CFLAGS=$(CFLAGS) -I.. -D__is_libk

SYSROOT=../sysroot
PREFIX=usr
INCLUDEDIR=$(PREFIX)/include
LIBDIR=$(PREFIX)/lib

BINS=libk.a

FREE_OBJS=\
math/iabs.o		\
math/ipow.o		\
stdio/putchar.o		\
stdio/printf.o		\
stdlib/abort.o		\
stdlib/atoi.o		\
string/strlen.o		

LIBK_OBJS=$(FREE_OBJS:.o=.libk.o)

all: $(BINS)

libk.a: $(LIBK_OBJS)
	$(AR) rcs $@ $(LIBK_OBJS)

%.libk.o: %.c
	$(CC) -c $< -o $@ $(LIBK_CFLAGS)

clean:
	$(RM) $(BINS)
	$(RM) $(FREE_OBJS)
	$(RM) $(LIBK_OBJS)

install: install-headers install-libs

install-headers:
	mkdir -p $(SYSROOT)/$(INCLUDEDIR)
	cp -R --preserve=timestamps include/. $(SYSROOT)/$(INCLUDEDIR)

install-libs: $(BINS)
	mkdir -p $(SYSROOT)/$(LIBDIR)
	cp $(BINS) $(SYSROOT)/$(LIBDIR)
