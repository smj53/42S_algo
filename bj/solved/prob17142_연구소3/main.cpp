#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
using namespace std;

int N, M, map[50][50], cmap[50][50];
vector<pair<int, int>> virus;
deque<pair<int, int>> dq;
int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int t = 0;

bool isAll() {
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			if (cmap[i][j] == 0) return false;
		}
	}
	return true;
}

void printArr(int arr[50][50]) {
	cout << "===================\n";
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

int bfs() {
	queue<pair<int, int>> q(dq);
	int t = 0;
	while (!q.empty()) {
		if (isAll()) break;
		int size = q.size();
		while (size--) {
			pair<int, int> p = q.front();
			q.pop();
			for (int i=0; i<4; i++) {
				int ni = p.first + d[i][0];
				int nj = p.second + d[i][1];
				if (ni<0 || ni>=N || nj<0 || nj>=N || cmap[ni][nj] == 1) continue;
				cmap[ni][nj] = 1;
				q.push({ni, nj});
			}
		}
		t++;
	}
	if (isAll()) return t;
	return -1;
}

void copyMap() {
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			cmap[i][j] = map[i][j];
		}
	}
}

int solve(int cnt, int start) {
	if (cnt == M) {
		copyMap();
		return bfs();
	}
	int ret = 2100000000;
	for (int i=start; i<virus.size(); i++) {
		dq.push_back(virus[i]);
		map[virus[i].first][virus[i].second] = 1;
		int t = solve(cnt + 1, i + 1);
		if (t != -1 && t < ret) ret = t;
		dq.pop_back();
		map[virus[i].first][virus[i].second] = 2;
	}
	if (ret == 2100000000) return -1;
	return ret;
}

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N >> M;
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				virus.push_back({i, j});
			}
		}
	}
	cout << solve(0, 0);
}