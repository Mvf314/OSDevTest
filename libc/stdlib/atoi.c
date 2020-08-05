#include <stdlib.h>

#include <string.h>
#include <math.h>

int atoi(const char* str) {
	size_t len = strlen(str);
	int sign = 0;
	int start = 0;
	int end = 0;
	// Determine sign and start
	for (size_t i = 0; i < len; i++) {
		if (sign == 0) {
			switch (str[i]) {
				case '-': 
					sign = -1;
					start = i + 1;
					break;
				case '0':
				case '1':
				case '2':
				case '3':
				case '4':
				case '5':
				case '6':
				case '7':
				case '8':
				case '9':
					sign = 1;
					start = i;
					break;
				case '+':
					sign = 1;
					start = i + 1;
					break;
				default:
					break;
			}
		}
	}
	if (sign == 0) {
		// No number found!
		return 0;
	}
	for (size_t i = start; i < len; i++) {
		switch (str[i]) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				break;
			default:
				end = i;
				break;
		}
	}
	if (end == 0) {
		end = len;
	}
	int final = 0;
	for (size_t i = start; i < (size_t) end; i++) {
		final += ipow(10, end - i - 1) * (int) (str[i] - 0x30);
	}
	return final;
}
