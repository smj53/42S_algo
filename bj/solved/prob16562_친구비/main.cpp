#include <iostream>
#include <algorithm>
using namespace std;

int N, M, K, v, w, A[10001], p[10001];
bool isVisited[10001];

int find(int a) {
	if (p[a] == a) return a;
	return p[a] = find(p[a]);
}

void u(int a, int b) {
	int ra = find(a);
	int rb = find(b);
	if (ra == rb) return;
	if (A[ra] < A[rb]) p[rb] = ra;
	else p[ra] = rb;
}

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N >> M >> K;
	for (int i=1; i<=N; i++) {cin >> A[i]; p[i] = i;}
	while (M--) {
		cin >> v >> w;
		u(v, w);
	}
	int sum = 0;
	for (int i=1; i<=N; i++) {
		if (isVisited[find(i)]) continue;
		isVisited[p[i]] = true;
		sum += A[p[i]];
	}
	if (K >= sum) cout << sum;
	else cout << "Oh no";
}