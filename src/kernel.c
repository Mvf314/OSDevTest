#if defined(__linux__)
#error "Please use a cross-compiler"
#endif

#if !defined (__i386__)
#error "ix86-elf compiler is necessary!"
#endif

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <assert.h>

#include <tty.h>

void write(const char* str) {
	terminal_write(str, strlen(str));
}

void kernel_main(void) {
	terminal_initialize();

	short int temp = 25 * 32;

	printf("Yo, shit shows 25 * 32: %h\nCool, isnt it?", temp);
}
