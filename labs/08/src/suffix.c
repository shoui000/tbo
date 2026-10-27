#include "suffix.h"

#include <stdio.h>
#include <stdlib.h>

// Cria uma estrutura de sufixo a partir de uma string e o indice de referencia
Suffix* suf(String *s, int index) {
	Suffix *x = malloc(sizeof(Suffix));

	if (index > s->len) {
		perror("[erro] foi tentado criar um sufixo que eh maior que a string");
		return NULL;
	}

	x->index = index;
	x->s = s;

	return x;
}

// Cria um vetor de sufixos a partir de uma string. O vetor contem todos os subsufixos da string. O parametro int *n eh o ponteiro para a variavel que recebera o tamanho do vetor
Suffix** sub_suffix(String *s, int *n) {
	Suffix **array = malloc(s->len * sizeof(Suffix *));
	*n = s->len;
	for (int i = 0; i < s->len; i++) {
		array[i] = suf(s, i);
	}
	return array;
}

// libera a estrutura do sufixo
void destroy_suffix(Suffix *s) {
	free(s);
}

// imprime o sufixo para stdout
void print_suffix(Suffix *a) {
	for (int i = a->index; i < a->s->len; i++) {
		putchar(a->s->c[i]);
	}
}

// imprime o vetor de sufixos sufixo para stdout
void print_suffix_array(Suffix **a, int n) {
	for (int i = 0; i < n; i++) {
		print_suffix(a[i]);
		putchar('\n');
	}
}

// libera o vetor de sufixos
void destroy_suffix_array(Suffix **a, int n) {
	for (int i = 0; i < n; i++) {
		destroy_suffix(a[i]);
	}
	free(a);
}

int compare_suf(Suffix *s, Suffix *t) {
	int s_i = s->index;
	int t_i = t->index;
	int s_len = s->s->len;
	int t_len = t->s->len;

	int r = 0;

	while (s_len - s_i > 0 && t_len - t_i > 0) {
		if (s->s->c[s_i] < t->s->c[t_i]) { r = -1; }
		else if (s->s->c[s_i] > t->s->c[t_i]) { r = 1; }

		if (r != 0) return r;

		s_i++; t_i++;
	}

	return (s->s->len - s->index) - (t->s->len - t->index);
}

int compare_suf_str(Suffix *s, String *c) {
	int s_i = s->index;
	int s_l = s->s->len;

	int c_l = c->len;
	int c_i = 0;


	while (s_l - s_i > 0 && c_l - c_i > 0) {
		if (s->s->c[s_i] < c->c[c_i]) { return -1; }
		if (s->s->c[s_i] > c->c[c_i]) { return  1; }

		s_i++; c_i++;
	}

	if (c_i == c_l) return 0;
	return -1;
}

int v_compare(const void *s, const void *t) {
	Suffix *s_x = *(Suffix **)s;
	Suffix *t_x = *(Suffix **)t;

	return compare_suf(s_x, t_x);
}

void qsort_suf_array(Suffix **s, int n) {
	qsort(s, n, sizeof(void *), v_compare);
}

int suf_search(Suffix **s, int n, String *c) {
	int lo = 0;
	int hi = n;

	while (lo < hi) {
		int mid = lo + (hi - lo) / 2;


		int comp = compare_suf_str(s[mid], c);

		if (comp < 0) {
			lo = mid + 1;
		} else  {
			hi = mid;
		}
	}

	if (lo < n &&	compare_suf_str(s[lo], c) == 0) return lo;

	return -1;
}

void context_suf_query(Suffix **s, int n, String *c, int context) {
	int z = suf_search(s, n, c);

	if (z == -1) {
		return;
	}

	for (int j = z; z < n && compare_suf_str(s[j], c) == 0; j++) {
		int pos = s[j]->index;
		int len = s[j]->s->len;

		int inicio = pos - context > 0 ? pos - context : 0;
		int fim = pos + c->len + context < len
			? pos + c->len + context
			: len;

		printf("%d\t", inicio);

		for (int i = inicio; i < fim; i++) {
			putchar(s[j]->s->c[i]);
		}

		putchar('\n');
	}


	putchar('\n');
}
