#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N, map[100][100], v1[100][100], v2[100][100];
int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void check(int ci, int cj, char c1, char c2, int v[100][100]) {
    queue<pair<int, int> > q;
    q.push(make_pair(ci, cj));
    v[ci][cj] = 0;
    while (!q.empty()) {
        ci = q.front().first;
        cj = q.front().second;
        q.pop();
        for (int i=0; i<4; i++) {
            int ni = ci + d[i][0];
            int nj = cj + d[i][1];
            if (ni<0 || ni>=N || nj<0 || nj>=N || v[ni][nj] || (map[ni][nj] != c1 && map[ni][nj] != c2))
                continue;
            v[ni][nj] = 1;
            q.push(make_pair(ni, nj));
        }
    }
}

int main(void) {
    string in;
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N;
    cin.ignore();
    int c1 = 0, c2 = 0;
    for (int i=0; i<N; i++) {
        cin >> in;
        for (int j=0; j<N; j++) {
            map[i][j] = in[j];
        }
    }
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (!v1[i][j]) {
                check(i, j, map[i][j], map[i][j], v1);
                c1++;
            }
            if (!v2[i][j]) {
                if (map[i][j] == 'R' || map[i][j] == 'G')
                    check(i, j, 'R', 'G', v2);
                else
                    check(i, j, map[i][j], map[i][j], v2);
                c2++;
            }
        }
    }
    cout << c1 << " " << c2;
}