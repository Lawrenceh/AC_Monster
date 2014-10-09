#include <iostream>
using namespace std;

void max_dec_subseq_traverse(int* A, int* B, int k) {
	int i;
	for (i = k; i >= 0; i--) {
		if (A[i] > A[k] && B[k] == B[i] + 1) {
			max_dec_subseq_traverse(A, B, i);
			break;
		}
	}
	cout << "A[" << k << "] = " << A[k] << " "; 
}

void max_dec_subseq(int* A, int len) {
	int i, j, max_i = 0;
	int* B = new int[len];

	for (i = 0; i < len; i++) {
		B[i] = 1;
		for (j = 0; j < i; j++) {
			if (A[j] > A[i] && (B[j] + 1) > B[i]) {
				B[i] = B[j] + 1;
				if (B[i] > B[max_i]) max_i = i;
			}
		}
	}
	max_dec_subseq_traverse(A, B, max_i);
}

int main() {
	int A[]={9, 4, 3, 2, 5, 4, 3, 2};
	int AA[]={9, 8, 6, 5, 4, 3, 2, 1};
	max_dec_subseq(A, 8);
	cout << endl;
	max_dec_subseq(AA, 8);
	cout << endl;
	return 0;
}
