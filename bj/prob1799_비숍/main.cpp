#include <iostream>
#include <algorithm>
using namespace std;
int N, map[10][10];

int solve(int p, int cnt, int v1, int v2, int isBlack) {
    if (p >= N * N) {
        return cnt;
    }
    int ci = p / N;
    int cj = p % N;
    int np = p + 2;
    if (N % 2 == 0 && cj >= N - 2) {
        if (ci % 2 == isBlack)
            np++;
        else
            np--;
    }
    if (map[ci][cj] == 0 || (v1 & 1<<(ci - cj + N - 1)) || (v2 & 1<<(ci + cj)))
        return solve(np, cnt, v1, v2, isBlack);
    return max(solve(np, cnt + 1, v1 | 1<<(ci - cj + N - 1), v2 | 1<<(ci + cj), isBlack),
                solve(np, cnt, v1, v2, isBlack));
}

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> map[i][j];
        }
    }
    cout << solve(0, 0, 0, 0, 0) + (N > 1 ? solve(1, 0, 0, 0, 1) : 0);
}