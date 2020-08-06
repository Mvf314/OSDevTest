#include <stdio.h>

#include <stdarg.h>

#include <string.h>
#include <math.h>

const char* itostr(int i) {
	char* str = "sthts";
	// TODO actually implement this, lol
	if (i > 0) {
		str[0] = '+';
	} else {
		str[0] = '-';
	}
	if (iabs(i) < 10000) {
		i = iabs(i);
		int thou = 0;
		int hund = 0;
		int tens = 0;
		int sngl = 0;
		thou = i / 1000;
		hund = (i - (thou * 1000)) / 100;
		tens = (i - (thou * 1000) - (hund * 100)) / 10;
		sngl = (i - (thou * 1000) - (hund * 100) - (tens * 10));
		str[1] = (char) (thou + 48);
		str[2] = (char) (hund + 48);
		str[3] = (char) (tens + 48);
		str[4] = (char) (sngl + 48);
		return str;
	} else {
		return "Bigno";
	}
}

int printf(const char* restrict format, ...) {
	va_list params;
	va_start(params, format);
	int written = 0;
	size_t length = strlen(format);
	
	for (size_t i = 0; i < length; i++) {
		if (format[i] == '%') {
			if (i + 1 >= length) {
				putchar('%');
				written++;
			} else {
			int intg;
			const char* str;
				switch (format[i + 1]) {
					case 'h':
						intg = (int) va_arg(params, int);
						written += printf(itostr(intg));
						i++;
						break;
					case 's':
						str = (const char*) va_arg(params, const char*);
						written += printf(str);
						i++;
						break;
					default:
						putchar('%');
						written++;
						break;
				}
			}
		} else {
			putchar(format[i]);
			written++;
		}
	}
	va_end(params);
	return written;
}
