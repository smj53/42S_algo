#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

static const int MAX = 2147483647;

class E {
public:
	int v, d, c;
	E(int v, int d, int c): v(v), d(d), c(c) {}
	bool operator<(const E& o) const {
		if (d == o.d) {
			return c > o.c;
		}
		return d > o.d;
	}
	friend ostream &operator<<(ostream &os, E &o) {
		os << "[" << o.v << "] " << o.d << ", " << o.c;
		return os;
	}
};

vector<E> g[101];
int dist[10001][101];
int K, N, R, s, d, l, t;

int dijk() {
	priority_queue<E> pq;
	for (int i=0; i<10001; i++) for (int j=0; j<101; j++) dist[i][j] = MAX;
	pq.push(E(1, 0, 0));
	dist[0][1] = 0;
	while (!pq.empty()) {
		E cur = pq.top(); pq.pop();
		// cout << "cur: " << cur << ": " << dist[cur.c][cur.v] << "\n";
		if (cur.v == N) return cur.d;
		if (dist[cur.c][cur.v] > cur.d) continue;
		for (E next : g[cur.v]) {
			int nd = cur.d + next.d;
			int nc = cur.c + next.c;
			if (nc > K || dist[nc][next.v] <= nd) continue;
			dist[nc][next.v] = nd;
			pq.push(E(next.v, nd, nc));
		}
	}
	return -1;
}

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> K >> N >> R;
	while (R--) {
		cin >> s >> d >> l >> t;
		g[s].push_back(E(d, l, t));
	}
	cout << dijk();
}