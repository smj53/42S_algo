#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

// TODO: 다시 풀기
int N, M, v[1000001];
queue<int> q;

int solve() {
    int step = 0, isChanged;
    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            int t = q.front();
            q.pop();
            for (int i=1; i<=1000000; i *= 2) {
                int tt = t ^ i;
                if (tt > N || v[tt])
                    continue;
                q.push(tt);
                v[tt] = 1;
            }
        }
        if (q.empty())
            break;
        step++;
    }
    return step;
}

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N >> M;
    for (int i=0; i<M; i++) {
        int t;
        cin >> t;
        q.push(t);
        v[t] = 1;
    }
    cout << solve();
}