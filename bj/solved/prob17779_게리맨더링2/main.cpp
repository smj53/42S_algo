#include <iostream>
#include <algorithm>
using namespace std;

int N, x, y, A[20][20];
// int map[20][20];

int calc(int d1, int d2) {
	int sum[5] = {0,};
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			if (i+j >= x+y && j-i <= y-x && j-i >= y-x-2*d1 && i+j <= x+y+2*d2) {
				sum[4]+=A[i][j];
				// map[i][j] = 0;
			}
			else if (0 <= i && i < x + d1 && 0 <= j && j <= y) {
				sum[0]+=A[i][j];
				// map[i][j] = 1;
			}
			else if (0 <= i && i <= x + d2 && y < j && j < N) {
				sum[1]+=A[i][j];
				// map[i][j] = 2;
			}
			else if (x+d1<=i && i<N && 0<=j && j<y-d1+d2) {
				sum[2]+=A[i][j];
				// map[i][j] = 3;
			}
			else if (x+d2<i && i<N && y-d1+d2<=j && j<N) {
				sum[3]+=A[i][j];
				// map[i][j] = 4;
			}
		}
	}
	int M, m;
	M = m = sum[0];
	for (int i=1; i<5; i++) {
		M = max(M, sum[i]);
		m = min(m, sum[i]);
	}
	return M - m;
}

// void printmap() {
// 	cout << x << ", " << y << " =======================\n";
// 	for (int i=0; i<N; i++) {
// 		for (int j=0; j<N; j++) cout << map[i][j] << " ";
// 		cout << "\n";
// 	}
// }

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N;
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			cin >> A[i][j];
		}
	}
	int ans = 2100000000;
	for (int i=0; i<N*N; i++) {
		x = i / N; y = i % N;
		for (int d1=1; d1<N; d1++) {
			for (int d2=1; x+d1+d2<N && y-d1>0 && y+d2<N; d2++) {
				// cout << d1 << " " << d2 << endl;
				ans = min(ans, calc(d1, d2));
				// printmap();
			}
		}
	}
	cout << ans;
}