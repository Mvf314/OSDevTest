#include <stdlib.h>

#include <stdio.h>

_Noreturn void abort(void) {
#if defined(__is_libk)
	printf("kernel panic: abort() called\n");
#else
	printf("abort() called\n");
#endif
	while(1) {}
}
