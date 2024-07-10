#include <iostream>
#include <algorithm>
using namespace std;

int N, green[6][4], blue[6][4], score;
int t, x, y;

int getX(int map[6][4], int y) {
	int x = 0;
	while (x < 6 && map[x][y] == 0) x++;
	return x-1;
}

void moveOne(int map[6][4], int y) {
	int x = getX(map, y);
	map[x][y] = 1;
}

void moveHTwo(int map[6][4], int y) {
	int x = getX(map, y);
	x = min(x, getX(map, y+1));
	map[x][y] = map[x][y+1] = 1;
}

void moveVTwo(int map[6][4], int y) {
	int x = getX(map, y);
	map[x][y] = map[x-1][y] = 1;
}

void downBlock(int map[6][4], int start, int num) {
	for (int i=start; i>=num; i--) {
		for (int j=0; j<4; j++) {
			map[i][j] = map[i-num][j];
			map[i-num][j] = 0;
		}
	}
}

void destroy(int map[6][4]) {
	int num = 0;
	for (int i=0; i<6; i++) {
		bool flag = true;
		for (int j=0; j<4; j++) {
			if (map[i][j] == 0) {
				flag = false;
				break;
			}
		}
		if (flag) {
			score++;
			downBlock(map, i--, 1);
		}
	}
}

void down(int map[6][4]) {
	int num = 0;
	for (int i=0; i<2; i++) {
		for (int j=0; j<4; j++) {
			if (map[i][j]) {
				num++;
				break;
			}
		}
	}
	if (num > 0) downBlock(map, 5, num);
}

int count(int map[6][4]) {
	int cnt = 0;
	for (int i=0; i<6; i++) {
		for (int j=0; j<4; j++) {
			cnt += map[i][j];
		}
	}
	return cnt;
}

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N;
	while (N--) {
		cin >> t >> x >> y;
		switch (t) {
			case 1:
				moveOne(green, y);
				moveOne(blue, x);
				break;
			case 2:
				moveHTwo(green, y);
				moveVTwo(blue, x);
				break;
			case 3:
				moveVTwo(green, y);
				moveHTwo(blue, x);
				break;
		}
		destroy(green);
		destroy(blue);
		down(green);
		down(blue);
	}
	cout << score << "\n";
	cout << count(green) + count(blue);
}