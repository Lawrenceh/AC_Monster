#include <cstdio>
#include <cstdlib>

#define NUM	10

int maxShares(int a[], int n);

int testShares(int a[], int n, int m, int sum, int groupsum, int aux[], int goal, int groupId);

int main() {
	int a[] = {2, 6, 4, 1, 3, 9, 7, 5, 8, 10};
	for (int i = 0; i < NUM; i++) printf(" %d ", a[i]);
	return 0;
}

int testShares(int a[], int n, int m, int sum, int groupsum, int aux[], int goal, int groupId) {
	if (goal < 0) return 0;
	if (goal == 0) {
		groupId++;
		goal = groupsum;
		if (groupId == m+1)	return 1;
	}
	for (int i = 0; i < n; i++) {
		if (aux[i] != 0) continue;
		aux[i] = groupId;
		if (testShares(a, n, m, sum, groupsum, aux, goal-a[i], groupId)) return 1;
		aux[i] = 0;				
	}
	return 0;
}

int maxShares(int a[], int n) {
	int sum = 0;
	int *aux = (int *)malloc(sizeof(int) * n);			
	for (int i = 0; i < n; i++) sum += a[i];
	for (int m = n; m >= 2; m--) {
		if (sum%m != 0) continue;
		for (int i = 0; i < n; i++) aux[i] = 0;
		if (testShares(a, n, m, sum, sum/m, aux, sum/m, 1)) {
			for (int i = 0; i < NUM; i++) printf(" %d ", aux[i]);
			free(aux);
			aux = NULL;
			return m;
		}
	}
	free(aux);
	aux = NULL;
	return 1;
}
