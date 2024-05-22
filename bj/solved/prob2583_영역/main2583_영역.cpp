#include <iostream>
#include <algorithm>
#include <list>
#include <queue>

using namespace std;

int M, N, K, map[100][100], lx, ly, rx, ry;
int d[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

int solve(int ci, int cj) {
    int ret = 1;
    queue<pair<int, int> > q;
    q.push(make_pair(ci, cj));
    map[ci][cj] = 1;
    while (!q.empty()) {
        ci = q.front().first;
        cj = q.front().second;
        q.pop();
        for (int i=0;i<4; i++) {
            int ni = ci + d[i][0];
            int nj = cj + d[i][1];
            if (ni<0 || ni>=M || nj<0 || nj>=N || map[ni][nj])
                continue;
            map[ni][nj] = 1;
            q.push(make_pair(ni, nj));
            ret++;
        }
    }
    return ret;
}

void print_map() {
    for(int i=0; i<M; i++) {
        for (int j=0;j<N;j++) {
            cout << map[i][j];
        }
        cout << endl;
    }
}

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> M >> N >> K;
    while (K--) {
        cin >> ly >> lx >> ry >> rx;
        for (int i=lx; i<rx; i++) {
            for (int j=ly; j<ry; j++) {
                map[i][j] = 1;
            }
        }
    }
    // print_map();
    int count = 0;
    list<int> lst;
    for (int i=0; i<M; i++) {
        for (int j=0; j<N; j++) {
            if (!map[i][j]) {
                lst.push_back(solve(i, j));
                count++;
            }
        }
    }
    lst.sort();
    cout << count;
    if (count) {
        cout << "\n";
        for(auto i : lst) {
            cout << i;
        }
    }
}