#include <iostream>
#include <algorithm>
using namespace std;

int T, N, ptr;
string in;

int consume0(int *idx) {
	int cnt = *idx;
	while (*idx >= 0) {
		if (in[*idx] != '0')
			break;
		(*idx)--;
	}
	return cnt - *idx;
}

int consume1(int *idx) {
	int cnt = *idx;
	while (*idx >= 0) {
		if (in[*idx] != '1')
			break;
		(*idx)--;
	}
	return cnt - *idx;
}

bool check1001(int *i) {
	int t = *i;
	int cnt;
	if ((cnt = consume1(&t)) < 1 || (cnt = consume0(&t)) < 2
		|| in[t] != '1')
		return false;
	*i = t - 1;
	return true;
}

bool check01(int *i) {
	int cnt;
	if ((cnt = consume1(i)) != 1 || (cnt = consume0(i)) != 1)
		return false;
	return true;
}

bool check() {
	for (int i=N-1; i>=0;) {
		if (check1001(&i)) {
			continue;
		}
		if (!check01(&i)) {
			return false;
		}
	}
	return true;
}

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		cin >> in;
		N = in.size();
		cout << (check() ? "YES\n" : "NO\n");
	}
	cout << endl;
}
