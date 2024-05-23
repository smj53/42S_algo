#include <iostream>
#include <algorithm>
using namespace std;

int N, maxVal=-1000000000, minVal=1000000000;
int nums[12];
int cnt[4]; // 0: +, 1: -, 2: *, 3: /
int selected[11];

int calc() {
	int ret = nums[0];
	for (int i=1; i<N; i++) {
		switch (selected[i-1]) {
			case 0:
				ret += nums[i];
				break;
			case 1:
				ret -= nums[i];
				break;
			case 2:
				ret *= nums[i];
				break;
			case 3:
				ret /= nums[i];
				break;
		}
	}
	return ret;
}

void solve(int c) {
	if (c == N - 1) {
		int t = calc();
		maxVal = max(maxVal, t);
		minVal = min(minVal, t);
		return;
	}
	for (int i=0; i<4; i++) {
		if (cnt[i] == 0) continue;
		cnt[i]--;
		selected[c] = i;
		solve(c + 1);
		cnt[i]++;
	}
}

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N;
	for (int i=0; i<N; i++) {
		cin >> nums[i];
	}
	for (int i=0; i<4; i++) {
		cin >> cnt[i];
	}
	solve(0);
	cout << maxVal << "\n" << minVal;
}