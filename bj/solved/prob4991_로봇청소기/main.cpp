#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

static const int MAX = 2100000000;

int H, W, map[20][20], dist[10][10], ans;
int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
vector<pair<int, int>> dirty;
pair<int, int> pos;

int getDist(pair<int, int> prev, int next) {
    queue<pair<int, int>> q;
    int visited[20][20] = {0,};
    visited[prev.first][prev.second] = 1;
    q.push(prev);
    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        for (int i=0; i<4; i++) {
            int ni = p.first + d[i][0];
            int nj = p.second + d[i][1];
            if (ni<0 || ni>=H || nj<0 || nj>=W || map[ni][nj] == 'x' || visited[ni][nj] != 0) continue;
            visited[ni][nj] = visited[p.first][p.second] + 1;
            if (ni == dirty[next].first && nj == dirty[next].second) return visited[ni][nj] - 1;
            q.push({ni, nj});
        }
    }
    return MAX;
}

void solve(int cnt, int v, int dis, int prev) {
    if (cnt == dirty.size()-1) {
        ans = min(ans, dis);
        return;
    }
    for (int i=0; i<dirty.size()-1; i++) {
        if (v & 1<<i) continue;
        int nextDist = dist[min(prev, i)][max(prev, i)];
        if (nextDist == MAX) continue;
        solve(cnt + 1, v | 1<<i, dis + nextDist, i);
    }
}

void calcDist() {
    for (int i=0; i<dirty.size(); i++) {
        for (int j=i + 1; j<dirty.size(); j++) {
            dist[i][j] = getDist(dirty[i], j);
        }
    }
}

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> W >> H;
    while (W != 0) {
        for (int i=0; i<H; i++) {
            string str;
            cin >> str;
            for (int j=0; j<W; j++) {
                map[i][j] = str[j];
                if (map[i][j] == '*') dirty.push_back({i, j});
                else if (map[i][j] == 'o') {
                    pos.first = i;
                    pos.second = j;
                }
            }
        }
        dirty.push_back(pos);
        ans = MAX;
        calcDist();
        solve(0, 0, 0, dirty.size()-1);
        cout << (ans == MAX ? -1 : ans) << "\n";
        dirty.clear();    
        cin >> W >> H;
    }
}