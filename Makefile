PROGRAM = molekuli
CC      = gcc
CFLAGS  = -Wall
LDLIBS  = -lglut -lGLU -lGL

$(PROGRAM): main.o
	$(CC) $(CFLAGS) -o $(PROGRAM) main.o $(LDLIBS)

.PHONY: clean

clean:
	-rm -f *.o $(PROGRAM) *~
