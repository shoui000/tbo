CFLAGS := -O3 $(DEF)
BIN_DIR := bin
SRC_DIR := src
PROGRAMAS := crivo_char crivo_int crivo_bit
N_TESTE := 10000000
SAIDA_TIME := resultados_tempo.txt

EXECS := $(addprefix $(BIN_DIR)/, $(PROGRAMAS))

.PHONY: clean all test_time $(PROGRAMAS)

all: clean $(EXECS) test_time

$(PROGRAMAS): %: $(BIN_DIR)/%

$(BIN_DIR): 
	@mkdir -p $(BIN_DIR)

$(BIN_DIR)/%: $(SRC_DIR)/%.c $(SRC_DIR)/main.c | $(BIN_DIR)
	gcc $(CFLAGS) $^ -o $@ -lm

test_time: $(EXECS)
	@echo "Iniciando testes de tempo (Entrada = $(N_TESTE))..."
	@echo "=== Resultados dos Testes ===" > $(SAIDA_TIME)
	@echo "Tamanho da entrada: $(N_TESTE)\n" >> $(SAIDA_TIME)
	@for prog in $(EXECS); do \
		echo "----------------------------------------" >> $(SAIDA_TIME); \
		echo "Testando: $$prog" >> $(SAIDA_TIME); \
		echo "----------------------------------------" >> $(SAIDA_TIME); \
		{ time $$prog $(N_TESTE); } >> $(SAIDA_TIME) 2>&1; \
		done
	@echo "Testes concluídos! Confira o arquivo: $(SAIDA_TIME)"

clean:
	rm -rf $(BIN_DIR) $(SAIDA_TIME)
