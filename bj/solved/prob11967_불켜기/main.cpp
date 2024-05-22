#include <iostream>
#include <algorithm>
#include <queue>
#include <list>
using namespace std;
int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int N, M, light[100][100], v[100][100], cnt = 1;
list<int> s[100][100];

void onSwitch(list<int>& lst) {
    for (int i : lst) {
        int ci = i / N;
        int cj = i % N;
        if (light[ci][cj])
            continue;
        light[ci][cj] = 1;
        cnt++;
    }
}
void bfs(int ci, int cj) {
    queue<int> q, tmp;
    q.push(0);
    v[0][0] = light[0][0] = 1;
    onSwitch(s[0][0]);
    do {
        while (!q.empty()) {
            ci = q.front() / N;
            cj = q.front() % N;
            q.pop();
            for (int i=0; i<4; i++) {
                int ni = ci + d[i][0];
                int nj = cj + d[i][1];
                if (ni<0 || ni>=N || nj<0 || nj>=N || v[ni][nj])
                    continue;
                v[ni][nj] = 1;
                if (!light[ni][nj]) {
                    tmp.push(ni * N + nj);
                    continue;
                }
                onSwitch(s[ni][nj]);
                q.push(ni * N + nj);
            }
        }
        int size = tmp.size();
        while (size--) {
            ci = tmp.front() / N;
            cj = tmp.front() % N;
            tmp.pop();
            if (!light[ci][cj]) {
                tmp.push(ci * N + cj);
                continue;
            }
            onSwitch(s[ci][cj]);
            q.push(ci * N + cj);
        }
    } while (!q.empty());
}
int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N >> M;
    while (M--) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        s[x-1][y-1].push_back((a-1) * N + b - 1);
    }
    bfs(0, 0);
    cout << cnt;
}