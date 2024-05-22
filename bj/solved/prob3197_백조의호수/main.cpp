#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int d[4][2] = {{1,0}, {-1,0},{0,1},{0,-1}};
int R, C, map[1500][1500], vw[1500][1500], vl[1500][1500];
queue<int> w, l1, l2, m;

void waterBfs() {
    int ci, cj;
    while (!w.empty()) {
        ci = w.front() / C;
        cj = w.front() % C;
        map[ci][cj] = '.';
        m.push(w.front());
        w.pop();
    }
    while (!m.empty()) {
        ci = m.front() / C;
        cj = m.front() % C;
        m.pop();
        for (int i=0; i<4; i++) {
            int ni = ci + d[i][0];
            int nj = cj + d[i][1];
            if (ni<0 || ni>=R || nj<0 || nj>=C || vw[ni][nj]) {
                continue;
            }
            vw[ni][nj] = 1;
            if (map[ni][nj] == 'X')
                w.push(ni * C + nj);
            else
                m.push(ni * C + nj);
        }
    }
}

int swanBfs(queue<int>& q, int type) {
    int ci, cj;
    while (!q.empty()) {
        ci = q.front() / C;
        cj = q.front() % C;
        m.push(q.front());
        q.pop();
    }
    while (!m.empty()) {
        ci = m.front() / C;
        cj = m.front() % C;
        m.pop();
        for (int i=0; i<4; i++) {
            int ni = ci + d[i][0];
            int nj = cj + d[i][1];
            if (ni<0 || ni>=R || nj<0 || nj>=C) {
                continue;
            }
            if (vl[ni][nj] == type)
                continue;
            vl[ni][nj] |= type;
            if (map[ni][nj] == 'X') {
                q.push(ni * C + nj);
            }
            else {
                if (vl[ni][nj] == 3)
                    return 1;
                m.push(ni * C + nj);
            }
        }
    }
    return 0;
}

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> R >> C;
    for (int i=0; i<R ;i++) {
        string in;
        cin >> in;
        for (int j=0; j<C; j++) {
            map[i][j] = in[j];
            if (in[j] == 'L') {
                map[i][j] = '.';
                if (l1.empty()) {
                    l1.push(i * C + j);
                    vl[i][j] = 1;
                } else {
                    l2.push(i * C + j);
                    vl[i][j] = 2;
                }
            }
        }
    }
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            if (map[i][j] == '.' && !vw[i][j]) {
                vw[i][j] = 1;
                w.push(i * C + j);
            }
        }
    }
    int ans = 0;
    while (1) {
        waterBfs();
        if (swanBfs(l1, 1)) {
            break;
        }
        if (swanBfs(l2, 2)) {
            break;
        }
        ans++;
    }
    cout << ans;
}