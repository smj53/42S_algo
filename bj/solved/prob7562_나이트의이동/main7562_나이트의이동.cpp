#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int I, map[300][300], cx, cy, tx, ty;
int d[8][2] = {{1, 2}, {2, 1}, {-1, 2}, {2, -1}, {1, -2}, {-2, 1}, {-1, -2}, {-2, -1}};

int solve() {
    queue<pair<int, int> > q;
    q.push(make_pair(cx, cy));
    map[cx][cy] = 1;
    int ans = 0;
    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            cx = q.front().first;
            cy = q.front().second;
            q.pop();
            if (cx == tx && cy == ty)
                return ans;
            for (int i=0; i<8; i++) {
                int nx = cx + d[i][0];
                int ny = cy + d[i][1];
                if (nx<0 || nx>=I || ny<0 || ny>=I || map[nx][ny])
                    continue;
                map[nx][ny] = 1;
                q.push(make_pair(nx, ny));
            }
        }
        ans++;
    }
    return -1;
}

void clear_map() {
    for (int i=0; i<300; i++) {
        for (int j=0; j<300; j++)
            map[i][j] = 0;
    }
}

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> I;
        cin >> cx >> cy >> tx >> ty;
        clear_map();
        cout << solve() << "\n";
    }
}