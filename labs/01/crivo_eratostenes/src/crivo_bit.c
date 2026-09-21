#include "crivo.h"

static unsigned char *vetor;
static int qtdBits;
static int qtdBytesAlocado;

void inicia_crivo(int tamanho) {
	qtdBits = tamanho;

	qtdBytesAlocado = ceilf(tamanho / 8.0);

	vetor = calloc(qtdBytesAlocado, sizeof(unsigned char));
}

void executa_crivo() {
	int fator = 2;
	int limite = sqrt(qtdBits);
	// considera 2 como indice 0

	while (fator <= limite) {
		for (int i = 2 * fator - 2; i < qtdBits; i += fator)
		{
			vetor[i/8] |= 1 << (i % 8);
		}


		for (int i = fator - 1; i < qtdBits; i++)
		{
			if (!(vetor[i/8] & (1 << (i % 8))))
			{
				fator = i + 2;
				break;
			}
		}
	}

}

void imprime_primos() {
	for (int i = 0; i < qtdBits; i++) {
		if (!(vetor[i/8] & (1 << (i % 8)))) {
			printf("%d ", i + 2);
		}
	}

	putchar('\n');
}

void limpa_crivo() {
	free(vetor);
}
