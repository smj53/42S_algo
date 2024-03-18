#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int N, ans, v[15];

bool check(int c, int r) {
    for (int i=1; i<c; i++) {
        if (v[i] == r || c - i == abs(v[i] - r)) {
            return false;
        }
    }
    return true;
}

int solve(int col) {
    int ret = 0;
    if (col > N) {
        return 1;
    }
    for (int i=1; i<=N; i++) {
        v[col] = i;
        if (check(col, i))
            ret += solve(col + 1);
        v[col] = 0;
    }
    return ret;
}

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N;
    cout << solve(1);
}