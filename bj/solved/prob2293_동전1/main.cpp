#include <iostream>
#include <algorithm>

using namespace std;

int N, K, dp[10001], t;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	cin >> N >> K;
	dp[0] = 1;
	while (N--) {
		cin >> t;
		for (int i=t; i<=K; i++) {
			dp[i] += dp[i - t];
		}
	}
	cout << dp[K];
}