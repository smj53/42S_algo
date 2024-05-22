#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

// TODO: bj17071 숨바꼭질5 구글링

const int MAX = 500001;
int N, K, arr[MAX][2];

int bfs() {
    int step = 1;
    queue<int> q;
    q.push(N);
    arr[N][0] = 1;
    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            N = q.front();
            q.pop();
            for (int t : {N + 1, N - 1, N * 2}) {
                if (t<0 || t>=MAX || arr[t][step % 2])
                    continue;
                arr[t][step % 2] = 1;
                q.push(t);
            }
        }
        K += step;
        if (K >= MAX)
            break;
        if (arr[K][step % 2]) {
            return step;
        }
        step++;
    }
    return -1;
}

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N >> K;
    if (N == K)
        cout << 0;
    else
        cout << bfs();
}