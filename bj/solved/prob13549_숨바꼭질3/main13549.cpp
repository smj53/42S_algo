#include <iostream>
#include <algorithm>
#include <queue>
// FIXME: 다시풀기
using namespace std;
int N, K, arr[200001];

int solve() {
    deque<int > q;
    q.push_back(N);
    fill(arr, arr+200000, -1);
    arr[N] = 0;
    while (!q.empty()) {
        N = q.front();
        q.pop_front();
        if (N == K) {
            return arr[N];
        }
        if (N * 2 <= 100000 && arr[N*2] == -1) {
            q.push_front(N * 2);
            arr[N * 2] = arr[N];
        }
        if (N - 1 >= 0 && arr[N-1] == -1) {
            q.push_back(N-1);
            arr[N - 1] = arr[N] + 1;
        }
        if (N + 1 <= 100000 && arr[N+1] == -1) {
            q.push_back(N+1);
            arr[N + 1] = arr[N] + 1;
        }
    }
    return -1;
}

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N >> K;
    cout << solve();
}