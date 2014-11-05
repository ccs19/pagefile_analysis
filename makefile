CC = gcc
CFLAGS = -g -Wall
OBJECTS = *.c
NAME = matrix
TODELETE = $(NAME) *.o

$NAME : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

.PHONY: clean
clean:
	rm -f $(TODELETE)
