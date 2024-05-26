#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[50][9];
int selected[9];

int move(int base[3], int cnt) {
	int score = 0;
	for (int i=2; i>=0; i--) {
		if (!base[i]) continue;
		base[i] = 0;
		if (i + cnt > 2) score++;
		else base[i + cnt] = 1;
	}
	if (cnt != 4) base[cnt - 1] = 1;
	else score++;
	return score;
}

int simulate() {
	int score = 0, cur = 0;
	for (int i=0; i<N; i++) {
		int base[3] = {0,};
		int out = 0;
		while (out < 3) {
			if (arr[i][selected[cur]] == 0) {
				out++;
			} else {
				score += move(base, arr[i][selected[cur]]);
			}
			cur = (cur + 1) % 9;
		}
	}
	return score;
}

int solve(int cnt, int visited) {
	if (cnt == 9) {
		return simulate();
	}
	if (cnt == 3)
		return solve(cnt + 1, visited);
	int ret = 0;
	for (int i=1; i<9; i++) {
		if (visited & 1<<i) continue;
		selected[cnt] = i;
		ret = max(ret, solve(cnt + 1, visited | 1<<i));
	}
	return ret;
}

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N;
	for (int i=0; i<N; i++) {
		for (int j=0; j<9; j++) {
			cin >> arr[i][j];
		}
	}
	cout << solve(0, 1);
}