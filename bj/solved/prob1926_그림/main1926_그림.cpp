#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int N, M;
int d[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

int get_size(int *arr, int cp) {
    int ci, cj, size = 1;
    queue<int> q;
    q.push(cp);
    arr[cp] = 0;
    while (!q.empty()) {
        cp = q.front();
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
            q.push(np);
            size++;
        }
    }
    return size;
}

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N >> M;
    int arr[N][M];
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> arr[i][j];
        }
    }
    int cnt = 0, max_size = 0, size;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (arr[i][j]) {
                cnt++;
                size = get_size(&arr[0][0], i * M + j);
                max_size = max(max_size, size);
            }
        }
    }
    cout << cnt << "\n" << max_size;
}