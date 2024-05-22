#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int N, M;
int arr[1000][1000][2];

int solve() {
  queue<pair<int, int>> q;
  q.push(make_pair(0, 0));
  arr[0][0][0] = 1;
  int step = 1;
  while (!q.empty()) {
    int size = q.size();
    while (size--) {
      int ci = q.front().first / M;
      int cj = q.front().first % M;
      int ck = q.front().second;
      if (ci == N - 1 && cj == M - 1)
        return step;
      q.pop();
      for (int i = 0; i < 4; i++) {
        int ni = ci + d[i][0];
        int nj = cj + d[i][1];
        if (ni < 0 || ni >= N || nj<0 || nj >= M)
          continue;
        if (!arr[ni][nj][ck]) {
          arr[ni][nj][ck] = 1;
          q.push(make_pair(ni * M + nj, ck));
        } else if (ck == 0) {
          q.push(make_pair(ni * M + nj, 1));
        }
      }
    }
    step++;
  }
  return -1;
}

int main(void) {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    string in;
    cin >> in;
    for (int j = 0; j < M; j++) {
      arr[i][j][0] = arr[i][j][1] = in[j] - 48;
    }
  }
  cout << solve();
}