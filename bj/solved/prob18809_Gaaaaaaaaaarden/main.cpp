#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

class Pos {
public:
    int x, y;
    Pos(int x, int y) : x(x), y(y) {};
    Pos() {};
};

Pos arr[10];
queue<Pos> r, g;
int N, M, G, R, map[50][50], cnt, rv[50][50], copyArr[50][50], ans, selected[10];
int d[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

void copyMap(int m[50][50]) {
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            m[i][j] = map[i][j];
        }
    }
}

void clearMap(int m[50][50]) {
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            m[i][j] = 0;
        }
    }
}

int getFlower() {
    int flower = 0, size, step = 3;
    while (!r.empty() && !g.empty()) {
        size = g.size();
        while (size--) {
            // 갈 수 있는 곳 방문하면서 스텝 표시
            Pos p = g.front();
            g.pop();
            // cout << "=g:: x, y:: " << p.x << " " << p.y << endl;
            if (copyArr[p.x][p.y] == -1) {
                // 꽃이면
                continue;
            }
            for (int i=0; i<4; i++) {
                int ni = p.x + d[i][0];
                int nj = p.y + d[i][1];
                // cout << "==ni, nj::: "<< ni << " " << nj << endl;
                if (ni<0 || ni>=N || nj<0 || nj>=M || rv[ni][nj])
                    continue;
                if (copyArr[ni][nj] != 1) {
                    // cout << "===map:: " << copyArr[ni][nj] << endl;
                    continue;
                }
                // cout << "=== spread\n";
                copyArr[ni][nj] = step;
                g.push(Pos(ni, nj));
            }
        }
        size = r.size();
        while (size--) {
            // 맵에 표시된 게 현재 스텝이랑 같으면 꽃 개수 추가
            Pos p = r.front();
            r.pop();
            // cout << "=r:: x, y:: " << p.x << " " << p.y << endl;
            for (int i=0; i<4; i++) {
                int ni = p.x + d[i][0];
                int nj = p.y + d[i][1];
                if (ni<0 || ni>=N || nj<0 || nj>=M || (copyArr[ni][nj] != 1 && copyArr[ni][nj] != step) || rv[ni][nj])
                    continue;
                // cout << "==ni, nj::: "<< ni << " " << nj << endl;
                rv[ni][nj] = 1;
                if (copyArr[ni][nj] == step) {
                    copyArr[ni][nj] = -1;
                    flower++;
                }
                else {
                    r.push(Pos(ni, nj));
                }
            }
        }
        step++;
    }
    while (!r.empty()) r.pop();
    while (!g.empty()) g.pop();
    // cout << "===flower:: " << flower << endl;
    return flower;
}

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N >> M >> G >> R;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> map[i][j];
            if (map[i][j] == 2) {
                arr[cnt].x = i;
                arr[cnt++].y = j;
                map[i][j] = 1;
            }
        }
    }
    fill(selected+cnt-G-R, selected+cnt-R, 1);
    fill(selected+cnt-R, selected+cnt, 2);
    do {
        copyMap(copyArr);
        clearMap(rv);
        for (int i=0; i<cnt; i++) {
            if (selected[i] == 1) {
                g.push(arr[i]);
                copyArr[arr[i].x][arr[i].y] = 0;
            } else if (selected[i] == 2) {
                r.push(arr[i]);
                rv[arr[i].x][arr[i].y] = 1;
            }
        }
        ans = max(ans, getFlower());
    } while(next_permutation(selected, selected + cnt));
    cout << ans;
}