#include <iostream>
#include <algorithm>
using namespace std;
// 0, 1, 2, 3: 좌 우 상 하
static const int M = 5;

int d[2] = {1, -1};
int sn[2] = {0, 0};
int N, map[20][20], cmap[20][20], s[M];

void printMap(int m[20][20]) {
    cout << "\n====================\n";
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
}

void cloneMap() {
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cmap[i][j] = map[i][j];
        }
    }
}

void sim_h(int idx) {
    int dj = d[idx];
    for (int i=0; i<N; i++) {
        int dst = sn[idx], src = dst + dj;
        while (src>=0 && src<N) {
            if (cmap[i][src] == 0) {
                src+=dj;
            } else if (cmap[i][dst] == 0) {
                cmap[i][dst] = cmap[i][src];
                cmap[i][src] = 0;
                src+=dj;
            } else if (cmap[i][src] == 0) {
                src+=dj;
            } else if (cmap[i][dst] == cmap[i][src]) {
                cmap[i][dst] += cmap[i][src];
                cmap[i][src] = 0;
                dst+=dj; src+=dj;
            } else if (cmap[i][dst] != cmap[i][src]) {
                if ((dst+=dj) == src) {
                    src+=dj;
                }
            }
        }
    }
}

void sim_v(int idx) {
    int di = d[idx];
    for (int i=0; i<N; i++) {
        int dst = sn[idx], src = dst + di;
        while (src>=0 && src<N) {
            if (cmap[src][i] == 0) {
                src+=di;
            } else if (cmap[dst][i] == 0) {
                cmap[dst][i] = cmap[src][i];
                cmap[src][i] = 0;
                src+=di;
            } else if (cmap[src][i] == 0) {
                src+=di;
            } else if (cmap[dst][i] == cmap[src][i]) {
                cmap[dst][i] += cmap[src][i];
                cmap[src][i] = 0;
                dst+=di; src+=di;
            } else if (cmap[dst][i] != cmap[src][i]) {
                if ((dst+=di) == src) {
                    src+=di;
                }
            }
        }
    }
}

void simulate() {
    for (int k=0; k<M; k++) {
        if (s[k] < 2)
            sim_h(s[k] % 2);
        else
            sim_v(s[k] % 2);
    }
}

int findMax() {
    int m = 0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            m = max(m, cmap[i][j]);
        }
    }
    return m;
}

int p(int cnt) {
    if (cnt == M) {
        cloneMap();
        simulate();
        return (findMax());
    }
    int ret = 0;
    for (int i=0; i<4; i++) {
        s[cnt] = i;
        ret = max(ret, p(cnt + 1));
    }
    return ret;
}

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N;
    sn[1] = N - 1;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> map[i][j];
        }
    }
    cout << p(0);
}