#include <iostream>
#include <algorithm>
using namespace std;

int R, C, T, A[50][50], pos = -1;
int d[4][2] = {{0,1}, {-1,0}, {0,-1}, {1,0}};

void printMap() {
	cout << "====================\n";
	for (int i=0; i<R; i++) {
		for (int j=0; j<C; j++) {
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
}

void diffuse() {
	int copyMap[50][50];
	for (int i=0; i<R; i++) {
		for (int j=0; j<C; j++) {
			copyMap[i][j] = 0;
		}
	}
	copyMap[pos][0] = -1;
	copyMap[pos+1][0] = -1;
	for (int i=0; i<R; i++) {
		for (int j=0; j<C; j++) {
			if (A[i][j] <= 0) continue;
			int diffusedCnt = 0;
			int diffusedAmount = A[i][j] / 5;
			for (int k=0; k<4; k++) {
				int ni = i + d[k][0];
				int nj = j + d[k][1];
				if (ni<0 || ni>=R || nj<0 || nj>=C || A[ni][nj] == -1) continue;
				copyMap[ni][nj] += diffusedAmount;
				diffusedCnt++;
			}
			copyMap[i][j] += A[i][j] - diffusedAmount * diffusedCnt;
		}
	}
	for (int i=0; i<R; i++) {
		for (int j=0; j<C; j++) {
			A[i][j] = copyMap[i][j];
		}
	}
}

void operate(int si, int dk) {
	int sj = 0, prev = 0, k = 0;
	while(true) {
		int ni = si + d[k][0];
		int nj = sj + d[k][1];
		if (ni<0 || ni>=R || nj<0 || nj>=C) {
			k = (k + dk + 4) % 4;
			continue;
		}
		if (A[ni][nj] == -1) break;
		int cur = A[ni][nj];
		A[ni][nj] = prev;
		prev = cur;
		si = ni;
		sj = nj;
	}
}

int count() {
	int cnt = 2;
	for (int i=0; i<R; i++) {
		for (int j=0; j<C; j++) {
			cnt += A[i][j];
		}
	}
	return cnt;
}

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> R >> C >> T;
	for (int i=0; i<R; i++) {
		for (int j=0; j<C; j++) {
			cin >> A[i][j];
			if (pos == -1 && A[i][j] == -1) pos = i;
		}
	}
	while (T--) {
		// 확산
		diffuse();
		// 작동
		operate(pos, 1);
		operate(pos + 1, -1);
	}
	cout << count();
}