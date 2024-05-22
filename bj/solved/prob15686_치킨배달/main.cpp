#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

int N, M, selected[13], t;
vector<pair<int, int>> chickenPos;
vector<pair<int, int>> housePos;

int calcDist() {
    int ret = 0;
    for (auto p : housePos) {
        int m = INT_MAX;
        for (int i=0; i<M; i++) {
            pair<int, int> cp = chickenPos[selected[i]];
            m = min(m, abs(p.first - cp.first) + abs(p.second - cp.second));
        }
        ret += m;
    }
    return ret;
}

int solve(int cnt, int start) {
    if (cnt == M) {
        return calcDist();
    }
    int ret = INT_MAX;
    for (int i=start; i<chickenPos.size(); i++) {
        selected[cnt] = i;
        ret = min(ret, solve(cnt + 1, i + 1));
    }
    return ret;
}

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N >> M;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> t;
            if (t == 1) {
                housePos.push_back(make_pair(i, j));
            } else if (t == 2) {
                chickenPos.push_back(make_pair(i, j));
            }
        }
    }
    cout << solve(0, 0);
}