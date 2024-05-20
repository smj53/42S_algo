#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

int d[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int N, K, didx, sr, sc, r, c;
deque<pair<int, int>> snake;
deque<pair<int, char>> info;
char dir;
int map[100][100];

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N >> K;
	while (K--) {
		cin >> r >> c;
		map[r-1][c-1] = 1;
	}
	cin >> K;
	while (K--) {
		cin >> r >> dir;
		info.push_back({r, dir});
	}
	snake.push_back({0, 0});
	map[0][0] = 2;
	int time = 0;
	while (true) {
		time++;
		r = sr + d[didx][0];
		c = sc + d[didx][1];
		if (r<0 || r>=N || c<0 || c>=N || map[r][c] == 2)
			break;
		sr = r;
		sc = c;
		if (map[sr][sc] == 0) {
			pair<int, int> p = snake.back();
			map[p.first][p.second] = 0;
			snake.pop_back();
		}
		map[sr][sc] = 2;
		snake.push_front({sr, sc});
		if (info.front().first == time) {
			if (info.front().second == 'L')
				didx = (didx + 3) % 4;
			else
				didx = (didx + 1) % 4;
			info.pop_front();
		}
	}
	cout << time;
}