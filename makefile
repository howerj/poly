CFLAGS=-O3 -std=c99 -Wall -Wextra

.PHONY: all default run clean

all default run: poly.txt

poly.txt: poly
	./poly > poly.txt

clean:
	git clean -dffx
