#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int N, M;
int d[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
int print_map(int *arr) {
    printf("=====================\n");
    for (int i=0; i<N*M; i++) {
        if (i % M == 0)
            printf("\n");
        printf("%3d", arr[i]);
    }
    return 1;
}
int is_all_riped(int *arr) {
    for (int i=0; i<N*M; i++) {
        if (!arr[i])
            return 0;
    }
    return 1;
}

int get_day(int *arr) {
    int ci, cj, cp, day = 0, size, changed;
    queue<int> q;
    for (int i=0; i<N*M; i++) {
        if (arr[i] == 1) {
            q.push(i); }
    }
    while (!q.empty() && !is_all_riped(arr)) {
        size = q.size();
        changed = 0;
        while (size--) {
            cp = q.front();
            q.pop();
            ci = cp / M;
            cj = cp % M;
            for (int i=0; i<4; i++) {
                int ni = ci + d[i][0];
                int nj = cj + d[i][1];
                int np = ni * M + nj;
                if (ni<0 || ni>=N || nj<0 || nj>=M || arr[np] == -1 || arr[np] == 1)
                    continue;
                arr[np] = 1;
                changed = 1;
                q.push(np);
            }
        }
       // print_map(arr);
        day++;
        if (!changed)
            return -1;
    }
    if (is_all_riped(arr))
        return day;
    return -1;
}

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> M >> N;
    int arr[N][M];
    for (int i=0; i<N; i++) {
        
        for (int j=0; j<M; j++) {
            cin >> arr[i][j];
        }
    }
    cout << get_day(&arr[0][0]);
}