#include "crivo.h"

int main(int argc, char const *argv[]) {
    inicia_crivo(atoi(argv[1]));

    executa_crivo();

    // imprime_primos();

    limpa_crivo();
}