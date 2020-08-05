TARGET=i686-elf

CC=$(TARGET)-gcc
AS=$(TARGET)-as

QEMU=qemu-system-i386

CFLAGS=-std=gnu99 -ffreestanding -O2 -Wall -Wextra
LD=-ffreestanding -O2 -Wall -Wextra
LIBS=-nostdlib -lk -lgcc

SRCDIR=src
OBJDIR=obj
BINDIR=bin

SYSROOT=sysroot
PREFIX=usr
INCLUDEDIR=$(PREFIX)/include
LIBDIR=$(PREFIX)/lib

LINKER=$(SRCDIR)/linker.ld
OUTFILE=$(BINDIR)/out.bin

CFLAGS:=$(CFLAGS) -I$(SYSROOT)/$(INCLUDEDIR) -L$(SYSROOT)/$(LIBDIR)
LDFLAGS=$(CFLAGS)

CRTI_OBJ=$(OBJDIR)/crti.o
CRTBEGIN_OBJ=$(shell $(CC) $(CFLAGS) -print-file-name=crtbegin.o)
CRTEND_OBJ=$(shell $(CC) $(CFLAGS) -print-file-name=crtend.o)
CRTN_OBJ=$(OBJDIR)/crtn.o

KERNEL_OBJS=\
$(OBJDIR)/boot.o	\
$(OBJDIR)/tty.o		\
$(OBJDIR)/kernel.o

LINK_OBJS=\
$(CRTI_OBJ) $(CRTBEGIN_OBJ) \
$(KERNEL_OBJS) \
$(CRTEND_OBJ) $(CRTN_OBJ)

LINK_LIST=\
$(LDFLAGS)	\
$(CRTI_OBJ) $(CRTBEGIN_OBJ) \
$(KERNEL_OBJS) 	\
$(LIBS)		\
$(CRTEND_OBJ) $(CRTN_OBJ)

all: $(OUTFILE)

test: $(OUTFILE)
	$(QEMU) -curses -kernel $<

$(OUTFILE): $(LINK_OBJS)
	$(CC) -T $(LINKER) -o $@ $(LINK_LIST)
	@if grub-file --is-x86-multiboot $@; then echo Multiboot compatible; else echo Not Multiboot compatible; fi;

$(OBJDIR)/%.o: $(SRCDIR)/%.s
	$(AS) $< -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) -c -I$(SRCDIR) $< -o $@ $(CFLAGS)
	
clean:
	$(RM) $(CRTI_OBJ) $(CRTN_OBJ)
	$(RM) $(KERNEL_OBJS)
	$(RM) $(OUTFILE)

install: install-headers install-libs

install-headers:
	mkdir -p $(SYSROOT)/
