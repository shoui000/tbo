SRCS := $(wildcard src/ms_*.c)
TARGETS := $(patsubst src/ms_%.c, ms_%, $(SRCS))

SIZE ?= 100000000
TEST ?= unif_rand

CFLAGS := -Wall -Wextra -Iinclude

.PHONY: all clean test

all: $(patsubst %, bin/%, $(TARGETS))

$(TARGETS): %: bin/%

bin/%: src/%.c src/main.c src/insertion_sort.c $(wildcard include/*.h)
	@mkdir -p bin
	gcc $^ $(CFLAGS) -o $@

test: bin/$(ARG)
	@bin/$(ARG) $(SIZE) < tests/in/$(TEST)/$(SIZE).txt > /tmp/saida_$(ARG).txt
	@cmp -s /tmp/saida_$(ARG).txt tests/in/sorted/$(SIZE).txt
	@rm -f /tmp/saida_$(ARG).txt

clean:
	rm -rf bin
