/* See https://github.com/howerj/poly, 0BSD license, howe.r.j.89@gmail.com */
#include <stdint.h>
#include <stdio.h>

static inline unsigned lfsr(unsigned n, unsigned polynomial_mask) {
	const int feedback = n & 1;
	n >>= 1;
	return feedback ? n ^ polynomial_mask : n;
}

static inline int popcnt(unsigned x) {
	int r = 0;
	while (x) {
		r += x & 1;
		x >>= 1;
	}
	return r;
}

static inline int highbit(unsigned x) {
	int r = 0;
	while (x) {
		r++;
		x >>= 1;
	}
	return r;
}

int main(void) {
	for (int i = 1; i < 65536; i++) {
		unsigned hi = highbit(i);
		if (printf("poly: %04X highbit: %2u popcnt: %2d ", i, hi, popcnt(i)) < 0) return 1;
		int j = 1;
		unsigned s = 1;
		for (j = 1; j < (1 << (hi + 1)); j++) {
			s = lfsr(s, i);
			if (s == 1)
				break;
		}
		if (printf("period: %d\n", j) < 0) return 1;
	}
	return 0;
}
