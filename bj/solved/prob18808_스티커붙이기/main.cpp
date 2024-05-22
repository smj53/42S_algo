#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M, K, map[40][40], r, c;
int sticker[10][10];

int count1() {
    int ret = 0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (map[i][j] == 1)
                ret++;
        }
    }
    return ret;
}

int check(int ci, int cj) {
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            if (map[ci + i][cj + j] & sticker[i][j])
                return 0;
        }
    }
    return 1;
}

pair<int, int> canAttach() {
    for (int i=0; i<=N-r; i++) {
        for (int j=0; j<=M-c; j++) {
            if (check(i, j))
                return make_pair(i, j);
        }
    }
    return make_pair(-1, -1);
}

int attach() {
    pair<int, int> pos = canAttach();
    if (pos.first == -1)
        return 0;
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            map[pos.first + i][pos.second + j] |= sticker[i][j];
        }
    }
    return 1;
}

void printSticker() {
    cout << "\n============< sticker >===============\n";
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            cout << sticker[i][j] << " ";
        }
        cout << endl;
    }
}

void rotate() {
    int nr = c, nc = r, ns[10][10];
    for (int i=0; i<c; i++) {
        for (int j=r-1; j>=0; j--) {
            ns[i][j] = sticker[r-j-1][i];
        }
    }
    r = nr;
    c = nc;
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            sticker[i][j] = ns[i][j];
        }
    }
}

void printMap() {
    cout << "\n============< Map >===============\n";
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
}

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N >> M >> K;
    while (K--) {
        cin >> r >> c;
        for (int i=0; i<r; i++) {
            for (int j=0; j<c; j++) {
                cin >> sticker[i][j];
            }
        }
        for (int i=0; i<4; i++) {
            if (attach()) {
                break;
            }
            rotate();
        }
    }
    cout << count1();
}