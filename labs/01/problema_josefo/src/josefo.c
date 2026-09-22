#include "josefo.h"
#include <stdlib.h>

static int *pessoas;
static int passo;
static int qtd_pessoas;

void inicia_josefo(int n, int m) {
	passo = m;
	qtd_pessoas = n;
	pessoas = malloc(n * sizeof(int));
}

void executa_josefo() {
	int pessoas_eliminadas = 0, i = 1, j = 0;
	while (pessoas_eliminadas < qtd_pessoas-1) {
		i = 1;
		
		while (i <= passo) {
			if (pessoas[j]) {
				j = (j + 1) % qtd_pessoas;
				continue;
			}

			if (i == passo) {
				pessoas[j] = ++pessoas_eliminadas;
				j = (j + 1) % qtd_pessoas;
				break;
			}

			i++;
		}
	}
}

void imprime_ordem() {
	for (int i = 0; i < qtd_pessoas; i++) {

		for (int j = 0; j < qtd_pessoas; j++) {
		}
	}
}

void limpa_josefo() {
	passo = qtd_pessoas = 0;
	free(pessoas);
	pessoas = NULL;
}
