CC = gcc
CFLAGS = -std=c11 -pedantic-errors -Wall -Werror -Wextra -Wconversion -Wstrict-prototypes
TARGETS = encrypter decrypter
SOURCES = q.c qdriver.c
OBJECTS = q.o qdriver.o

all: $(TARGETS)

encrypter: q.o qdriver.o
	$(CC) q.o qdriver.o -o encrypter

decrypter: q.o qdriver.o
	$(CC) q.o qdriver.o -o decrypter

q.o: q.c
	$(CC) $(CFLAGS) -c q.c -o q.o

qdriver.o: qdriver.c
	$(CC) $(CFLAGS) -DENCRYPT -c qdriver.c -o qdriver.o

clean:
	rm -f $(TARGETS) $(OBJECTS) actual-output.txt

.PHONY: all clean
