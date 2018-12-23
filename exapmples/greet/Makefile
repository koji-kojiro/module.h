CFLAGS = -I../../
SRCS = $(wildcard ./src/*.c)
OBJS = $(SRCS:.c=.o)
PROG = ./a.out

.phony: all clean

all: $(PROG)
	@$(PROG)

$(PROG): $(OBJS)
	$(CC) $^ $(CFLAGS) -o $@

clean:
	@rm -fv $(PROG) $(OBJS)
