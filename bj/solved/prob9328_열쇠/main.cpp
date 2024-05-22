#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int d[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
queue<int> q, door;
int h, w, v[100][100], key, ans;
char map[100][100];
string in;

void setStart(char c, int i, int j) {
    if (v[i][j] || c == '*')
        return;
    v[i][j] = 1;
    if (c >= 'A' && c <= 'Z') {
        door.push(i * w + j);
        return;
    }
    if (c >= 'a' && c <= 'z') {
        key |= 1 << (c - 'a');
    }
    q.push(i * w + j);
}

void openDoor() {
    int size = door.size();
    while (size--) {
        int ci = door.front() / w;
        int cj = door.front() % w;
        if (key & 1 << (map[ci][cj] - 'A')) {
            q.push(door.front());
        }
        else
            door.push(door.front());
        door.pop();
    }
}

void bfs() {
    while (!q.empty()) {
        int ci = q.front() / w;
        int cj = q.front() % w;
        q.pop();
        if (map[ci][cj]=='$')
            ans++;
        for (int i=0; i<4; i++) {
            int ni = ci + d[i][0];
            int nj = cj + d[i][1];
            if (ni<0 || ni>=h || nj<0 || nj>=w || v[ni][nj] || map[ni][nj] == '*')
                continue;
            v[ni][nj] = 1;
            if (map[ni][nj] >= 'A' && map[ni][nj] <= 'Z') {
                if ((key & 1 << (map[ni][nj] - 'A')) == 0) {
                    door.push(ni * w + nj);
                    continue;
                }
            }
            else if (map[ni][nj] >= 'a' && map[ni][nj] <= 'z') {
                key |= 1 << (map[ni][nj] - 'a');
            }
            q.push(ni * w + nj);
        }
    }
}

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> h >> w;
        for (int i=0; i<h; i++) {
            cin >> in;
            for (int j=0; j<w; j++) {
                map[i][j] = in[j];
            }
        }
        cin >> in;
        if (in[0] != '0')
            for (char c : in) {
                key |= 1 << (c - 'a');
            }
        for (int i=0; i<h; i++) {
            setStart(map[i][0], i, 0);
            setStart(map[i][w - 1], i, w-1);
        }
        for (int i=0; i<w; i++) {
            setStart(map[0][i], 0, i);
            setStart(map[h-1][i], h-1, i);
        }
        openDoor();
        while (!q.empty()) {
            bfs();
            openDoor();
        }
        cout << ans << "\n";
        ans = key = 0;
        while (!q.empty()) q.pop();
        while (!door.empty()) door.pop();
        fill(&v[0][0], &v[0][0] + sizeof(v) / sizeof(v[0][0]), 0);
    }
}