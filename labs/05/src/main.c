#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "item.h"

extern void sort(Item *, int, int);

int main(int argc, char **argv) {
	if (argc < 2) {
		perror("[erro] menos argumentos que o necessário\n");
		exit(EXIT_FAILURE);
	}

	int n = atoi(argv[1]);
	Item *array = malloc(n * sizeof(Item));

	for (int i = 0; i < n; i++) {
		scanf("%d\n", &array[i]);
	}

	clock_t inicial = clock();

	sort(array, 0, n-1);

	clock_t final = clock();

	for (int i = 0; i < n; i++) {
		printf("%d\n", array[i]);
	}

	fprintf(stderr, "Tempo de execução do merge sort: %.2f\n", (double)(final - inicial)/CLOCKS_PER_SEC);

	free(array);

	exit(EXIT_SUCCESS);

}
