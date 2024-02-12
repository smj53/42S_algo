#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
int T, N, arr[100000], visited[100000], ans;

void clear() {
  for (int i = 0; i < N; i++) {
    visited[i] = 0;
  }
}

int check(int cur, int dst) {
  int next = arr[cur];
  int ret = 0;
  arr[cur] = -1;
  if (next == dst) {
    ret = 1;
  } else if (arr[next] == -1) {
    ret = 0;
  } else {
    ret = check(next, dst);
  }
  arr[cur] = next;
  cout << "ret: " << ret << endl;
  return ret;
}

int dfs(int cur) {
  if (visited[cur])
    return 0;
  cout << "====" << cur << endl;
  int next = arr[cur];
  visited[cur] = 1;
  if (cur == next) {
    ans--;
    return 0;
  }
  if (visited[next] && check(cur, cur)) {
    ans--;
    return 1;
  }
  if (dfs(next)) {
    ans--;
    return 1;
  }
  return 0;
}

int solve() {
  ans = N;
  for (int i = 0; i < N; i++)
    if (!visited[i]) {
      dfs(i);
    }
  return ans;
}

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> T;
    while (T--) {
      cin >> N;
      clear();
      for (int i = 0; i < N; i++) {
        cin >> arr[i];
        arr[i]--;
      }
      solve();
      cout << solve() << "\n";
    }
}