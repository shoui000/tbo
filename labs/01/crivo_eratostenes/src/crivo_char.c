#include "crivo.h"

static char *vetor;
static int tamanho_crivo;

void inicia_crivo(int tamanho) {
	tamanho_crivo = tamanho;
	vetor = calloc(tamanho, sizeof(char));
}

void executa_crivo() {
	int fator = 2;
	int limite = sqrt(tamanho_crivo);
	// considera 2 como indice 0

	while (fator <= limite) {
		for (int i = 2 * fator - 2; i < tamanho_crivo; i += fator)
		{
			vetor[i] = 1;
		}

		for (int i = fator - 1; i < tamanho_crivo; i++)
		{
			if (!vetor[i])
			{
				fator = i + 2;
				break;
			}
		}
	}

}

void imprime_primos() {
	for (int i = 0; i < tamanho_crivo; i++) {
		if (!vetor[i]) {
			printf("%d ", i+2);
		}
	}

	putchar('\n');
}

void limpa_crivo() {
	free(vetor);
}
