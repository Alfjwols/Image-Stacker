CC = g++
TARGET = stacker
CFLAGS = -Wall -Wextra -c

all: $(TARGET)

$(TARGET): Stacker.o Pixel.o main.o
	$(CC) Stacker.o Pixel.o main.o -o $(TARGET)

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp -o main.o

Stacker.o: Stacker.cpp Stacker.h Pixel.o
	$(CC) $(CFLAGS) Stacker.cpp -o Stacker.o

Pixel.o: Pixel.cpp Pixel.h
	$(CC) $(CFLAGS) Pixel.cpp -o Pixel.o

clean:
	rm -f Pixel.o Stacker.o main.o $(TARGET)
