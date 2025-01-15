SRCS = t-sharp.c $(wildcard src/*.c)
OBJS = $(SRCS:.c=.o)
CFLAGS = -g -Iinclude

t-sharp: $(OBJS)
	clang $(CFLAGS) -o $@ $(OBJS)

clean:
	rm -f $(OBJS) t-sharp