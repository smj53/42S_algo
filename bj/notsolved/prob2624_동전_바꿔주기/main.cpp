#include <iostream>
#include <algorithm>
using namespace std;

int T, K, P[101], N[101], dp[10001];

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> T >> K;
	for (int i=0; i<K; i++) {
		cin >> P[i] >> N[i];
	}
	dp[0] = 1;
	for (int i=0; i<K; i++) {
		for (int j=T; j>0; j--) {
			for (int k=N[i]; k>0; k--) {
				if (j - k * P[i] < 0 || !dp[j - k * P[i]]) continue;
				dp[j] += dp[j - k * P[i]];
			}
		}
	}
	cout << dp[T];
}