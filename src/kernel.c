#if defined(__linux__)
#error "Please use a cross-compiler"
#endif

#if !defined (__i386__)
#error "ix86-elf compiler is necessary!"
#endif

#include <string.h>

#include <tty.h>

void write(const char* str) {
	terminal_write(str, strlen(str));
}

void kernel_main(void) {
	terminal_initialize();
	for (size_t i = 0; i < 25; i++) {
		write("Line ");
		terminal_putchar((char) ((i % 10) + 48));
		write("!\n");
	}
}
