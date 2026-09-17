#include "crivo.h"

static unsigned char *vetor;
static int qtdBits;
static int qtdBytesAlocado;

void inicia_crivo(int tamanho) {
    qtdBits = tamanho;

    float tamanho_alocado = tamanho / 8.0;

    if (tamanho_alocado > tamanho / 8) { tamanho_alocado++; }

    qtdBytesAlocado = (int)tamanho_alocado;

    vetor = calloc(qtdBytesAlocado, sizeof(unsigned char));
}

// TODO
void executa_crivo() {
    int fator = 2;
    int limite = sqrt(qtdBits);
    // considera 2 como indice 0

    while (fator <= limite) {
        for (int i = 2 * fator - 2; i < qtdBits / 8; i += fator)
        {
            vetor[i/8] ^= 1 << i % 8;
        }

        for (int i = fator - 1; i < qtdBits / 8; i++)
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
    for (int i = 0; i < qtdBytesAlocado; i++) {
        for (int j = 0; j < 8; j++) {
            if (!(vetor[i] & 1 << j)) {
                printf("%d ", (i * 8) + j + 2);
            }
        }
    }

    putchar('\n');
}

void limpa_crivo() {
    free(vetor);
}
