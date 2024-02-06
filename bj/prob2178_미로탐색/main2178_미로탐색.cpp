#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int N, M;
int d[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

int get_dist(int *arr, int cp) {
    int ci, cj, dist;
    queue<pair<int, int> > q;
    q.push(make_pair(cp, 1));
    arr[cp] = 0;
    while (!q.empty()) {
        cp = q.front().first;
        dist = q.front().second;
        if (cp == N * M - 1) {
            return dist;
        }
        q.pop();
        ci = cp / M;
        cj = cp % M;
        for (int i=0; i<4; i++) {
            int ni = ci + d[i][0];
            int nj = cj + d[i][1];
            int np = ni * M + nj;
            if (ni<0 || ni>=N || nj<0 || nj>=M || !arr[np])
                continue;
            arr[np] = 0;
            q.push(make_pair(np, dist + 1));
        }
    }
    return -1;
}

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N >> M;
    int arr[N][M];
    for (int i=0; i<N; i++) {
        string t;
        cin >> t;
        for (int j=0; j<M; j++) {
            arr[i][j] = t[j] - '0';
        }
    }
    cout << get_dist(&arr[0][0], 0);
}