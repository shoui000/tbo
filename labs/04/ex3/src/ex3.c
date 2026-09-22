#include <stdio.h>
#include <stdlib.h>

#define MAX 100

float cache[MAX] = {-1};
int calculados = 0;

float f_C(int N) {
  // Implemente essa funcao para resolver a questao 3.
  if (N == 0) return 1;

  if (cache[N-1] > 0) return cache[N-1];

  float valor, sum = 0;

  for (int i = 1; i <= N; i++) {
    sum += f_C(i-1) + f_C(N-i);
  }

  valor = N + (1.0/N) * sum;

  cache[N-1] = valor;

  return valor;
}

int main() {
    int N;
    // Le a entrada.
    scanf("%d\n", &N);
    // Calcula e exibe a saida.
    float res = f_C(N);
    printf("%f\n", res);
}
