#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <queue>
using namespace std;
int N = 5, arr[5][5];
int d[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
unordered_set<int> se;

int find(int n, int v, int s) {
    if (n - s > 3)
        return 0;
    if (n == 7) {
        se.insert(v);
        return 1;
    }
    // cout << "==========" << n << endl;
    // cout << bitset<25>(v).to_string() << endl;
    int ret = 0;
    for (int i=0; i<25; i++) {
        if (v & 1 << i)
            continue;
        int r = i / N;
        int c = i % N;
        int hasAdj = 0;
        for (int j=0; j<4; j++) {
            int nr = r + d[j][0];
            int nc = c + d[j][1];
            int np = nr * N + nc;
            // cout << "nr, nc, np:: " << nr << ", " << nc << ", " << np << endl;
            // cout << "np:: " << bitset<25>(1 << np).to_string() << endl;
            if (n == 0 || (nr>=0 && nr<N && nc>=0 && nc<N && (v & 1<<np))) {
                hasAdj = 1;
                break;
            }
        }
        if (hasAdj)
            ret += find(n + 1, v | 1 << i, s + (arr[r][c] == 'S' ? 1 : 0));
    }
    return ret;
}

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    for (int i=0;i<N;i++) {
        string in;
        cin >> in;
        for (int j=0;j<N;j++) {
            arr[i][j] = in[j];
        }
    }
    find(0, 0, 0);
    cout << se.size();
}