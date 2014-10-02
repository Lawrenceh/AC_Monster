// 0-1 knapsack problem
// f[i][v] = max(f[i - 1][v], f[i - 1][v - weight(i)] + cost[i])

#include <iostream>
using namespace std;

const int N = 3;
const int V = 5;
int weight[N + 1] = {0, 3, 2, 2};
int value[N + 1] = {0, 5, 10, 20};

int f[V + 1] = {0, 0, 0, 0, 0, 0};

int Max(int x,int y) {
	return x > y ? x : y;
}

int Knapsack() {
	memset(f, 0, sizeof(f));
	for (int i = 1; i <= N; i++) {
		for (int j = V; j >= weight[i]; j--) {
			f[j] = Max(f[j], f[j - weight[i]] + value[i]);
		}
	}
	return f[V];
}

int main() {
	cout << Knapsack() << endl;
	system("pause");
	return 1;
}
