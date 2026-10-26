#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "event.h"
#include "PQ.h"

// TODO: Aqui você deve implementar uma fila com prioridade mínima para
//       ordenar os eventos por tempo, isto é, o evento com o menor tempo tem
//       a maior prioridade. Veja as funções definidas em 'event.h' para
//       a manipulação das estruturas de evento. A princípio, as funções já
//       existentes em 'event.h' são suficientes para implementar a simulação,
//       isto é, você não precisa implementar mais nada lá.
//
//       Você é livre para implementar a fila com prioridade da forma que quiser
//       mas é recomendado usar um min-heap para obter um bom desempenho. As
//       simulações maiores geram uma quantidade grande de eventos: um
//       limite superior frouxo (mas seguro) para o número máximo simultâneo de
//       eventos é N^3, aonde N é o número de partículas.

struct pq {
	Event **list;
	int qtd;
	int max_size;
};

#define exch(A, B) { Event *temp = A; A = B; B = temp; }

void fix_up(PQ *pq, int pos) {
	for (int i = pos; i > 1; i /= 2) {
		if (compare(pq->list[i/2], pq->list[i]) > 0) {
			exch(pq->list[i/2], pq->list[i]);
		} else break;
	}
}

void fix_down(PQ *pq, int pos) {
	int qtd = pq->qtd;
	int i = pos;

	while (i <= qtd/2) {
		int next = i * 2;

		if (qtd >= next+1 && compare(pq->list[next], pq->list[next+1]) > 0) {
			next++;
		}

		if (compare(pq->list[i], pq->list[next]) <= 0) {
			break;
		}

		exch(pq->list[i], pq->list[next]);
		i = next;
	}
}

/*
 * Cria uma nova fila de prioridade mínima com o limite de elementos informado.
 */
PQ* PQ_create(int max_N) {
	PQ* p = malloc(sizeof(struct pq));

	p->qtd = 0;
	p->max_size = max_N;
	p->list = malloc((max_N + 1) * sizeof(Event *));

	return p;
}

/*
 * Libera a memória da fila.
 */
void PQ_destroy(PQ *pq) {
	for (int i = 1; i <= pq->qtd; i++) {
		destroy_event(pq->list[i]);
	}
	free(pq->list);
	free(pq);
}

/*
 * Insere o evento na fila segundo o seu tempo.
 */
void PQ_insert(PQ *pq, Event *e) {
	if (pq->max_size == pq->qtd) return;

	pq->list[++pq->qtd] = e;

	fix_up(pq, pq->qtd);
}

/*
 * Remove e retorna o evento mais próximo.
 */
Event* PQ_delmin(PQ *pq) {
	if (PQ_is_empty(pq)) return NULL;

	Event *e = pq->list[1];
	exch(pq->list[pq->qtd], pq->list[1]);

	pq->qtd--;

	if (pq->qtd > 0)
		fix_down(pq, 1);

	return e;
}

/*
 * Testa se a fila está vazia.
 */
bool PQ_is_empty(PQ *pq) {
	return pq->qtd == 0;
}

/*
 * Retorna o tamanho da fila.
 */
int PQ_size(PQ *pq) {
	return pq->qtd;
}
