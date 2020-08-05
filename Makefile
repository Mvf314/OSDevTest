TARGET = i686-elf

CC = $(TARGET)-gcc
AS = $(TARGET)-as

QEMU = qemu-system-i386

CFLAGS = -std=gnu99 -ffreestanding -O2 -Wall -Wextra

SRCDIR = src
OBJDIR = obj
BINDIR = bin

LINKER = $(SRCDIR)/linker.ld
OUTFILE = $(BINDIR)/out.bin

KERNEL_OBJS =\
$(OBJDIR)/boot.o	\
$(OBJDIR)/tty.o		\
$(OBJDIR)/kernel.o

all: $(OUTFILE)

test: $(OUTFILE)
	$(QEMU) -curses -kernel $<

$(OUTFILE): $(KERNEL_OBJS)
	$(CC) -T $(LINKER) -o $@ -ffreestanding -O2 -nostdlib $(KERNEL_OBJS) -lgcc
	@if grub-file --is-x86-multiboot $@; then echo Multiboot compatible; else echo Not Multiboot compatible; fi;

$(OBJDIR)/%.o: $(SRCDIR)/%.s
	$(AS) $< -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) -c -I$(SRCDIR) $< -o $@ $(CFLAGS)
	
clean:
	$(RM) $(KERNEL_OBJS) $(OUTFILE)
