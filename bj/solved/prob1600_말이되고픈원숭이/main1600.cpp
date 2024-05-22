#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int d2[8][2] = {{2, 1}, {-2, 1}, {2, -1}, {-2, -1}, {1, 2}, {-1, 2}, {1, -2}, {-1, -2}};
int K, W, H, arr[200][200];

int solve() {
    int ci = 0, cj = 0, ret = 0;
    int v[200][200][31] = {0,};
    queue<pair<int,int> > q;
    q.push(make_pair(0, K));
    v[ci][cj][K] = 1;
    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            ci = q.front().first / W;
            cj = q.front().first % W;
            if (ci == H - 1 && cj == W - 1)
                return ret;
            int k = q.front().second;
            q.pop();
            for (int i=0; i<4; i++) {
                int ni = ci + d[i][0];
                int nj = cj + d[i][1];
                if (ni<0 || ni>=H || nj<0 || nj>=W || arr[ni][nj] || v[ni][nj][k])
                    continue;
                q.push(make_pair(ni * W + nj, k));
                v[ni][nj][k] = 1;
            }
            if (k) {
                for (int i=0; i<8; i++) {
                    int ni = ci + d2[i][0];
                    int nj = cj + d2[i][1];
                    if (ni<0 || ni>=H || nj<0 || nj>=W || arr[ni][nj] || v[ni][nj][k-1])
                        continue;
                    q.push(make_pair(ni * W + nj, k - 1));
                    v[ni][nj][k-1] = 1;
                }
            }
        }
        ret++;
    }
    return -1;
}

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> K >> W >> H;
    for (int i=0; i<H; i++) {
        for (int j=0; j<W; j++) {
            cin >> arr[i][j];
        }
    }
    cout << solve();
}