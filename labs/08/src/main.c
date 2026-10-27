#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "string.h"
#include "suffix.h"

#define CONTEXT 10

int main(int argc, char **argv) {
  if (argc < 2) {
    perror("[erro] não foi passado o caminho para o arquivo de entrada");
    exit(EXIT_FAILURE);
  }

  FILE *in = fopen(argv[1], "r");

  if (in == NULL) {
    perror("[erro] ocorreu um erro ao abrir o arquivo de entrada");
    exit(EXIT_FAILURE);
  }

  long char_count;
  fscanf(in, "%ld", &char_count);

  char *buffer = malloc((char_count + 1) * sizeof(char));
  long buffer_size = 0;
  char b;
  bool espaco = true;

  while((b = fgetc(in)) != EOF && buffer_size < char_count) {
    if (b == '\n' || b == ' ') {

      if (espaco) continue;

      buffer[buffer_size++] = ' ';
      espaco = true;

      continue;
    }

    espaco = false;
    buffer[buffer_size++] = b;
  }

  buffer[buffer_size++] = '\0';

  String *texto = create_string(buffer);

  free(buffer);
  fclose(in);

  int n;
  Suffix **a = sub_suffix(texto, &n);

  qsort_suf_array(a, n);

	char bx[64];
	String *s;

	while (scanf(" %s", bx) != 0) {
		s = create_string(bx);
		context_suf_query(a, n, s, CONTEXT);
		destroy_string(s);
	}

  destroy_suffix_array(a, n);
  destroy_string(texto);

  exit(EXIT_SUCCESS);
}
