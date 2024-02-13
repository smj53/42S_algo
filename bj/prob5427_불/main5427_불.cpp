#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int T, W, H, arr[1000][1000];
queue<int> q, f;

void bfs(void) {
    int step = 1;
    while (!q.empty()) {
        int size = f.size();
        while (size--) {
            int ci = f.front() / W;
            int cj = f.front() % W;
            f.pop();
            for(int i=0;i<4;i++) {
                int ni = ci + d[i][0];
                int nj = cj + d[i][1];
                if (ni<0 || ni>=H || nj<0 || nj>=W || arr[ni][nj] == '#')
                    continue;
                arr[ni][nj] = '#';
                f.push(ni * W + nj);
            }
        }
        size = q.size();
        while (size--) {
            int ci = q.front() / W;
            int cj = q.front() % W;
            q.pop();
            for(int i=0;i<4;i++) {
                int ni = ci + d[i][0];
                int nj = cj + d[i][1];
                if (ni<0 || ni>=H || nj<0 || nj>=W) {
                    cout << step << "\n";
                    return;
                }
                if (arr[ni][nj] != '.')
                    continue;
                arr[ni][nj] = 'x';
                q.push(ni * W + nj);
            }
        }
        step++;
    }
    cout << "IMPOSSIBLE\n";
}

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> T;
    while (T--) {
        cin >> W >> H;
        while (!q.empty()) q.pop();
        while (!f.empty()) f.pop();
        for(int i=0; i<H; i++) {
            string in;
            cin >> in;
            for (int j=0; j<W; j++) {
                arr[i][j] = in[j];
                if (in[j] == '*') {
                    arr[i][j] = '#';
                    f.push(i * W + j);
                } else if(in[j] == '@') {
                    arr[i][j] = 'x';
                    q.push(i * W + j);
                }
            }
        }
        bfs();
    }
}