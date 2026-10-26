#include "item.h"

#include <stdlib.h>

#define CUTOFF 32

void sort(Item *a, int lo, int hi);
void merge_sort(Item *a, Item *aux, int lo, int hi);
void merge(Item *a, Item *aux, int lo, int mid, int hi);
extern void insertion_sort(Item *, int, int);

void sort(Item *a, int lo, int hi) {
	int N = hi - lo + 1;

	Item *aux = malloc(N * sizeof(Item));

	for (int sz = CUTOFF; sz < N; sz <<= 1) { // define o tamanho de cada unidade de vetor
		for (int l = lo; l < N-sz; l += sz << 1) { // define o ponto inicial de cada vetor
			int x = l + sz + sz - 1; // ponto final do vetor da direita
			int right = x > hi ? hi : x;

			if (sz == CUTOFF) {
				insertion_sort(a, l, right);
				continue;
			}

			if (!less(a[l+sz], a[l+sz-1])) {
				continue;
			}

			merge(a, aux, l, l+sz-1, right);
		}
	}

	free(aux);
}

void merge(Item *a, Item *aux, int lo, int mid, int hi) {
	for (int i = lo; i <= hi; i++) {
		aux[i] = a[i];
	}
	int h = lo, k = mid+1;
	for (int i = lo; i <= hi; i++) {
		if (h > mid)                   a[i] = aux[k++];
		else if (k > hi)               a[i] = aux[h++];
		else if (less(aux[h], aux[k])) a[i] = aux[h++];
		else                           a[i] = aux[k++];
	}

}
