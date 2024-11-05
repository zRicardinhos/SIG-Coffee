CC = gcc
CFLAGS = -Wall -g

SOURCES = $(shell find . -name "*.c")
OBJECTS = $(SOURCES:.c=.o)

TARGET = sig-coffee

all: $(TARGET) clean-objects

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean-objects:
	rm -f $(OBJECTS)

clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: all clean clean-objects
