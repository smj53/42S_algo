#include <iostream>
#include <algorithm>
using namespace std;
int N;
char map[6561][6561];

void print(int r, int c, int len, bool isWS) {
    if (len == 1) {
        map[r][c] = isWS ? ' ' : '*';
        return;
    }
    len /= 3;
    int rr = r;
    for (int i=0; i<3; i++) {
        int cc = c;
        for (int j=0; j<3; j++) {
            print(rr, cc, len, isWS || i == 1 && j == 1);
            cc += len;
        }
        rr += len;
    }
}

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N;
    print(0, 0, N, false);
    for(int i=0; i<N; i++) {
        for (int j=0;j<N;j++) {
            cout << map[i][j];
        }
        cout << "\n";
    }
}