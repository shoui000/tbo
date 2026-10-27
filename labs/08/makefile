SOURCES := $(wildcard src/*.c)
CFLAGS := -Wall -Iinclude
TARGET := bin/prog

.PHONY: clean abra tale moby

all: $(TARGET)

bin:
	@mkdir -p bin

$(TARGET): bin $(SOURCES)
	gcc $(CFLAGS) $(SOURCES) -o $(TARGET)

abra: $(TARGET)
	$(TARGET) tests/in/abra.txt

tale: $(TARGET)
	$(TARGET) tests/in/tale.txt

moby: $(TARGET)
	$(TARGET) tests/in/moby.txt

clean:
	rm -rf bin
