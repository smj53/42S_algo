#include <iostream>
#include <algorithm>
#include <list>
#include <queue>
using namespace std;
int N, arr[25][25];
int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int bfs(int ci, int cj) {
  int ret = 1;
  queue<pair<int, int>> q;
  arr[ci][cj] = 0;
  q.push(make_pair(ci, cj));
  while (!q.empty()) {
    ci = q.front().first;
    cj = q.front().second;
    q.pop();
    for (int i = 0; i < 4;i++) {
      int ni = ci + d[i][0];
      int nj = cj + d[i][1];
      if (ni < 0 || ni >= N || nj<0 || nj>=N || !arr[ni][nj])
        continue;
      q.push(make_pair(ni, nj));
      arr[ni][nj] = 0;
      ret++;
    }
  }
  return ret;
}

void solve() {
  int cnt = 0;
  list<int> lst;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (arr[i][j]) {
        lst.push_back(bfs(i, j));
        cnt++;
      }
    }
  }
  lst.sort();
  cout << cnt << "\n";
  for (int i : lst) {
    cout << i << "\n";
  }
}

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N;
    string in;
    for (int i = 0; i < N; i++) {
      cin >> in;
      for (int j = 0; j < N; j++) {
        arr[i][j] = in[j] - '0';
      }
    }
    solve();
}