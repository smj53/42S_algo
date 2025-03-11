#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Node {
public:
	Node *l, *r;
	int v;
	void setChild(Node &l, Node &r) {
		this->l = &l;
		this->r = &r;
	}
};

vector<Node> v;
int N, t, l, r;
int cnt = 0;

void traverse(Node &n, int t) {
	if (n.v == -1) {
		cnt--;
		return;
	}

	cnt++;
	traverse(*n.l, 1);
	cnt++;
	traverse(*n.r, 1);
	cnt += t;
}

void right(Node &n) {
	if (n.v == -1) {
		cnt++;
		return;
	}

	cnt--;
	right(*n.r);
}

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> N;
	v = vector<Node>(N + 1);
	v[0].v = -1;
	for (int i=1; i<=N; i++) {
		v[i].v = i;
		cin >> t >> l >> r;
		if (l < 0) l++;
		if (r < 0) r++;
		v[t].setChild(v[l], v[r]);
	}
	// traverse(v[1], 0);
	cnt = 2 * (N - 1);
	right(v[1]);
	cout << cnt;
}