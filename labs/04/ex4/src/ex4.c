#include <stdio.h>
#include <stdlib.h>

#define M 100
#define N 18

int str_compare(char *a, char *b) {
  for (int i = 0; i < N; i++) {
    if (a[i] != b[i]) {
      return a[i] > b[i] ? 1 : -1;
    }
  }

  return 0;
}

void exch(char a[N], char b[N]) {
  for (int i = 0; i < N; i++) {
    char t;
    t = a[i];
    a[i] = b[i];
    b[i] = t;
  }
}

void sort(char a[M][N]) {
  // Implemente essa funcao para resolver a questao 4.
  for (int i = 1; i < M-1; i++) {
    for (int j = i + 1; j > 0; j--) {
      if (str_compare(a[j], a[j-1]) < 0) {
        exch(a[j-1], a[j]);
      }
    }
  }
}

int main() {
    char a[M][N];

    // Le a entrada.
    for (int i = 0; i < M; i++) {
        fscanf(stdin,"%s", a[i]);
    }

    // Ordena.
    sort(a);

    // Exibe o resultado.
    for (int i = 0; i < M; i++) {
        printf("%s\n", a[i]);
    }
}
