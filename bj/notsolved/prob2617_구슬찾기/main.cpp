#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int N, M, a, b, check[100][2];
set<int> g[100][2];

int t(int idx, int cur) {
	check[cur][idx] = true;
	int ret = 0;
	for (int i : g[cur][idx]) {
		if (check[i][idx]) continue;
		ret += t(idx, i) + 1;
	}
	return ret;
}

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N >> M;
	while (M--) {
		cin >> a >> b;
		g[a][0].insert(b);
		g[b][1].insert(a);
	}
	int cnt = 0;
	for (int i=1; i<=N; i++) {
		if (t(0, i) >= (N+1) / 2 || t(1, i) >= (N+1) / 2) {
			cnt++;
		}
		for (int i=0; i<=N; i++) check[i][0] = check[i][1] = 0;
			// cout << i << ": " << m[i][0] << "|"<<m[i][1] << ", ";
	}
	// cout << endl;
	cout << cnt;
}