#include <iostream>
#include <algorithm>
using namespace std;

// 조합 전부 구해서 정렬하는 방법도 있다

int N, num[10], cur, digit;

void print() {
	for (int i=0; i<10; i++) if (num[i]) cout << 9-i;
}

bool next() {
	if (!next_permutation(num, num+10)) {
		if (digit++ == 9) return false;
		for (int i=0; i<10; i++) num[i] = 0;
		for (int i=9-digit; i<10; i++) num[i] = 1;
	}
	return true;
}

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> N;
	num[9] = 1;
	do {
		if (cur++ == N) {
			print();
			return 0;
		}
	} while (next());
	cout << -1;
}