#include <iostream>
#include <algorithm>
using namespace std;

// FIXME: bj14956 philosopher's walk 다시 풀기

int N, M;
pair<int, int> t;

pair<int, int> find(int n, int m) {
    if (n == 2) {
        switch (m) {
            case 1:
                return {1, 1};
            case 2:
                return {1, 2};
            case 3:
                return {2, 2};
            case 4:
                return {2, 1};
        }
        return {};
    }
    n /= 2;
    int sec = n * n;
    if (m <= sec) {
        t = find(n, m);
        return {t.second, t.first};
    } else if (m <= 2 * sec) {
        t = find(n, m - sec);
        return {t.first, n + t.second};
    } else if (m <= 3 * sec) {
        t = find(n, m - 2 * sec);
        return {n + t.first, n + t.second};
    } else {
        t = find(n, m - 3 * sec);
        return {2 * n - t.second + 1, n - t.first + 1};
    }
}

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N >> M;
    t = find(N, M);
    cout << t.first << " " << t.second;
}