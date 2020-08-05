#if defined(__linux__)
#error "Please use a cross-compiler"
#endif

#if !defined (__i386__)
#error "ix86-elf compiler is necessary!"
#endif

#include <tty.h>

size_t strlen(const char* str) {
	size_t len = 0;
	while (str[len])
		len++;
	return len;
}

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
