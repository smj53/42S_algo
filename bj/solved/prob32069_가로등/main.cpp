#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <queue>
using namespace std;

int N, K;
long long L, a;
int d[] = {1, -1};

struct cmp {
	bool operator() (pair<long long, long long> a, pair<long long, long long> b) {
		return a.second > b.second;
	}
};

// TODO: BJ32069 가로등 다시 풀기
int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	cin >> L >> N >> K;
	// priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
	unordered_set<long long> visited;

	queue<pair<long long, long long>> pq;
	while (N-- > 0) {
		cin >> a;
		pq.push({a, 0});
		visited.insert(a);
	}

	int cnt = 0;
	while (!pq.empty() && K > 0) {
		auto p = pq.front();
		pq.pop();
		cout << p.second << "\n";
		K--;

		for (int i=0; i<2; i++) {
			long long np = p.first + d[i];
			if (np < 0 || np > L || visited.contains(np)) continue;
			visited.insert(np);
			pq.push({np, p.second + 1});
		}
	}
}