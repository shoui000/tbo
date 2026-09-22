#include <stdio.h>

#define MAX 50

int operandos[MAX];
int qtd_operandos = 0;

int calc() {
  // Implemente essa funcao para resolver a questao 1.
  char buffer[16];

	char c;
  while (scanf(" %s", buffer) != EOF) {
    int digito;
    c = 0;

    if (sscanf(buffer, "%d", &digito) == 1) {
      operandos[qtd_operandos++] = digito;
			continue;
    } else if (sscanf(buffer, "%c", &c) == 1) {
			if (c == '*') {
				operandos[qtd_operandos - 2] = operandos[qtd_operandos - 2]  * operandos[qtd_operandos - 1];
			} else {
				operandos[qtd_operandos - 2] = operandos[qtd_operandos - 2]  + operandos[qtd_operandos - 1];
			}

			qtd_operandos--;
    }

  }

  return operandos[0];
}

int main() {
  // Le a entrada e calcula e retorna o resultado.
  int res = calc();
  // Exibe a saida.
  printf("%d\n", res);
}
