#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;

long power(long a, int b) {
	if (b == 0) return 1;
	if (b == 1) return a;
	long c = power(a, b/2);
	c *= c;
	if (b%2) c *= a;
	return c;
}

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    long N, K, num;
	int digit = 1;
	cin >> N >> K;
	while (true) {
		num = digit * 9 * power(10, digit-1);
		if (num >= K) break;
		K -= num;
		digit++;
	}
	num = power(10, digit-1) + (K-1) / digit;
	if (num > N) cout << -1;
	else cout << num / power(10, digit - (K-1) % digit - 1) % 10;
	// cout << "digit: " << digit << " K: " << K << " num: " << num << endl;
}