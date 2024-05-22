#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N, M, K, arr[1001][1001][11];
int d[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

int solve() {
    queue<pair<int, int> > q;
    int t = 1;
    q.push(make_pair(0, 0));
    arr[0][0][0] = -1;
    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            int ci = q.front().first / M;
            int cj = q.front().first % M;
            if (ci == N - 1 && cj == M - 1)
                return t;
            int ck = q.front().second;
            q.pop();
            for (int i=0; i<4; i++) {
                int ni = ci + d[i][0];
                int nj = cj + d[i][1];
                int nk = ck;
                if (ni<0 || ni>=N || nj<0 || nj>=M || arr[ni][nj][ck] == -1
                    || (ck == K && arr[ni][nj][0] == 1))
                    continue;
                if (arr[ni][nj][0] == 1) {
                    arr[ni][nj][nk++] = -1;
                }
                arr[ni][nj][nk] = -1;
                q.push(make_pair(ni * M + nj, nk));
            }
        }
        t++;
    }
    return -1;
}

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N >> M >> K;
    for (int i=0; i<N; i++) {
        string in;
        cin >> in;
        for (int j=0; j<M; j++) {
            arr[i][j][0] = in[j] - '0';
        }
    }
    cout << solve();
}