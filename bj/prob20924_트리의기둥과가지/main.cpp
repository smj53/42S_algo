#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// BJ20924 트리의 기둥과 가지
// https://www.acmicpc.net/problem/20924
// FIXME: 다시 풀기

static const int MAX = 200001;
int N, R, a, b, d;
int ggParent, gg;

vector<pair<int, int>> g[MAX];

// int findGG(int c, int parent) {
// 	int cnt = 0, next;
// 	for (auto p : g[c]) {
// 		next = p.first;
// 		if (next == parent) continue;
// 		cnt++;
// 	}
// 	if (cnt == 1)
// 		return findGG(next, c);
// 	ggParent = parent;
// 	return c;
// }

int getPoleLength(int c, int parent) {
	int next, length;
	if ((parent != 0 && g[c].size() != 2)
		|| (parent == 0 && g[c].size() != 1)) {
		gg = c;
		ggParent = parent;
		return 0;
	}
	for (auto p : g[c]) {
		if (parent == p.first) continue;
		next = p.first;
		length = p.second;
	}
	return length + getPoleLength(next, c);
}

int getMaxBranchLength(int c, int parent) {
	int maxLength = 0;
	for (auto p : g[c]) {
		if (p.first == parent) continue;
		maxLength = max(maxLength, getMaxBranchLength(p.first, c) + p.second);
	}
	return maxLength;
}

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> N >> R;
	for (int i=0; i<N-1; i++) {
		cin >> a >> b >> d;
		g[a].push_back({b, d});
		g[b].push_back({a, d});
	}
	cout << getPoleLength(R, 0);
	cout << " " << getMaxBranchLength(gg, ggParent);
}
