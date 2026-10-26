SRCS := $(wildcard src/ms_*.c)
TARGETS := $(patsubst src/qs_%.c, ms_%, $(SRCS))

SIZE ?= 100000000
TEST ?= unif_rand

CFLAGS := -O3 -Wall -Wextra -Iinclude

ifeq ($(TEST),few_uniq)
    SIZE := 10000000
    IN_FILE := tests/in/few_uniq/10M_const_keys_unif_rand.txt
    EXPECTED_FILE := tests/in/few_uniq/10M_const_keys_sorted.txt
else
    IN_FILE := tests/in/$(TEST)/$(SIZE).txt
    EXPECTED_FILE := tests/in/sorted/$(SIZE).txt
endif

.PHONY: all clean test

all: $(patsubst %, bin/%, $(TARGETS))

$(TARGETS): %: bin/%

bin/%: src/%.c src/shuffle.c src/main.c src/insertion_sort.c $(wildcard include/*.h)
	@mkdir -p bin
	gcc $^ $(CFLAGS) -o $@

test: bin/$(ARG)
	@bin/$(ARG) $(SIZE) < $(IN_FILE) > /tmp/saida_$(ARG).txt
	@cmp -s /tmp/saida_$(ARG).txt $(EXPECTED_FILE) && echo "Saida correta" || echo "Saida incorreta"
	@rm -f /tmp/saida_$(ARG).txt

clean:
	rm -rf bin
