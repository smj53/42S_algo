#include <iostream>
#include <algorithm>
using namespace std;

class Node {
public:
	int s;
	Node *red, *blue;
	bool occupied;
	Node(int n): s(n) { red = blue = 0; occupied = false; }
	Node(): Node(0) {}
};
ostream &operator<<(ostream &o, Node n) {
	o << "[" << n.s <<":";
	if (n.red) o << *n.red;
	else o << 0;
	o << "|";
	if (n.blue) o<<*n.blue<<"]";
	else o<<0<<"]";
	return o;
}

Node start;
int dice[10];
Node *cur[4] = {&start, &start, &start, &start};

Node *init(Node *a[4], int idx) {
	static const int num[4][2] = {{5, 2}, {3, 2}, {2, 1}, {-1, 2}};
	Node *prev = a[idx];
	for (int i=a[idx]->s + num[idx][0], j=num[idx][1]; j--; i+=num[idx][0]) {
		Node *cur = new Node(i);
		prev->red = cur;
		prev = cur;
	}
	if (idx != 0) {
		prev->red = a[0];
	}
	return prev;
}

void init() {
	Node *prev = &start;
	Node *end = new Node(0);
	Node *tmp[4] = {new Node(25), new Node(13), new Node(22), new Node(28)};
	Node *node35;
	for (int i=3; i>=0; i--) {
		node35 = init(tmp, i);
	}
	for (int i=2; i<=40; i+=2) {
		Node *cur = new Node(i);
		prev->red = cur;
		if (i % 10 == 0 && i / 10 != 4) {
			cur->blue = tmp[i / 10];
		}
		prev = cur;
	}
	node35->red = prev;
	prev->red = end;
}

Node *getNext(Node *n, int num) {
	Node *next = n;
	if (n->blue) {
		next = n->blue;
		num--;
	}
	while (next->red && num--) {
		next = next->red;
	}
	return next;
}

int solve(int cnt, int score) {
	if (cnt == 10) {
		return score;
	}
	int m = 0;
	for (int i=0; i<4; i++) {
		if (cur[i]->red == 0) continue;
		Node *next = getNext(cur[i], dice[cnt]);
		if (next->occupied) continue;
		Node *prev = cur[i];
		prev->occupied = false;
		if (next->red) next->occupied = true;
		cur[i] = next;
		m = max(m, solve(cnt+1, score+next->s));
		cur[i] = prev;
		prev->occupied = true;
		next->occupied = false;
	}
	return m;
}

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    init();
	for (int i=0; i<10; i++) cin >> dice[i];
	cout << solve(0, 0);
}