#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int N, M, L;
vector<int> v;
priority_queue<int> pq;

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N >> M >> L;
	for (int i=0; i<N; i++) {
		int t;
		cin >> t;
		v.push_back(t);
	}
	sort(v.begin(), v.end());
	v.insert(v.begin(), 0);
	v.insert(v.end(), L);
	for (int i=0; i<v.size()-1; i++) {
		int diff = v[i+1] - v[i];
		cout << v[i] <<" and " << v[i+1] << " diff:: " <<diff << endl;
		if (diff == 0) continue;
		pq.push(diff);
	}
	while (M > 0) {
		int diff = pq.top();
		pq.pop();
		int div = min(M+1, diff / pq.top());
		for (int i=1; i<div; i++) {
			pq.push(diff/div);
		}
		pq.push(diff - diff/div*(div-1));
		M-=div-1;
	}
	cout << pq.top();
}