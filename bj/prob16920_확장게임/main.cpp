#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int N, M, P, S[10], map[1000][1000], v[1000][1000], cnt[10];
queue<int> q[10];

int bfs(int s, queue<int>& q, int idx) {
    int ret = 0;
    while (!q.empty() && s--) {
        int size = q.size();
        while (size--) {
            ret = 1;
            int ci = q.front() / M;
            int cj = q.front() % M;
            cnt[idx]++;
            q.pop();
            for (int i=0; i<4; i++) {
                int ni = ci + d[i][0];
                int nj = cj + d[i][1];
                if (ni<0 || ni>=N || nj<0 || nj>=M || map[ni][nj] != '.')
                    continue;
                map[ni][nj] = '#';
                q.push(ni * M + nj);
            }
        }
    }
    return ret;
}

void printAns() {
    for (int i=0; i<P; i++) {
        cout << cnt[i] << " ";
    }
}

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N >> M >> P;
    for (int i=0; i<P; i++) {
        cin >> S[i];
    }
    for (int i=0; i<N; i++) {
        string in;
        cin >> in;
        for (int j=0; j<M; j++) {
            map[i][j] = in[j];
            if ('1' <= map[i][j] && map[i][j] <= '9') {
                map[i][j] -= '1';
                q[map[i][j]].push(i * M + j);
            }
        }
    }
    for (int i=0; i<P; i++) {
        bfs(S[i], q[i], i);
    }
    int isChanged;
    do {
        isChanged = 0;
        for (int i=0; i<P; i++) {
            isChanged |= bfs(S[i], q[i], i);
        }
    } while (isChanged);
    printAns();
}