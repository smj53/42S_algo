#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, x, y, d, g;
int map[101][101];
vector<int> curve;
int dir[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};

void getCurve() {
	curve.push_back(d);
	for (int i=0; i<g; i++) {
		for (int j=curve.size()-1; j>=0; j--) {
			curve.push_back((curve[j] + 1) % 4);
		}
	}
}

void drawCurve() {
	map[y][x] = 1;
	for (int i=0; i<curve.size(); i++) {
		d = curve[i];

		// 변 체크...
		// // d가 1, 2면 dir만큼 더해주고, 0, 3이면 더하지 않음
		// int ci = y + (d == 1 || d == 2) * dir[d][0];
		// int cj = x + (d == 1 || d == 2) * dir[d][1];
		// // d가 짝수면 1, 홀수면 2
		// int dd = 2 - ((d % 2) ^ 1);
		// if (ci>=0 && ci<=100 && cj>=0 && cj<=100)
		// 	map[ci][cj] |= 1 << dd;
		// ci += dir[dd][0];
		// cj += dir[dd][1];
		// if (ci>=0 && ci<=100 && cj>=0 && cj<=100)
		// 	map[ci][cj] |= 1 << ((dd + 2) % 4);

		y = y + dir[d][0];
		x = x + dir[d][1];
		map[y][x] = 1;
	}
}

int countSquare() {
	int cnt = 0;
	for (int i=0; i<100; i++) {
		for (int j=0; j<100; j++) {
			if (map[i][j] && map[i+1][j] && map[i][j+1] && map[i+1][j+1]) cnt++;
		}
	}
	return cnt;
}

void drawMap() {
	for (int i=0; i<=100; i++) {
		for (int j=0; j<=100; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
}

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N;
	while (N--) {
		cin >> x >> y >> d >> g;
		getCurve();
		drawCurve();
		curve.clear();
	}
	// drawMap();
	cout << countSquare();
}