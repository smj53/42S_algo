#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int T, x, y, diff, n, ans, t;

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> T;
	while (T--) {
		cin >> x >> y;
		diff = y - x;
		n = sqrt(diff);
		ans = 2 * n - 1;
		diff = diff - n * n;
		while (diff) {
			if (diff >= n) {
				t = diff / n;
				diff -= t * n;
				ans += t;
			}
			n--;
		}
		cout << ans << '\n';
	}
}
