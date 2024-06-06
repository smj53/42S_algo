#include <iostream>
#include <algorithm>
using namespace std;

int T, N, A, B, da, db;
int tree[10001];

int getDepth(int t) {
	int depth = 0;
	while (tree[t] != 0) {
		t = tree[t];
		depth++;
	}
	return depth;
}

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> T;
	while (T--) {
		cin >> N;
		for (int i=1; i<N; i++) {
			cin >> A >> B;
			tree[B] = A;
		}
		cin >> A >> B;
		da = getDepth(A);
		db = getDepth(B);
		while (da != db) {
			if (da > db) {
				A = tree[A];
				da--;
			} else {
				B = tree[B];
				db--;
			}
		}
		while (A != B) {
			A = tree[A];
			B = tree[B];
		}
		cout << A << "\n";
		for (int i=0; i<N; i++) tree[i] = 0;
	}
}