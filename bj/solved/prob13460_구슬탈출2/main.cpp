#include <iostream>
#include <algorithm>
using namespace std;

int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int N, M;
pair<int, int> blue, red, hole;
char map[10][10];

bool solved() {
    return red == hole && blue != hole;
}

void set(pair<int, int> pos, char c) {
    map[pos.first][pos.second] = c;
}

void roll(pair<int, int> &pos, int dir) {
    int ni = pos.first;
    int nj = pos.second;
    while (true) {
        ni += d[dir][0];
        nj += d[dir][1];
        if (map[ni][nj] == 'O') {
            pos.first = ni;
            pos.second = nj;
            return;
        }
        if (map[ni][nj] != '.')
            break;
        pos.first = ni;
        pos.second = nj;
    }
    set(pos, '#');
}

void roll(pair<int, int> &f, pair<int, int> &s, int dir) {
    roll(f, dir);
    roll(s, dir);
    set(f, '.');
    set(s, '.');
}

void roll(int dir) {
    if (dir % 2 == 0) {
        if (blue < red)
            roll(red, blue, dir);
        else
            roll(blue, red, dir);
    } else {
        if (blue > red)
            roll(red, blue, dir);
        else
            roll(blue, red, dir);
    }
}

int solve(int cnt) {
    if (solved()) {
        set(hole, 'O');
        return cnt;
    }
    if (cnt == 10 || blue == hole) {
        set(hole, 'O');
        return -1;
    }
    int ret = 11;
    for (int i=0; i<4; i++) {
        pair<int, int> oldBlue, oldRed;
        oldBlue = blue;
        oldRed = red;
        roll(i);
        int t = solve(cnt + 1);
        if (t != -1 && ret > t)
            ret = t;
        blue = oldBlue;
        red = oldRed;
    }
    return ret == 11 ? -1 : ret;
}

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N >> M;
    for (int i=0; i<N; i++) {
        string in;
        cin >> in;
        for (int j=0; j<M; j++) {
            map[i][j] = in[j];
            if (map[i][j] == 'B') {
                map[i][j] = '.';
                blue.first = i;
                blue.second = j;
            } else if (map[i][j] == 'R') {
                map[i][j] = '.';
                red.first = i;
                red.second = j;
            } else if (map[i][j] == 'O') {
                hole.first = i;
                hole.second = j;
            }
        }
    }
    cout << solve(0);
}