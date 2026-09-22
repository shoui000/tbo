#include <stdio.h>
#include <stdlib.h>

// 1 2 4 5 3 6
// 4 2 5 1 3 6
//
//     1
//   2    3
// 4  5     6
// 
// 4 5 2 6 3 1

void print_post_order(int *pre, int *in, int N) {
  // Implemente essa funcao para resolver a questao 2.
  
  if (N == 0) { return; }

  if (N == 1) {
    printf("%d ", pre[0]);
    return;
  }

  int raiz = pre[0], in_raiz_pos;

  for (int i = 0; i < N; i++) {
    if (in[i] == raiz) {
      in_raiz_pos = i;
      break;
    }
  }

  print_post_order(pre + 1, in, in_raiz_pos); // subarvore da esquerda

  print_post_order(pre + in_raiz_pos + 1, in + in_raiz_pos + 1, N - (in_raiz_pos + 1)); // subarvore da direita;

  printf("%d ", raiz);
}

int main() {
    // Le a entrada.
    int N;
    scanf("%d\n", &N);
    int *pre = malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &pre[i]);
    }
    int *in = malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &in[i]);
    }

    // Calcula e exibe a saida.
    print_post_order(pre, in, N);
    printf("\n");
    free(pre);
    free(in);
}
