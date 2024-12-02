#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int d[9][2] = {{0,0}, {-1,0}, {-1,-1}, {0,-1}, {1,-1}, {1,0}, {1,1}, {0,1}, {-1, 1}};
int map[4][4], fish[17][2], a, b;

void printMap() {
    cout << "======================\n";
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            cout << map[i][j] << "|" << fish[map[i][j]][0] << "|" << fish[map[i][j]][1] << " ";
        }
        cout << "\n";
    }
}

void store(int pmap[4][4], int pfish[17][2]) {
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            pmap[i][j] = map[i][j];
        }
    }
    for (int i=0; i<17; i++) {pfish[i][0] = fish[i][0]; pfish[i][1] = fish[i][1];}
}

void restore(int pmap[4][4], int pfish[17][2]) {
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            map[i][j] = pmap[i][j];
        }
    }
    for (int i=0; i<17; i++) {fish[i][0] = pfish[i][0]; fish[i][1] = pfish[i][1];}
}

int canMove(int pos, int di) {
    int ni = pos/4 + d[di][0], nj = pos%4 + d[di][1];
    if (ni<0 || ni>=4 || nj<0 || nj>=4 || map[ni][nj] == 0) return -1;
    return map[ni][nj];
}

void swap(int idx, int oidx) {
    int pp = fish[idx][1], pi = pp/4, pj = pp%4;
    int np = fish[oidx][1], ni = np/4, nj = np%4;
    map[pi][pj] = oidx;
    map[ni][nj] = idx;
    fish[idx][1] = np;
    fish[oidx][1] = pp;
}

void moveFish() {
    for (int i=1; i<17; i++) {
        if (fish[i][0] == 0) continue;
        int di = fish[i][0], other;
        for (int j=0; j<8; j++) {
            di = (fish[i][0] + j - 1) % 8 + 1;
            other = canMove(fish[i][1], di);
            if (other != -1) {
                fish[i][0] = di;
                break;
            }
        }
        if (other == -1) continue;
        swap(i, other);
    }

}

void checkAvail(vector<int> &avail) {
    int ni = fish[0][1]/4; int nj = fish[0][1]%4;
    int sd = fish[0][0];
    while (ni>=0 && ni<4 && nj>=0 && nj<4) {
        if (map[ni][nj] != 0 && fish[map[ni][nj]][0] != 0) {
            avail.push_back(map[ni][nj]);
        }
        ni += d[sd][0];
        nj += d[sd][1];
    }

}

int solve(int eaten) {
    vector<int> avail;
    int pmap[4][4], pfish[17][2];
    store(pmap, pfish);
    moveFish();
    checkAvail(avail);
    if (avail.size() == 0) {
        restore(pmap, pfish);
        return eaten;
    }
    int ret = 0;
    for (auto idx : avail) {
        int px = fish[idx][1]/4, py = fish[idx][1]%4, ps = fish[0][0], psp = fish[0][1];
        map[px][py] = 0;
        map[psp/4][psp%4] = idx;
        fish[0][0] = fish[idx][0];
        fish[0][1] = fish[idx][1];
        fish[idx][0] = 0;
        fish[idx][1] = psp;
        ret = max(ret, solve(eaten + idx));
        fish[idx][0] = fish[0][0];
        fish[idx][1] = fish[0][1];
        fish[0][0] = ps;
        fish[0][1] = psp;
        map[psp/4][psp%4] = 0;
        map[px][py] = idx;
    }
    restore(pmap, pfish);
    return ret;
}

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            cin >> a >> b;
            map[i][j] = a;
            fish[a][0] = b;
            fish[a][1] = i*4+j;
        }
    }
    int fidx = map[0][0];
    fish[0][0] = fish[fidx][0];
    fish[fidx][0] = 0;
    map[0][0] = 0;
    cout << solve(fidx);
}