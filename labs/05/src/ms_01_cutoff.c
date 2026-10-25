#include "item.h"

#include <stdlib.h>

#define CUTOFF 30

void sort(Item *a, int lo, int hi);
void merge_sort(Item *a, Item *aux, int lo, int hi);
void merge(Item *a, Item *aux, int lo, int mid, int hi);
extern void insertion_sort(Item *, int, int);

void sort(Item *a, int lo, int hi) {
	int N = hi - lo + 1;
	Item *aux = malloc(N * sizeof(Item));

	merge_sort(a, aux, lo, hi);

	free(aux);
}

void merge_sort(Item *a, Item *aux, int lo, int hi) {
	if (hi <= lo + CUTOFF - 1) {
		insertion_sort(a, lo, hi);
		return;
	}

	int mid = lo + ((hi - lo)/ 2);

	merge_sort(a, aux, lo, mid);
	merge_sort(a, aux, mid+1, hi);
	merge(a, aux, lo, mid, hi);
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
