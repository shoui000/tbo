BIN_DIR := bin
SRC_DIR := src

.PHONY: clean

all: clean bin/crivo_char bin/crivo_int test_time

$(BIN_DIR): 
	@mkdir -p $(BIN_DIR)

bin/crivo_char: $(BIN_DIR)
	gcc crivo_char.c main.c -o bin/crivo_char -lm

bin/crivo_int: $(BIN_DIR)
	gcc crivo_int.c main.c -o bin/crivo_int -lm

test_time: bin/crivo_char bin/crivo_int
	time bin/crivo_char 10000000
	time bin/crivo_int 10000000 

clean:
	rm -rf bin
