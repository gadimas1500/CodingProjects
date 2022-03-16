CC = clang

# Make sure to use the full CFLAGS before turning in. Uncomment this for lax
# checking during development, if you need to.
# CFLAGS =

# You can comment this out and use the above CFLAGS instead if you need to,
# during development.
#CFLAGS = -Wall -Wpedantic -Werror -Wextra


all: main

main: main.o inf_to_pos.o
	$(CC) inf_to_pos.o main.o -o inftopos

inf_to_pos.o: inf_to_pos.c inf_to_pos.h
	$(CC) $(CFLAGS) -c inf_to_pos.c

main.o: main.c inf_to_pos.h
	$(CC) $(CFLAGS) -c main.c


clean:
	rm -f inftopos inf_to_pos.o inf_to_pos.o

format:
	clang-format -i -style=file *.{c,h}
