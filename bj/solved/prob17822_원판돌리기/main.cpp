#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;

int N, M, T, x, d, k;
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
vector<deque<int>> m(50, deque<int>());

void printMap() {
	cout << "======================\n";
	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			cout << m[i][j] << " ";
		}
		cout << endl;
	}
}

void rotateMap(deque<int> &v, int d, int k) {
	int t;
	while (k--) {
		if (d) {
			t = v.front();
			v.pop_front();
			v.push_back(t);
		} else {
			t = v.back();
			v.pop_back();
			v.push_front(t);
		}
	}
}

void remove() {
	bool check[50][50] = {0,};
	bool hasSame = false;
	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			for (int di=0; di<4; di++) {
				int ni = i + dir[di][0];
				int nj = (j + dir[di][1] + M) % M;
				if (ni<0 || ni>=N || m[i][j] == 0) continue;
				if (m[i][j] == m[ni][nj]) {
					check[ni][nj] |= 1;
					hasSame = true;
				}
			}
		}
	}
	if (!hasSame) {
		double s = 0; int cnt = 0;
		for (int i=0; i<N; i++) {
			for (int j=0; j<M; j++) {
				s += m[i][j];
				if (m[i][j] != 0) cnt++;
			}
		}
		s /= cnt;
		for (int i=0; i<N; i++) {
			for (int j=0; j<M; j++) {
				if (m[i][j] == 0) continue;
				if (m[i][j] > s) m[i][j]--;
				else if (m[i][j] < s) m[i][j]++;
			}
		}
	} else {
		for (int i=0; i<N; i++) {
			for (int j=0; j<M; j++) {
				if (check[i][j])
					m[i][j] = 0;
			}
		}
	}
}

int sum() {
	int s = 0;
	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			s += m[i][j];
		}
	}
	return s;
}

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N >> M >> T;
	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			cin >> x;
			m[i].push_back(x);
		}
	}
	while (T--) {
		cin >> x >> d >> k;
		for (int i=x; i<=N; i+=x)
			rotateMap(m[i-1], d, k);
		remove();
	}
	cout << sum();
}