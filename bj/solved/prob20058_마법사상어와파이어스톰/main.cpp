#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N, Q, L, A[1<<6][1<<6], B[1<<6][1<<6];
int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void print() {
	cout << "---------------\n";
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			cout << A[i][j] <<" ";
		}
		cout << endl;
	}
}

int sum() {
	int s = 0;
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			s += A[i][j];
		}
	}
	return s;
}

int bfs(int si, int sj) {
	int cnt = 0;
	queue<pair<int, int>> q;
	q.push({si, sj});
	A[si][sj] = 0;
	while (!q.empty()) {
		pair<int, int> p = q.front();
		q.pop();
		cnt++;
		for (int i=0; i<4; i++) {
			int ni = p.first + d[i][0];
			int nj = p.second + d[i][1];
			if (ni<0 || ni>=N || nj<0 || nj>=N || A[ni][nj]==0) continue;
			q.push({ni, nj});
			A[ni][nj] = 0;
		}
	}
	return cnt;
}

int maxChunk() {
	int m = 0;
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			if (A[i][j]) m = max(m, bfs(i, j));
		}
	}
	return m;
}

void rotate(int si, int sj) {
	for (int i=0; i<L; i++) {
		for (int j=0; j<L; j++) {
			B[i][j] = A[si+L-1-j][sj+i];
		}
	}
	for (int i=0; i<L; i++) {
		for (int j=0; j<L; j++) {
			A[si+i][sj+j] = B[i][j];
		}
	}
}

void rotate() {
	for (int i=0; i<N; i+=L) {
		for (int j=0; j<N; j+=L) {
			rotate(i, j);
		}
	}
}

void reduce() {
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			B[i][j] = A[i][j];
			if (A[i][j] == 0) continue;
			int cnt = 0;
			for (int k=0; k<4; k++) {
				int ni = i + d[k][0];
				int nj = j + d[k][1];
				if (ni<0 || ni>=N || nj<0 || nj>=N || A[ni][nj]==0) continue;
				cnt++;
			}
			if (cnt < 3) B[i][j]--;
		}
	}
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			A[i][j] = B[i][j];
		}
	}
}

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N >> Q;
	N = 1 << N;
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			cin >> A[i][j];
		}
	}
	while (Q--) {
		cin >> L;
		L = 1<<L;
		rotate();
		reduce();
	}
	cout << sum() << "\n";
	cout << maxChunk();
}