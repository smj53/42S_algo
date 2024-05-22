#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int N, m, M;
int arr[100][100], c[100][100];

void copy_arr() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      c[i][j] = arr[i][j];
    }
  }
}

void bfs(int ci, int cj) {
  queue<pair<int, int> > q;
  q.push(make_pair(ci, cj));
  c[ci][cj] = 0;
  while (!q.empty()) {
    ci = q.front().first;
    cj = q.front().second;
    q.pop();
    for (int i = 0; i < 4; i++) {
      int ni = ci + d[i][0];
      int nj = cj + d[i][1];
      if (ni < 0 || ni >= N || nj<0 || nj>=N || !c[ni][nj])
        continue;
      c[ni][nj] = 0;
      q.push(make_pair(ni, nj));
    }
  }
}

int solve(int w) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (arr[i][j] <= w)
        arr[i][j] = 0;
    }
  }
  copy_arr();
  int cnt = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (c[i][j]) {
        bfs(i, j);
        cnt++;
      }
    }
  }
  return cnt;
}

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N;
    m = 100;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        cin >> arr[i][j];
        m = min(m, arr[i][j]);
        M = max(M, arr[i][j]);
      }
    }
    int ans = 1;
    for (int i = m; i <= M;i++) {
      ans = max(ans, solve(i));
    }
    cout << ans;
}