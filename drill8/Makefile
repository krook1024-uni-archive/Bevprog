CC=g++
CFLAGS=-I
DEPS = my.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

make: my.o use.o
	$(CC) -o use my.o use.o

.PHONY: clean

clean:
	rm -f ./*.o 
