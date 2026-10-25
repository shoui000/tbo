/*
 * Código escrito por Eduardo Zambon
 */

#include <stdio.h>
#include <stdlib.h>

#define SEED 42

#define PATH_RANDOM      "./tests/in/unif_rand/"
#define PATH_SORTED      "./tests/in/sorted/"
#define PATH_REV_SORTED  "./tests/in/reverse_sorted/"
#define PATH_NEAR_SORTED "./tests/in/nearly_sorted/"

#define Ns 4
int sizes[Ns] = {100000, 1000000, 10000000, 100000000};

void output_array(char *path, int *a, int N) {
    // Determine required length for "path/N.txt" + null terminator
    int filepath_len = snprintf(NULL, 0, "%s/%d.txt", path, N) + 1;
    char *filepath = (char *)malloc(filepath_len);
    // Format the full file path string
    snprintf(filepath, filepath_len, "%s/%d.txt", path, N);

    FILE *f = fopen(filepath, "w");
    for (int i = 0; i < N; i++) {
        fprintf(f, "%d\n", a[i]);
    }
    fclose(f);
    free(filepath);
}

void gen_unif_rand(int *a, int N) {
    for (int i = 0; i < N; i++) {
        a[i] = rand();
    }
}

int compare_asc(const void* p1, const void* p2) {
    int x = *((int*) p1);
    int y = *((int*) p2);
    if      (x < y) return -1;
    else if (x > y) return  1;
    else /*x == y*/ return  0;
}

void gen_sorted(int *a, int N) {
    qsort(a, N, sizeof(int), compare_asc);
}

int compare_desc(const void* p1, const void* p2) {
    int x = *((int*) p1);
    int y = *((int*) p2);
    if      (x < y) return  1;
    else if (x > y) return -1;
    else /*x == y*/ return  0;
}

void gen_reverse_sorted(int *a, int N) {
    qsort(a, N, sizeof(int), compare_desc);
}

// Array *a needs to be sorted
void gen_nearly_sorted(int *a, int N) {
    for (int s = 0; s < N / 10; s++) {
        for (int j = 0; j < 5; j++) {
            if (rand() > RAND_MAX / 2) {
                int t = a[s+j];
                a[s+j] = a[s+2*j];
                a[s+2*j] = t;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    srand(SEED);

    for (int i = 0; i < Ns; i++) {
        int N = sizes[i];
        int *a = malloc(N * sizeof(int));

        gen_unif_rand(a, N);
        output_array(PATH_RANDOM, a, N);

        gen_reverse_sorted(a, N);
        output_array(PATH_REV_SORTED, a, N);

        gen_sorted(a, N);
        output_array(PATH_SORTED, a, N);

        gen_nearly_sorted(a, N);
        output_array(PATH_NEAR_SORTED, a, N);

        free(a);
    }

}
