BIN_DIR := bin
SRC_DIR := src

TARGET := $(BIN_DIR)/ex1

all: $(TARGET) test

$(BIN_DIR): 
	@mkdir $(BIN_DIR)

$(TARGET): $(BIN_DIR) $(SRC_DIR)/*.c
	gcc -Wall -o $(TARGET) $(SRC_DIR)/*.c

test: $(TARGET)
	$(TARGET) < in | diff out -

clean:
	rm -rf $(BIN_DIR)

