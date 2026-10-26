.PHONY: all clean

SOURCES := $(wildcard src/*.c)
TARGET := bin/prog

all: $(TARGET)

bin:
	@mkdir -p bin

$(TARGET): $(SOURCES) | bin
	gcc -g -Wall -Iinclude src/*.c -lm -lglut -lGL -o bin/prog

clean:
	rm -rf bin
