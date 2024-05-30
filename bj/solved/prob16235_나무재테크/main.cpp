#include <iostream>
#include <algorithm>
#include <deque>
#include <queue>
using namespace std;

int N, M, K, A[10][10], nutri[10][10], r, c, z;
deque<int> age[10][10];
int d[8][2] = {{1, 0}, {-1, 0}, {1, 1}, {-1, 1}, {1, -1}, {-1, -1}, {0, 1}, {0, -1}};
queue<int> dead[10][10];

void spring() {
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			int size = age[i][j].size();
			while (size--) {
				int t = age[i][j].back();
				age[i][j].pop_back();
				if (nutri[i][j] >= t) {
					nutri[i][j] -= t;
					age[i][j].push_front(t+1);
				} else {
					dead[i][j].push(t);
				}
			}
		}
	}
}

void summer() {
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			while (!dead[i][j].empty()) {
				int t = dead[i][j].front();
				dead[i][j].pop();
				nutri[i][j] += t / 2;
			}
		}
	}
}

void fall() {
	int cnt[10][10] = {0,};
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			for (int t : age[i][j]) {
				if (t % 5 != 0) continue;
				for (int k=0; k<8; k++) {
					int ni = i + d[k][0];
					int nj = j + d[k][1];
					if (ni<0 || ni>=N || nj<0 || nj>=N) continue;
					cnt[ni][nj]++;
				}
			}
		}
	}
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			while(cnt[i][j]--) {
				age[i][j].push_back(1);
			}
		}
	}
}

void winter() {
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			nutri[i][j] += A[i][j];
		}
	}
}

int count() {
	int sum = 0;
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			sum += age[i][j].size();
		}
	}
	return sum;
}

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N >> M >> K;
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			nutri[i][j] = 5;
		}
	}
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			cin >> A[i][j];
		}
	}
	while (M--) {
		cin >> r >> c >> z;
		age[r-1][c-1].push_back(z);
	}
	while (K--) {
		spring();
		summer();
		fall();
		winter();
	}
	cout << count();
}