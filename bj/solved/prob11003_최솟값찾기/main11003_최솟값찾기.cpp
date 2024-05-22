#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

// deque
int main(void) {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
  int N, L, t;
  cin >> N >> L;
  deque<pair<int, int> > q;
  for(int i=0; i<N; i++) {
    cin >> t;
    while (!q.empty() && q.back().first >= t) {
      q.pop_back();
    }
    while (!q.empty() && i - q.front().second >= L) {
      q.pop_front();
    }
    q.push_back(make_pair(t, i));
    cout << q.front().first << " ";
  }
}