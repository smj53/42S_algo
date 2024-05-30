#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int N, s = 2, map[20][20], sx, sy, eatCnt = 2;
int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

template<typename T>
void printMap(T map[20][20]) {
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
}

int bfs() {
	queue<pair<int, int>> q;
	bool visited[20][20] = {0,};
	q.push({sx, sy});
	visited[sx][sy] = true;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	int t=0;
	while (!q.empty()) {
		int size = q.size();
		while (size--) {
			pair<int, int> p = q.front();
			q.pop();
			for (int i=0; i<4; i++) {
				sx = p.first + d[i][0];
				sy = p.second + d[i][1];
				if (sx<0 || sx>=N || sy<0 || sy>=N || visited[sx][sy] || map[sx][sy] > s) continue;
				if (map[sx][sy] != 0 && map[sx][sy] < s) pq.push({sx, sy});
				q.push({sx, sy});
				visited[sx][sy] = true;
			}
		}
		t++;
		if (!pq.empty()) break;
	}
	// printMap(visited);
	if (pq.empty()) return 0;
	pair<int, int> p = pq.top();
	sx = p.first;
	sy = p.second;
	map[sx][sy] = 0;
	if (--eatCnt == 0) {
		eatCnt = ++s;
	}
	// cout << "pq: ";
	// while (!pq.empty()) {
	// 	p = pq.top();
	// 	pq.pop();
	// 	cout << p.first << ", " << p.second << "|";}
	// cout << endl;
	return t;
}

int solve() {
	int cnt = 0;
	while (true) {
		// cout << "loop: " << s << "\n";
		int t = bfs();
		if (t == 0) break;
		cnt += t;
	}
	return cnt;
}

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N;
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				map[i][j] = 0;
				sx = i; sy = j;
			}
		}
	}
	cout << solve();
}