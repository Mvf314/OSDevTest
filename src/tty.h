#ifndef __KERNEL__
#define __KERNEL__

#include <stdint.h>
#include <stddef.h>

void terminal_setcolor(uint8_t color);
void terminal_putchar(char c);
void terminal_write(const char* data, size_t size);
void terminal_initialize(void);

#endif
