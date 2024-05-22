#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int F, S, G, U, D, c, t, ans;
int arr[1000001] = {0,};

void solve(void) {
  arr[S] = 1;
  ans = 0;
  queue<int> q;
  q.push(S);
  while(!q.empty()) {
    int size = q.size();
    while (size--) {
      c = q.front();
      if (c == G) {
        cout << ans;
        return;
      }
      q.pop();
      t = c + U;
      if (t <= F && !arr[t]) {
        q.push(t);
        arr[t] = 1;
      }
      t = c - D;
      if (t >= 1 && !arr[t]) {
        q.push(t);
        arr[t] = 1;
      }
    }
    ans++;
  }
  cout << "use the stairs";
}

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> F >> S >> G >> U >> D;
    solve();
}