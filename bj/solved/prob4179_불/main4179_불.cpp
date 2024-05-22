#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int R, C, map[1000][1000], ci, cj, fi, fj;
queue<pair<int, int> > q, f;

void print_map() {
    cout << "====================\n";
    for(int i=0;i<R; i++) {
        for (int j=0; j<C; j++) {
            cout << (char)map[i][j];
        }
        cout << endl;
    }
}

void solve() {
    int time = 1;
    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            ci = q.front().first;
            cj = q.front().second;
            q.pop();
            if (map[ci][cj] == '#') 
                continue;
            map[ci][cj] = '#';
            for (int i=0; i<4; i++) {
                fi = ci + d[i][0];
                fj = cj + d[i][1];
                if (fi<0 || fi>=R || fj<0 || fj>=C) {
                    cout << time;
                    return;
                }
                if (map[fi][fj] == '#')
                    continue;
                q.push(make_pair(fi, fj));
            }
        }
        size = f.size();
        while (size--) {
            ci = f.front().first;
            cj = f.front().second;
            f.pop();
            for (int i=0; i<4; i++) {
                fi = ci + d[i][0];
                fj = cj + d[i][1];
                if (fi<0 || fi>=R || fj<0 || fj>=C || map[fi][fj] == '#') {
                    continue;
                }
                map[fi][fj] = '#';
                f.push(make_pair(fi, fj));
            }
        }
        time++;
    }
    cout << "IMPOSSIBLE";
}

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    string in;
    cin >> R >> C;
    for (int i=0; i<R; i++) {
        cin >> in;
        for (int j=0; j<C; j++) {
            map[i][j] = in[j];
            if (map[i][j] == 'J') {
                map[i][j] = '.';
                q.push(make_pair(i, j));
            } else if (map[i][j] == 'F') {
                map[i][j] = '#';
                f.push(make_pair(i, j));
            }
        }
    }
    solve();
}