#include <iostream>
#include <algorithm>
using namespace std;
int N, map[64][64];

bool isAll(int r, int c, int len) {
    for (int i=r;i<r+len; i++) {
        for (int j=c;j<c+len;j++) {
            if (map[r][c] != map[i][j]) {
                return false;
            }
        }
    }
    return true;
}

void print(int r, int c, int len) {
    if (isAll(r, c, len)) {
        cout << map[r][c];
        return;
    }
    len /= 2;
    cout << "(";
    print(r, c, len);
    print(r, c+len, len);
    print(r+len, c, len);
    print(r+len, c+len, len);
    cout << ")";
}

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N;
    for (int i=0; i<N; i++) {
        string in;
        cin >> in;
        for (int j=0;j<N; j++) {
            map[i][j] = in[j] - '0';
        }
    }
    print(0, 0, N);
}