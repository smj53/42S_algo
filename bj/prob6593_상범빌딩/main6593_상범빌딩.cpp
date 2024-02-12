#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;

int d[6][3] = {{1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1}};
int L, R, C, step;
tuple<int, int, int> s, e;
string in;
int arr[30][30][30];

void solve() {
  queue<tuple<int, int, int> > q;
  arr[get<0>(s)][get<1>(s)][get<2>(s)] = '#';
  q.push(s);
  step = 0;
  while (!q.empty()) {
    int size = q.size();
    while (size--) {
      tuple<int, int, int> t = q.front();
      q.pop();
      if (get<0>(t) == get<0>(e) && get<1>(t) == get<1>(e) && get<2>(t) == get<2>(e)) {
        cout << "Escaped in " << step << " minute(s).\n";
        return;
      }
      for (int i = 0; i < 6; i++) {
        int ni = get<0>(t) + d[i][0];
        int nj = get<1>(t) + d[i][1];
        int nk = get<2>(t) + d[i][2];
        if (ni<0 || ni>=L || nj<0 || nj>=R || nk<0 || nk>=C || arr[ni][nj][nk] == '#')
          continue;
        q.push(make_tuple(ni, nj, nk));
        arr[ni][nj][nk] = '#';
      }
    }
    step++;
  }
  cout << "Trapped!\n";
}

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    while (1) {
      cin >> L >> R >> C;
      if (L == 0)
        break;
      for (int i = 0; i < L; i++) {
        for (int j = 0; j < R; j++) {
          cin.ignore();
          cin >> in;
          for (int k = 0; k < C; k++) {
            arr[i][j][k] = in[k];
            if (in[k] == 'S') {
              s = make_tuple(i, j, k);
            } else if (in[k] == 'E') {
              e = make_tuple(i, j, k);
            }
          }
        }
      }
      solve();
    }
}