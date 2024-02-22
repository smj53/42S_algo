#include <iostream>
#include <algorithm>
using namespace std;
int N, map[2187][2187], arr[3];

bool is_all(int r, int c, int len) {
    int t = map[r][c];
    for (int i=r; i<r+len; i++) {
        for (int j=c; j<c+len; j++) {
            if (t != map[i][j])
                return false;
        }
    }
    return true;
}

void find(int r, int c, int len) {
    if (is_all(r, c, len) || len == 0) {
        arr[map[r][c] + 1]++;
        return;
    }
    len /= 3;
    int rr = r;
    for (int i=0; i<3; i++) {
        int rc = c;
        for (int j=0; j<3; j++) {
            find(rr, rc, len);
            rc += len;
        }
        rr += len;
    }
}

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> map[i][j];
        }
    }
    find(0, 0, N);
    for (int i=0; i<3; i++) {
        cout << arr[i] << "\n";
    }
}