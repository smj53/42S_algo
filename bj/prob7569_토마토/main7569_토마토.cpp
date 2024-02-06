#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int N, M, H;
int d[6][3] = {{0, 1, 0}, {1, 0, 0}, {-1, 0, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1}};
int arr[100][100][100];

class Pos {
    public:
    int x, y, z;
    Pos(int x, int y, int z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }
};

void print_arr() {
    cout << "print arr =----------------\n";
    for (int k=0; k<H; k++) {
        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++) {
                cout << arr[i][j][k];
            }
            cout << endl;
        }
        cout << "==================\n";
    }
}

int is_all_riped() {
    for (int k=0; k<H; k++)
        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++) {
                if (!arr[i][j][k])
                    return 0;
            }
        }
    return 1;
}

int get_day() {
    int ci, cj, cp, day = 0, size, changed;
    queue<Pos> q;
    for (int k=0; k<H; k++)
        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++) {
                if (arr[i][j][k] == 1)
                    q.push(Pos(i, j, k));
            }
        }
    while (!q.empty() && !is_all_riped()) {
        size = q.size();
        changed = 0;
        while (size--) {
            Pos t = q.front();
            q.pop();
            for (int i=0; i<6; i++) {
                int ni = t.x + d[i][0];
                int nj = t.y + d[i][1];
                int nk = t.z + d[i][2];
                if (ni<0 || ni>=N || nj<0 || nj>=M || nk<0 || nk>=H
                    || arr[ni][nj][nk] == -1 || arr[ni][nj][nk] == 1)
                    continue;
                arr[ni][nj][nk] = 1;
                changed = 1;
                q.push(Pos(ni, nj, nk));
            }
        }
        day++;
        if (!changed)
            return -1;
    }
    if (is_all_riped())
        return day;
    return -1;
}

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> M >> N >> H;
    for (int k=0; k<H; k++)
        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++) {
                cin >> arr[i][j][k];
            }
        }
    cout << get_day();
}