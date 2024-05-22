#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

int N, M, K, arr[1000][1000], v[1000][1000][11];
int d[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

class Info {
public:
    int dist;
    int is_night;
    int x, y, k;
    Info (int d, int n, int x, int y, int k) : dist(d), is_night(n),
        x(x), y(y), k(k) {}
    bool operator<(const Info o) const {
        return this->dist > o.dist;
    }
    friend ostream& operator<<(ostream& os, const Info& i) {
        os << i.dist << ": (" << i.is_night << ") x, y, k:: " << i.x << " " <<i.y << " " << i.k;
        return os;
    }
};

int solve() {
    priority_queue<Info> q;
    q.push(Info(1, 0, 0, 0, K));
    v[0][0][0] = 1;
    while (!q.empty()) { 
        Info info = q.top();
        if (info.x == N - 1 && info.y == M - 1) {
            return info.dist;
        }
        q.pop();
        for (int i=0; i<4; i++) {
            int nd = info.dist;
            int nn = info.is_night;
            int nk = info.k;
            int ni = info.x + d[i][0];
            int nj = info.y + d[i][1];
            if (ni < 0 || ni>=N || nj<0 || nj>=M || (arr[ni][nj] == 1 && nk == 0))
                continue;
            if (arr[ni][nj] == 1) {
                if (nn) {
                    nd++;
                    nn ^= 1;
                }
                nk--;
            }
            nd++;
            if (v[ni][nj][nk] <= nd)
                continue;
            v[ni][nj][nk] = nd;
            q.push(Info(nd, nn ^ 1, ni, nj, nk));
        }
    }
    return -1;
}

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N >> M >> K;
    fill(&v[0][0][0], &v[N-1][M][K], INT_MAX);
    for (int i=0; i<N; i++) {
        string in;
        cin >> in;
        for (int j=0; j<M; j++) {
            arr[i][j] = in[j] - '0';
        }
    }
    cout << solve();
}