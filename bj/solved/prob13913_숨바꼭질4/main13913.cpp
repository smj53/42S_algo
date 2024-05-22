#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

int N, K, arr[100001], p[100001];

void print_order() {
    stack<int> s;
    do {
        s.push(N);
        N = p[N];
    } while (N != -1);
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
}

void solve() {
    fill(arr, arr+100001, -1);
    fill(p, p+100001, -1);
    int step = 0;
    queue<int> q;
    q.push(N);
    arr[N] = 0;
    while (!q.empty()) {
        N = q.front();
        if (N == K) {
            cout << arr[N] << "\n";
            print_order();
            return;
        }
        q.pop();
        if (N - 1 >= 0 && arr[N - 1] == -1) {
            arr[N - 1] = arr[N] + 1;
            p[N - 1] = N;
            q.push(N - 1);
        }
        if (N + 1 <= 100000 && arr[N + 1] == -1) {
            arr[N + 1] = arr[N] + 1;
            p[N + 1] = N;
            q.push(N + 1);
        }
        if (N * 2 <= 100000 && arr[N * 2] == -1) {
            arr[N * 2] = arr[N] + 1;
            p[N * 2] = N;
            q.push(N * 2);
        }
    }
}

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N >> K;
    solve();
}