# variables
CC=gcc
CFLAGS=-std=c11 -Wall
LDLIBS=#-lm
OUTPUT=k

# targets
all: $(OUTPUT)

$(OUTPUT): ktest.o main.o hof.o
	$(CC) $(CFLAGS) ktest.o main.o hof.o $(LDLIBS) -o $(OUTPUT)

main.o: main.c
	$(CC) $(CFLAGS) -c main.c $(LDLIBS) -o main.o

k.o: ktest.c k.h
	$(CC) $(CFLAGS) -c k.c $(LDLIBS) -o k.o

hof.o: hof.c hof.h
	$(CC) $(CFLAGS) -c hof.c $(LDLIBS) -o hof.o

# remove compiled files
clean: 
	rm -rf $(OUTPUT) *.o