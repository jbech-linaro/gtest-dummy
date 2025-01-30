CC = gcc
CFLAGS = -I../include -Wall -g
SRCS = main.c
OBJS = $(SRCS:.c=.o)

all: libmain.a

libmain.a: $(OBJS)
	ar rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) libmain.a
