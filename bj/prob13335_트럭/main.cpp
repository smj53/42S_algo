#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N, W, L, ans, total, weight;
int trucks[1000];
queue<int> q;

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N >> W >> L;
	for (int i=0; i<N; i++) {
		cin >> trucks[i];
	}
	for (int i=0; i<W; i++)
		q.push(-1);
	int i = 0;
	while (total != 0 || i < N) {
		ans++;
		int t = q.front();
		q.pop();
		if (t != -1) {
			total--;
			weight -= trucks[t];
		}
		if (i < N && weight + trucks[i] <= L) {
			weight += trucks[i];
			total++;
			q.push(i++);
		} else {
			q.push(-1);
		}
	}
	cout << ans;
}

// 더 큰 경우?
// int main(void) {
//     cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
//     cin >> N >> W >> L;
// 	for (int i=0; i<N; i++) {
// 		cin >> trucks[i];
// 	}
// 	for (int i=0; i<N;) {
// 		while (i < N && total + trucks[i] <= L && q.size() < W) {
// 			ans += W - q.size();
// 			total += trucks[i];
// 			q.push(trucks[i++]);
// 		}
// 		if (q.size()) {
// 			total -= q.front();
// 			q.pop();
// 		}
// 	}
// 	cout << ans;
// }