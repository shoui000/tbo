#ifndef _SUFFIX_H
#define _SUFFIX_H

#include "str.h"

typedef struct {
  String *s;
  int index;
} Suffix;

// Cria uma estrutura de sufixo a partir de uma string e o indice de referencia
Suffix* suf(String *s, int index);

// Cria um vetor de sufixos a partir de uma string. O vetor contem todos os subsufixos da string. O parametro int *n eh o ponteiro para a variavel que recebera o tamanho do vetor
Suffix** sub_suffix(String *s, int *n);

// libera a estrutura do sufixo
void destroy_suffix(Suffix *s);

// imprime o sufixo para stdout
void print_suffix(Suffix *a);

// imprime o vetor de sufixos sufixo para stdout
void print_suffix_array(Suffix **a, int n);

// libera o vetor de sufixos
void destroy_suffix_array(Suffix **a, int n);

int compare_suf(Suffix *s, Suffix *t);

int suf_search(Suffix **s, int n, String *c);

void qsort_suf_array(Suffix **s, int n);

void context_suf_query(Suffix **s, int n, String *c, int context);

#endif
