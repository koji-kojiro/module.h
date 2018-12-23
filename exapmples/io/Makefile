CFLAGS = -I../../
SRCS = $(wildcard ./src/*.c)
OBJS = $(SRCS:.c=.o)
LIB = ./libio.so
PROG = ./a.out

.phony: all clean

all: $(PROG)
	@$(PROG)

$(LIB): $(OBJS)
	$(CC) $^ $(CFLAGS) -o $@ -shared

$(PROG): main.c $(LIB)
	$(CC) -o $(PROG) $(CFLAGS) main.c $(LIB)

clean:
	@rm -fv $(PROG) $(LIB) $(OBJS)
