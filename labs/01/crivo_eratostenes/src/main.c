#include "crivo.h"

int main(int argc, char const *argv[]) {
  inicia_crivo(atoi(argv[1]));

  executa_crivo();

#ifdef LOG
  imprime_primos();
#endif

  limpa_crivo();
}
