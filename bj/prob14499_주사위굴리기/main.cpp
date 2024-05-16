#include <iostream>
#include <algorithm>
using namespace std;

int N, M, K, r, c, x, y;
int map[20][20];
int d[5][2] = {{0, 0}, {0, 1}, {0, -1}, {-1, 0}, {1, 0}};
// int cube[6] = {1,2,3,4,5,6};
int cube[6] = {0, 0, 0, 0, 0, 0};

void printCube() {
	cout << "cube:: ";
	for (int i=0; i<6; i++) {
		cout << cube[i] << " ";
	}
	cout << endl;
}

void changeCube(int dir) {
	int t;
	if (dir == 3) {
		t = cube[0];
		cube[0] = cube[1];
		cube[1] = cube[2];
		cube[2] = cube[3];
		cube[3] = t;
	} else if (dir == 4) {
		t = cube[0];
		cube[0] = cube[3];
		cube[3] = cube[2];
		cube[2] = cube[1];
		cube[1] = t;
	} else if (dir == 1) {
		t = cube[0];
		cube[0] = cube[4];
		cube[4] = cube[2];
		cube[2] = cube[5];
		cube[5] = t;
	} else {
		t = cube[0];
		cube[0] = cube[5];
		cube[5] = cube[2];
		cube[2] = cube[4];
		cube[4] = t;
	}
}

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N >> M >> x >> y >> K;
	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			cin >> map[i][j];
		}
	}
	// for (int i=1; i<5; i++) {
	// 	changeCube(i);
	// 	printCube();
	// }
	while (K--) {
		int dir;
		cin >> dir;
		int nx = x + d[dir][0];
		int ny = y + d[dir][1];
		if (nx<0 || nx>=N || ny<0 || ny>=M)
			continue;
		changeCube(dir);
		x = nx; y = ny;
		if (map[x][y] == 0) {
			map[x][y] = cube[2];
		} else {
			cube[2] = map[x][y];
			map[x][y] = 0;
		}
		cout << cube[0] << "\n";
	}
}