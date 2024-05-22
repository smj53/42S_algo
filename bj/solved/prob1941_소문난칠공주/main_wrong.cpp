#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int N = 5, arr[5][5];
int d[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

bool isAdj(int n, int p, int v) {
    if (n == 7)
        return true;
    int r = p / N;
    int c = p % N;
    for (int i=0; i<4; i++) {
        int nr = r + d[i][0];
        int nc = c + d[i][1];
        int np = nr * N + nc;
        if (nr>=0 && nr<N && nc>=0 && nc<N && (v & 1<<np) && isAdj(n + 1, np, v)) {
            return true;
        }
    }
    return false;
}

int find(int n, int v, int s) {
    if (n - s > 3)
        return 0;
    if (n == 7) {
        for (int i=0; i < 25; i++) {
            if (v & 1 << i) {
                return (isAdj(0, 1<<i, v) ? 1 : 0);
            }
        }
        return 0;
    }
    int ret = 0;
    for (int i=0; i<25; i++) {
        if (v & 1 << i)
            continue;
        int r = i / N;
        int c = i % N;
        ret += find(n + 1, v | 1 << i, s + (arr[r][c] == 'S' ? 1 : 0));
    }
    return ret;
}

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    for (int i=0;i<N;i++) {
        string in;
        cin >> in;
        for (int j=0;j<N;j++) {
            arr[i][j] = in[j];
        }
    }
    cout << find(0, 0, 0);
}