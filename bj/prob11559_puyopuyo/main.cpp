#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

static const int ROW = 12;
static const int COL = 6;

int d[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
char map[ROW][COL];

void restore(char c) {
	for (int i=0; i<ROW; i++) {
		for (int j=0; j<COL; j++) {
			if (map[i][j] == 'D')
				map[i][j] = c;
		}
	}
}

bool bfs(int si, int sj, bool visited[ROW][COL]) {
	queue<pair<int, int>> q;
	q.push(make_pair(si, sj));
	char color = map[si][sj];
	int count = 0;
	map[si][sj] = 'D';
	visited[si][sj] = true;
	while (!q.empty()) {
		pair<int, int> p = q.front();
		q.pop();
		count++;
		for (int i=0; i<4; i++) {
			int ni = p.first + d[i][0];
			int nj = p.second + d[i][1];
			if (ni<0 || ni>=ROW || nj<0 || nj>=COL || map[ni][nj] != color)
				continue;
			map[ni][nj] = 'D';
			visited[ni][nj] = true;
			q.push(make_pair(ni, nj));
		}
	}
	if (count < 4) {
		restore(color);
		return false;
	} else {
		restore(0);
		return true;
	}
}

bool checkChain() {
	bool hasChain = false;
	bool visited[ROW][COL];
	bzero(visited, sizeof(visited));

	for (int i=0; i<ROW; i++) {
		for (int j=0; j<COL; j++) {
			if (map[i][j] != 0 && !visited[i][j] && bfs(i, j, visited)) {
				hasChain = true;
			}
		}
	}
	return hasChain;
}

void gravity() {
	for (int j=0; j<COL; j++) {
		int blank = ROW - 1;
		while (true) {
			while (blank >= 0 && map[blank][j] != 0) blank--;
			int puyo = blank - 1;
			while (puyo >= 0 && map[puyo][j] == 0) puyo--;
			if (puyo < 0) break;
			map[blank][j] = map[puyo][j];
			map[puyo][j] = 0;
		}
	}
}

void printMap() {
	cout << "==========map==============" << endl;
	for (int i=0; i<ROW; i++) {
		for (int j=0; j<COL; j++) {
			cout << (map[i][j] ? map[i][j] : '.');
		}
		cout << endl;
	}
}

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	int chain = 0;
	for (int i=0; i<ROW; i++) {
		string in;
		cin >> in;
		for (int j=0; j<COL; j++) {
			if (in[j] != '.') {
				map[i][j] = in[j];
			}
		}
	}
    while (true) {
		if (!checkChain())
			break;
		chain++;
		// printMap();
		gravity();
		// printMap();
	}
	cout << chain;
}