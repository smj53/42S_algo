#include <iostream>
#include <algorithm>
using namespace std;
int N, arr[3072][6143];
void drawTri(int r, int c) {
    arr[r][c] = arr[r+1][c-1] = arr[r+1][c+1] = 1;
    for (int i=-2; i<=2; i++) {
        arr[r+2][c+i] = 1;
    }
}

void draw(int r, int c, int len) {
    if (len == 3) {
        drawTri(r, c);
        return;
    }
    len /= 2;
    draw(r, c, len);
    draw(r + len, c - len, len);
    draw(r + len, c + len, len);
}

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N;
    draw(0, N - 1, N);
    for (int i=0; i<N; i++) {
        for (int j=0; j<2*N-1;j++) {
            cout << (arr[i][j] ? "*" : " ");
        }
        cout << "\n";
    }
}