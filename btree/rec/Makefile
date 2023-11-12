CC=gcc
CFLAGS=-Wall -std=c11 -pedantic -lm -g #-fsanitize=address
FILES_NOMAIN=btree.c ../btree.c ../test_util.c
FILES=$(FILES_NOMAIN) ../test.c

.PHONY: test clean

test: $(FILES)
	$(CC) $(CFLAGS) -o $@ $(FILES)

test_muj: test_muj.c $(FILES_NOMAIN)
	$(CC) $(CFLAGS) -o $@ $^

run: test_muj
	./test_muj

clean:
	rm -f test test_muj
