#include <math.h>

#include <stddef.h>

int ipow(int b, int e) {
	// TODO addd more checks
	int temp = b;
	for (size_t i = 0; i < (size_t) e; i++) {
		temp *= b;
	}
	return temp;
}
