#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int N, M, arr[300][300], visited[300][300];

void bfs(int ci, int cj) {
    queue<int> q;
    q.push(ci * M + cj);
    visited[ci][cj] = 0;
    while (!q.empty()) {
        ci = q.front() / M;
        cj = q.front() % M;
        q.pop();
        for (int i=0; i<4; i++) {
            int ni = ci + d[i][0];
            int nj = cj + d[i][1];
            if (ni<0 || ni>=N || nj<0 || nj>=M || !visited[ni][nj])
                continue;
            q.push(ni * M + nj);
            visited[ni][nj] = 0;
        }
    }
}

int count() {
    int cnt = 0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (visited[i][j]) {
                bfs(i, j);
                cnt++;
            }
        }
    }
    return cnt;
}

void copy() {
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            visited[i][j] = arr[i][j];
        }
    }
}

int solve() {
    int ans = 0;
    copy();
    int c = count();
    while (c == 1) {
        copy();
        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++) {
                if (visited[i][j]) {
                    int sum = 0;
                    for (int k=0; k<4; k++) {
                        int ni = i + d[k][0];
                        int nj = j + d[k][1];
                        if (ni<0 || ni>=N || nj<0 || nj>=M || visited[ni][nj] != 0)
                            continue;
                        sum++;
                    }
                    arr[i][j] = max(0, arr[i][j] - sum);
                }
            }
        }
        copy();
        ans++;
        c = count();
    }
    if (c == 0)
        ans = 0;
    return ans;
}

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N >> M;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> arr[i][j];
        }
    }
    cout << solve();
}