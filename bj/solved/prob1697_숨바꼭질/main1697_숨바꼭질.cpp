#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    int N, K;
    cin >> N >> K;
    int visited[100001] = {0,};
    queue<pair<int, int> > q;
    q.push(make_pair(N, 0)); // visited 배열에 얼마나 걸렸는지 저장해서 처리 가능
    visited[N] = 1;
    while (!q.empty()) {
        int cur = q.front().first;
        int step = q.front().second;
        q.pop();
        if (cur == K) {
            cout << step;
            return 0;
        }
        step++;
        if (!visited[cur-1] && cur - 1 >= 0) {
            q.push(make_pair(cur - 1, step));
            visited[cur-1] = 1;
        }
        if (!visited[cur+1] && cur + 1 <= 100000) {
            q.push(make_pair(cur + 1, step));
            visited[cur+1] = 1;
        }
        if (!visited[cur * 2] && cur * 2 <= 100000) {
            q.push(make_pair(cur * 2, step));
            visited[cur * 2] = 1;
        }
    }
}