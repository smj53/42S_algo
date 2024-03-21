#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

int d[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
vector<int> m[5] = {
    {0},
    {0, 2},
    {0, 1},
    {0, 1, 2},
    {0, 1, 2, 3}
};
int cnt[5] = {4, 2, 4, 4, 1};
int mCnt;
vector<pair<int, int>> mPos;
vector<int> mDir;

int N, M, map[8][8], cMap[8][8];

void printMap(int m[8][8]) {
    cout << "========================\n";
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cout << m[i][j] << "\t";
        }
        cout<<endl;
    }
}

void cloneMap() {
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cMap[i][j] = map[i][j];
        }
    }
}

int count0() {
    int ret = 0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (cMap[i][j] == 0)
                ret++;
        }
    }
    return ret;
}

void check(int ci, int cj, int di, int dj) {
    while (1) {
        ci += di;
        cj += dj;
        if (ci<0 || ci>=N || cj<0 || cj>=M || cMap[ci][cj] == 6) {
            break;
        }
        cMap[ci][cj] = -1;
    }
}

int monitor() {
    cloneMap();
    for (int i=0; i<mCnt; i++) {
        int ci = mPos[i].first, cj = mPos[i].second;
        int didx = map[ci][cj] - 1;
        for (int j=0; j<m[didx].size(); j++) {
            int di = d[(m[didx][j] + mDir[i]) % 4][0];
            int dj = d[(m[didx][j] + mDir[i]) % 4][1];
            // int di = d[m[didx][(j + mDir[i]) % 4]][0];
            // int dj = d[m[didx][(j + mDir[i]) % 4]][1];
            check(ci, cj, di, dj);
        }
    }
    return count0();
}

int solve(int c) {
    if (c == mCnt) {
        return monitor();
    }
    int ret = INT_MAX;
    int ci = mPos[c].first;
    int cj = mPos[c].second;
    int cidx = map[ci][cj] - 1;
    for (int i=0; i<cnt[cidx]; i++) {
        mDir[c] = i;
        ret = min(ret, solve(c + 1));
    }
    return ret;
}

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N >> M;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> map[i][j];
            if (map[i][j] >= 1 && map[i][j] <= 5) {
                mPos.push_back(make_pair(i, j));
                mCnt++;
            }
        }
    }
    mDir.resize(mCnt);
    cout << solve(0);
}