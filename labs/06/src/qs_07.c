#include "item.h"

#define CUTOFF 30

extern void insertion_sort(Item *, int, int);

void sort(Item *a, int lo, int hi);
void quick_sort(Item *a, int lo, int hi);
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

  int lt = lo, gt = hi, i = lo;
  Item v = a[lo];

  while (i <= gt) {
    if (a[i] < v) {
			exch(a[lt], a[i]);
			lt++; i++;
		} else if (a[i] > v) {
			exch(a[i], a[gt]);
			gt--;
		} else {
			i++;
		}
  }

	quick_sort(a, lo, lt-1);
	quick_sort(a, gt+1, hi);

}

int median_of_3(Item *a, int lo, int hi) {
  int mid = lo + (hi-lo)/2;
  compexch(a[lo], a[hi]);
  compexch(a[lo], a[mid]);
  compexch(a[mid], a[hi]);
  return mid;
}
