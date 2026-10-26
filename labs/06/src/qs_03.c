#include "item.h"

#define CUTOFF 30

extern void insertion_sort(Item *, int, int);
  
void sort(Item *a, int lo, int hi);
void quick_sort(Item *a, int lo, int hi);
int partition(Item *a, int lo, int hi);
int median_of_3(Item *a, int lo, int hi);

void sort(Item *a, int lo, int hi) {
  quick_sort(a, lo, hi);
}

void quick_sort(Item *a, int lo, int hi) {
  if (hi <= lo + CUTOFF - 1) {
    insertion_sort(a, lo, hi);
    return;
  }

  int median = median_of_3(a, lo, hi);
  exch(a[lo], a[median]);

  int j = partition(a, lo, hi);
  quick_sort(a, lo, j-1);
  quick_sort(a, j+1, hi);
}

int partition(Item *a, int lo, int hi) {
  int i = lo, j = hi+1;
  Item v = a[lo];

  while (1) {
    while (less(a[++i], v))
      if (i == hi) break;
    while (less(v, a[--j]))
      if (j == lo) break;
    if (i >= j) break;
    exch(a[i], a[j]);
  }

  exch(a[lo], a[j]);

  return j;
}

int median_of_3(Item *a, int lo, int hi) {
  int mid = lo + (hi-lo)/2;
  compexch(a[lo], a[hi]);
  compexch(a[lo], a[mid]);
  compexch(a[mid], a[hi]);
  return mid;
}
