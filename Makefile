CC = gcc
CFLAGS = -Wall -Og -g
LIBS = -lm


SRCS = 

OBJS = $(SRCS:.c=.o)


main: main.o $(OBJS) 
	$(CC) $(CFLAGS) $^ -o $(<:.o=.out) $(LIBS)


.PHONY: clean

clean:
	rm -f $(OBJS)


%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@ $(LIBS)
