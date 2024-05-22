#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N, arr[100][100], copy_arr[100][100];
int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void print(int m[100][100]) {
    cout << "=======================\n";
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
}

void set_num(int ci, int cj, int n) {
    queue<int> q;
    q.push(ci * N + cj);
    arr[ci][cj] = n;
    while (!q.empty()) {
        ci = q.front() / N;
        cj = q.front() % N;
        q.pop();
        for (int i=0; i<4; i++) {
            int ni = ci + d[i][0];
            int nj = cj + d[i][1];
            if (ni<0 || ni>=N || nj<0 || nj>=N || arr[ni][nj] == 0 || arr[ni][nj] == n)
                continue;
            q.push(ni * N + nj);
            arr[ni][nj] = n;
        }
    }
}

void copy() {
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            copy_arr[i][j] = arr[i][j];
        }
    }
}

void get_starts(int ci, int cj, queue<int> &q) {
    int n = arr[ci][cj];
    queue<int> qq;
    int v[100][100] = {0,};
    qq.push(ci * N + cj);
    v[ci][cj] = 1;
    while (!qq.empty()) {
        ci = qq.front() / N;
        cj = qq.front() % N;
        qq.pop();
        for (int i=0; i<4; i++) {
            int ni = ci + d[i][0];
            int nj = cj + d[i][1];
            if (ni<0 || ni>=N || nj<0 || nj>=N || v[ni][nj])
                continue;
            if (arr[ni][nj] == 0)
                q.push(ni * N + nj);
            else if (arr[ni][nj] == n)
                qq.push(ni * N + nj);
            v[ni][nj] = 1;
        }
    }
}

int set_bridge(int ci, int cj, int n) {
    queue<int> q;
    copy();
    int cnt = 1;
    get_starts(ci, cj, q);
    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            ci = q.front() / N;
            cj = q.front() % N;
            q.pop();
            for (int i=0; i<4; i++) {
                int ni = ci + d[i][0];
                int nj = cj + d[i][1];
                if (ni<0 || ni>=N || nj<0 || nj>=N || copy_arr[ni][nj] == 1)
                    continue;
                if (copy_arr[ni][nj] != 0 && copy_arr[ni][nj] != n) {
                    return cnt;
                }
                q.push(ni * N + nj);
                copy_arr[ni][nj] = 1;
            }
        }
        cnt++;
    }
    return 100;
}


int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> arr[i][j];
        }
    }
    int n = 2;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (arr[i][j] == 1) {
                // bfs 돌면서 대륙 번호 저장
                set_num(i, j, n++);
            }
        }
    }
    int ans = 100000;
    int visited[10002] = {0, };
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (arr[i][j] != 0 && !visited[arr[i][j]]) {
                visited[arr[i][j]] = 1;
                // 해당 대륙 주변 0에서부터 bfs해서 다른 대륙까지 도달할 때까지 반복
                ans = min(ans, set_bridge(i, j, arr[i][j]));
            }
        }
    }
    cout << ans;
}