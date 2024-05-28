#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N, M, D, map[15][15], copyMap[15][15];
vector<pair<int, int>> attackPos[15];
int selected[3];
int d[3][2] = {{0, -1}, {-1, 0}, {0, 1}};

bool isEmpty() {
	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			if (copyMap[i][j])
				return false;
		}
	}
	return true;
}

void copy() {
	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			copyMap[i][j] = map[i][j];
		}
	}
}

int attack() {
	int cnt = 0;
	bool isAttacked[15][15] = {0,};
	for (int i=0; i<3; i++) {
		int idx = selected[i];
		for (pair<int, int> p : attackPos[idx]) {
			if (copyMap[p.first][p.second] == 1) {
				isAttacked[p.first][p.second] = true;
				break;
			}
		}
	}
	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			if (isAttacked[i][j]) {
				copyMap[i][j] = 0;
				cnt++;
			}
		}
	}
	return cnt;
}

void move() {
	for (int i=N-1; i>=0; i--) {
		for (int j=0; j<M; j++) {
			if (copyMap[i][j]) {
				copyMap[i][j] = 0;
				if (i+1 < N)
					copyMap[i+1][j] = 1;
			}
		}
	}
}

int simulate() {
	int cnt = 0;
	copy();
	while (!isEmpty()) {
		cnt += attack();
		move();
	}
	return cnt;
}


int solve(int cnt, int start) {
	if (cnt == 3) {
		return simulate();
	}
	int ret = 0;
	for (int i=start; i<M; i++) {
		selected[cnt] = i;
		ret = max(ret, solve(cnt + 1, i + 1));
	}
	return ret;
}

void getAttackPos(int si, int sj, vector<pair<int, int>>& res) {
	bool visited[15][15] = {0,};
	queue<pair<int, int>> q;
	int cnt = 0;
	q.push({si, sj});
	while (!q.empty() && cnt++ < D) {
		int size = q.size();
		while (size--) {
			pair<int, int> p = q.front();
			q.pop();
			for (int i=0; i<3; i++) {
				si = p.first + d[i][0];
				sj = p.second + d[i][1];
				if (si<0 || si>=N || sj<0 || sj>=M || visited[si][sj])
					continue;
				res.push_back({si, sj});
				q.push({si, sj});
				visited[si][sj] = true;
			}
		}
	}
}

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N >> M >> D;
	for (int i=0; i<M; i++) {
		getAttackPos(N, i, attackPos[i]);
	}
	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			cin >> map[i][j];
		}
	}
	cout << solve(0, 0);
}