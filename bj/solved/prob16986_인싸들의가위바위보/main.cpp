#include <iostream>
#include <algorithm>
using namespace std;

static const int Z = 1;
static const int KY = 2;
int N, K, A[9][9], order[4][20];

bool updateWin(int win[4], int idx) {
	if (++win[idx] == K) return true;
	return false;
}

int simulate() {
	int a = Z, b = KY;
	int win[4] = {0,};
	int idx[4] = {0,};
	while (true) {
		if ((a == Z || b == Z) && idx[Z] >= N) return 0;
		// cout << a << ": " << order[a][idx[a]] << " " << b << ": " << order[b][idx[b]] << endl;
		int res = A[order[a][idx[a]++]][order[b][idx[b]++]];
		int winner;
		if (res == 2) winner = a;
		else if (res == 1) winner = a > b ? a : b;
		else winner = b;
		// cout << "win: " << winner << endl;
		if (updateWin(win, winner)) break;
		b = a ^ b;
		a = winner;
	}
	return win[Z] == K;
}

int solve(int cnt, int v) {
	if (cnt == N) {
		// cout << "==============\n";
			// for (int i=0; i<N; i++) cout << order[Z][i] << " ";
			// cout << endl;
		if (simulate()) {
			return 1;
		}
		return 0;
	}
	for (int i=0; i<N; i++) {
		if (v & 1<<i) continue;
		order[Z][cnt] = i;
		if (solve(cnt + 1, v | 1<<i)) return 1;
	}
	return 0;
}

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N >> K;
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) cin >> A[i][j];
	}
	for (int i=2; i<=3; i++) {
		for (int j=0; j<20; j++) {cin >> order[i][j]; order[i][j]--;}
	}
	cout << solve(0, 0);
}