#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, H;
int top[500001], bot[500001];

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N >> H;
	for (int i=0; i<N; i++) {
		int t;
		cin >> t;
		if (i % 2) top[H+1-t]++;
		else bot[t]++;
	}
	for (int i=2; i<=H; i++) {
		top[i] += top[i-1];
	}
	for (int i=H-1; i>0; i--) {
		bot[i] += bot[i+1];
	}
	int min = 2100000000;
	int cnt = 0;
	for (int i=1; i<=H; i++) {
		if (min > top[i] + bot[i]) {
			min = top[i] + bot[i];
			cnt = 1;
		} else if (min == top[i] + bot[i]) cnt++;
	}
	cout << min << " " << cnt;
}