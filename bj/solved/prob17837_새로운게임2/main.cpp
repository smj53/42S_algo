#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int d[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int N, K, map[12][12], a, b, c, dir[10];
pair<int, int> pos[10];
stack<int> dm[12][12];

bool moveWhite(int tr, int tc, int target) {
	int sr = pos[target].first, sc = pos[target].second;
	int t;
	stack<int> s;
	do {
		t = dm[sr][sc].top();
		dm[sr][sc].pop();
		pos[t].first = tr, pos[t].second = tc;
		s.push(t);
	} while (t != target);
	while (!s.empty()) {
		dm[tr][tc].push(s.top());
		s.pop();
	}
	return dm[tr][tc].size() >= 4;
}

bool moveRed(int tr, int tc, int target) {
	int sr = pos[target].first, sc = pos[target].second;
	int t;
	do {
		t = dm[sr][sc].top();
		dm[sr][sc].pop();
		pos[t].first = tr, pos[t].second = tc;
		dm[tr][tc].push(t);
	} while (t != target);
	return dm[tr][tc].size() >= 4;
}

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N >> K;
	for (int i=0; i< N; i++) {
		for (int j=0; j<N; j++) {
			cin >> map[i][j];
		}
	}
	for (int i=0; i<K; i++) {
		cin >> a >> b >> c;
		dm[--a][--b].push(i);
		pos[i] = {a, b};
		dir[i] = --c;
	}
	int turn = 0;
	while(turn <= 1000) {
		turn++;
		for (int i=0; i<K; i++) {
			int nr = pos[i].first + d[dir[i]][0];
			int nc = pos[i].second + d[dir[i]][1];
			if (nr<0 || nr>=N || nc<0 || nc>=N || map[nr][nc] == 2) {
				dir[i] ^= 1;
				nr = pos[i].first + d[dir[i]][0];
				nc = pos[i].second + d[dir[i]][1];
			}
			if (nr<0 || nr>=N || nc<0 || nc>=N || map[nr][nc] == 2) {
				continue;
			}
			if (map[nr][nc] == 0) {
				if (moveWhite(nr, nc, i)) {
					cout << turn;
					return 0;
				}
			} else if (map[nr][nc] == 1) {
				if (moveRed(nr, nc, i)) {
					cout << turn;
					return 0;
				}
			}
		}
	}
	cout << -1;
}