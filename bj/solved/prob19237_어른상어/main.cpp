#include <iostream>
#include <algorithm>
using namespace std;

class Shark {
	public:
		int dir, x, y, prio[4][4];
};

int N, M, K;
int map[20][20], smell[20][20][2]; // 0: 남긴 상어 번호 1: 남은 시간
Shark shark[401];
int d[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};

void printMap() {
	cout << "=========\n";
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			cout << map[i][j] << "|" << shark[map[i][j]].dir << " ";
		}
		cout << endl;
	}
}

bool check() {
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			if (map[i][j] == 0) continue;
			if (map[i][j] != 1) return true;
		}
	}
	return false;
}

void move() {
	int nmap[20][20] = {0,};
	for (int i=1; i<=M; i++) {
		Shark &s = shark[i];
		if (s.dir == -1) continue;
		int dir = -1;
		int ni, nj;
		for (int j=0; j<4; j++) {
			int nni = s.x + d[s.prio[s.dir][j]][0];
			int nnj = s.y + d[s.prio[s.dir][j]][1];
			if (nni<0 || nni>=N || nnj<0 || nnj>=N) continue;
			if (smell[nni][nnj][1] == 0) {
				ni = nni; nj = nnj;
				dir = s.prio[s.dir][j]; break;}
			else if (dir == -1 && smell[nni][nnj][0] == i) {
				ni = nni; nj = nnj;
				dir = s.prio[s.dir][j];
			}
		}
		s.dir = dir;
		s.x = ni;
		s.y = nj;
		if (nmap[ni][nj]==0) {nmap[ni][nj] = i;}
		else if (nmap[ni][nj] > i) {
			shark[nmap[ni][nj]].dir = -1;
			nmap[ni][nj] = i;
		} 
		else s.dir = -1;
	}
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			map[i][j] = nmap[i][j];
		}
	}
}

void removeSmell() {
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			if (smell[i][j][1] == 0) continue;
			smell[i][j][1]--;
		}
	}
}

void setSmell() {
	for (int i=1; i<=M; i++) {
		Shark s = shark[i];
		if (s.dir == -1) continue;
		smell[s.x][s.y][0] = i;
		smell[s.x][s.y][1] = K;
	}
}

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N >> M >> K;
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			cin >> map[i][j];
			if (map[i][j] != 0) {
				smell[i][j][0] = map[i][j];
				smell[i][j][1] = K;
				shark[map[i][j]].x = i;
				shark[map[i][j]].y = j;
			}
		}
	}
	for (int i=1; i<=M; i++) {
		cin >> shark[i].dir;
		shark[i].dir--;
	}
	for (int i=1; i<=M; i++) {
		for (int j=0; j<4; j++) {
			for (int k=0; k<4; k++) {
				cin >> shark[i].prio[j][k];
				shark[i].prio[j][k]--;
			}
		}
	}
	int T = 0;
	while (check() && T++ < 1000) {
		move();
		removeSmell();
		setSmell();
	}
	cout << (T > 1000 ? -1 : T);
}