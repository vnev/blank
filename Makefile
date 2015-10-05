all:
	clang *.c -Wall -std=c99 -o mangoc

clean:
	rm -f mangoc *.o
