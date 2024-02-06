#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N, M, K, map[50][50];
int d[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

void clear_map() {
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++)
            map[i][j] = 0;
    }
}

void check_adj(int ci, int cj) {
    queue<pair<int, int> > q;
    q.push(make_pair(ci, cj));
    map[ci][cj] = 0;
    while (!q.empty()) {
        ci = q.front().first;
        cj = q.front().second;
        q.pop();
        for (int i=0; i<4; i++) {
            int ni = ci + d[i][0];
            int nj = cj + d[i][1];
            if (ni<0 || ni>=N || nj<0 || nj>=M || !map[ni][nj])
                continue;
            q.push(make_pair(ni, nj));
            map[ni][nj] = 0;
        }
    }
}

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    int T, X, Y, ans;
    cin >> T;
    while (T--) {
        cin >> M >> N >> K;
        clear_map();
        while (K--) {
            cin >> Y >> X;
            map[X][Y] = 1;
        }
        ans = 0;
        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++) {
                if (map[i][j]) {
                    check_adj(i, j);
                    ans++;
                }
            }
        }
        cout << ans << "\n";
    }
}