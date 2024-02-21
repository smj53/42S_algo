#include <iostream>
#include <algorithm>
using namespace std;
int N, R, C, cnt;

int rec(int r, int c, int len) {
    if (len == 0) {
        if (r == R && c == C) {
            cout << cnt;
        }
        return r == R && c == C;
    } 
    len /= 2;
    int rr = r + len;
    int rc = c + len;
    if (rr > R && rc > C) {
        return rec(r, c, len);
    } else
        cnt += len * len;
    if (rr > R && rc <= C) {
        return rec(r, rc, len);
    } else
        cnt += len * len;
    if (rr <= R && rc > C) {
        return rec(rr, c, len);
    } else
        cnt += len * len;
    return rec(rr, rc, len);
}

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N >> R >> C;
    rec(0, 0, 1<<N);
}