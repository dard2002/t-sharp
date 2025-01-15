SRCS = tsharp.c $(wildcard src/*.c)
OBJS = $(SRCS:.c=.o)
CFLAGS = -g -Iinclude

tsharp: $(OBJS)
	clang $(CFLAGS) -o $@ $(OBJS)

clean:
	rm -f $(OBJS) tsharp