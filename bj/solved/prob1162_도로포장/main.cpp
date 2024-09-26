#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N, M, K, a, b, c;
long v[21][10001];
vector<pair<int, long>> g[10001];

class Node {
public:
	int cur, k; long dist;
	Node(int c, int k, long d) : cur(c), k(k), dist(d) {}
	bool operator<(Node o) const { return dist > o.dist; }
	friend ostream &operator<<(ostream &os, Node &n) {
		os << n.cur << " " << n.k << " " << n.dist;
		return os;
	}
};

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N >> M >> K;
	while (M--) {
		cin >> a >> b >> c;
		g[a].push_back({b, c});
		g[b].push_back({a, c});
	}
	priority_queue<Node> q;
	q.push(Node(1, 0, 0));
	for(int i=0; i<21; i++) for(int j=0; j<10001; j++) v[i][j] = -1;
	v[0][1] = 0;
	while (!q.empty()) {
		auto n = q.top(); q.pop();
		// cout << "====="<< n << endl;
		if (v[n.k][n.cur] != -1 && v[n.k][n.cur] < n.dist) continue;
		if (n.cur == N) {
			cout << n.dist;
			break;
		}
		for (auto p : g[n.cur]) {
			// cout << p.first << " ";
			if (n.k < K && (v[n.k + 1][p.first] == -1 || v[n.k + 1][p.first] > n.dist)) {
				q.push(Node(p.first, n.k + 1, n.dist));
				v[n.k + 1][p.first] = n.dist;
			}
			if (v[n.k][p.first] == -1 || v[n.k][p.first] > n.dist + p.second) {
				q.push(Node(p.first, n.k, n.dist + p.second));
				v[n.k][p.first] = n.dist + p.second;
			}
		}
		// cout << endl;
	}
}