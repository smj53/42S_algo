#include <iostream>
#include <algorithm>
using namespace std;
int N, arr[128][128], w, b;

bool isAll(int r, int c, int len, int cur) {
    for(int i=r;i<r+len;i++) {
        for (int j=c;j<c+len;j++) {
            if (arr[i][j] != cur)
                return false;
        }
    }
    return true;
}

void count(int r, int c, int len) {
    if (len == 0 || isAll(r, c, len, arr[r][c])) {
        if (arr[r][c] == 0) w++;
        else b++;
        return;
    }
    len /= 2;
    count(r, c, len);
    count(r, c+len, len);
    count(r+len, c, len);
    count(r+len, c+len, len);
}

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N;
    for (int i=0; i<N;i++) {
        for (int j=0; j<N; j++){
            cin >> arr[i][j];
        }
    }
    count(0, 0, N);
    cout << w << "\n" << b;
}