CC = clang

# Make sure to use the full CFLAGS before turning in. Uncomment this for lax
# checking during development, if you need to.
# CFLAGS =

# You can comment this out and use the above CFLAGS instead if you need to,
# during development.
#CFLAGS = -Wall -Wpedantic -Werror -Wextra


all: hw7

hw7: hw7.o businessdb.o
	$(CC) businessdb.o hw7.o -o businessdb

businessdb.o: businessdb.c businessdb_header.h
	$(CC) $(CFLAGS) -c businessdb.c

hw7.o: hw7.c businessdb_header.h
	$(CC) $(CFLAGS) -c hw7.c


clean:
	rm -f businessdb hw7.o businessdb.o

format:
	clang-format -i -style=file *.{c,h}
