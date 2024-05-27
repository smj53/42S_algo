#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N, map[50][50], newMap[50][50], border[50][50], L, R, ans;
int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void open() {
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			for (int k=0; k<4; k++) {
				int ni = i + d[k][0];
				int nj = j + d[k][1];
				if (ni<0 || ni>=N || nj<0 || nj>=N) continue;
				int diff = abs(map[i][j] - map[ni][nj]);
				if (diff < L || R < diff) continue;
				border[i][j] |= 1<<k;
			}
		}
	}
}

void move(int ci, int cj, bool visited[50][50]) {
	queue<pair<int, int>> q;
	queue<pair<int, int>> u;
	int population = 0;
	visited[ci][cj] = true;
	q.push({ci, cj});
	while (!q.empty()) {
		pair<int, int> p = q.front();
		q.pop();
		u.push(p);
		population += map[p.first][p.second];
		for (int i=0; i<4; i++) {
			int ni = p.first + d[i][0];
			int nj = p.second + d[i][1];
			if (ni < 0 || ni>=N || nj<0 || nj>=N || visited[ni][nj] || !(border[p.first][p.second] & 1<<i)) continue;
			q.push({ni, nj});
			visited[ni][nj] = true;
		}
	}
	population /= u.size();
	while (!u.empty()) {
		pair<int, int> p = u.front();
		u.pop();
		newMap[p.first][p.second] = population;
	}
}

bool isChanged() {
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			if (map[i][j] != newMap[i][j]) return true;
		}
	}
	return false;
}

void clear() {
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			map[i][j] = newMap[i][j];
			border[i][j] = 0;
		}
	}
}

void print(int arr[50][50]) {
	cout << "============\n";
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N >> L >> R;
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			cin >> map[i][j];
		}
	}
	while (true) {
		// 1. 국경선 열기
		open();
		// 2. 연합 이동 (bfs로 국경선 열려있는 모든 인구수 더해서 각 칸 인구수 구하기)
		bool visited[50][50] = {0,};
		for (int i=0; i<N; i++) {
			for (int j=0; j<N; j++) {
				if (visited[i][j]) continue;
				move(i, j, visited);
			}
		}
		if (!isChanged()) break;
		clear();
		ans++;
	}
	cout << ans;
}