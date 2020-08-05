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

void kernel_main(void) {
	terminal_initialize();
	const char* str = "Hello, kernel!\nNewline test";
	size_t len = strlen(str);
	terminal_write(str, len);
}
