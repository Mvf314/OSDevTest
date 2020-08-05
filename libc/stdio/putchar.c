#include <stdio.h>

#if defined(__is_libk)
#include <src/tty.h>
#endif

int putchar(int c) {
#if defined(__is_libk)
	char chr = (char) c;
	terminal_putchar(chr);
#else

#endif
	return c;
}
