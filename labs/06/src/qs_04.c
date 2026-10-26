#include "item.h"

#define MAX_SZ 50

static int v[MAX_SZ];
static int size;

#define stack_init()   size =  0
#define stack_empty() (size == 0)

void push(int e) { v[size++] = e; }
int  pop()       { return v[--size]; }

#define push2(A, B) push(B); push(A)

void sort(Item *a, int lo, int hi);
void quick_sort(Item *a, int lo, int hi);
int partition(Item *a, int lo, int hi);

void sort(Item *a, int lo, int hi) {
  quick_sort(a, lo, hi);
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

void quick_sort(Item *a, int lo, int hi) {
    stack_init();
    push2(lo, hi);
    while(!stack_empty()) {
        lo = pop(); hi = pop();
        if (hi <= lo) continue; // Could add cutoff here.
        int i = partition(a, lo, hi);
        if (i-lo > hi-i) {  // Test the size of sub-arrays.
            push2(lo, i-1); // Push the larger one.
            push2(i+1, hi); // Sort the smaller one first.
        } else {
            push2(i+1, hi);
            push2(lo, i-1);
        }
    }
}
