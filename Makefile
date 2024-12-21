SRCS = t-sharp.c token/token.c node/node.c
OBJS = $(SRCS:.c=.o)

t-sharp: $(OBJS)
	clang -o $@ $(OBJS)