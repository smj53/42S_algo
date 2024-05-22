#include <iostream>
#include <algorithm>
#include <iterator>
#include <queue>
#include <vector>
using namespace std;

int N, M;
int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int map[8][8];
vector<pair<int, int>> blanks;
vector<pair<int, int>> viruses;

void printMap(int m[8][8]) {
	cout << "=============================" << endl;
	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			cout << m[i][j];
		}
		cout << endl;
	}
}

void bfs(int m[8][8], int si, int sj) {
	queue<pair<int, int>> q;
	q.push({si, sj});
	m[si][sj] = 3;
	while (!q.empty()) {
		pair<int, int> p = q.front();
		q.pop();
		for (int i=0; i<4; i++) {
			int ni = p.first + d[i][0];
			int nj = p.second + d[i][1];
			if (ni<0 || ni>=N || nj<0 || nj>=M || m[ni][nj] != 0)
				continue;
			q.push({ni, nj});
			m[ni][nj] = 3;
		}
	}
}

void check(int m[8][8]) {
	for (int i=0; i<viruses.size(); i++) {
		pair<int, int> p = viruses[i];
		bfs(m, p.first, p.second);
	}
}

int countSafe(int m[8][8]) {
	int cnt = 0;
	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			if (m[i][j] == 0)
				cnt++;
		}
	}
	return cnt;
}

int comb(int start, int cnt) {
	if (cnt == 3) {
		int newMap[8][8];
		for (int i=0; i<N; i++) {
			for (int j=0; j<M;j++) {
				newMap[i][j] = map[i][j];
			}
		}
		check(newMap);
		return countSafe(newMap);
	}
	int max = 0;
	for (int i=start; i<blanks.size(); i++) {
		pair<int, int> p = blanks[i];
		map[p.first][p.second] = 1;
		int t = comb(i + 1, cnt + 1);
		max = max < t ? t : max;
		map[p.first][p.second] = 0;
	}
	return max;
}

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N >> M;
	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0)
				blanks.push_back({i, j});
			else if (map[i][j] == 2)
				viruses.push_back({i, j});
		}
	}
	cout << comb(0, 0);
}