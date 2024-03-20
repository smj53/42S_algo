#include <iostream>
#include <algorithm>
using namespace std;

// FIXME: bj16987 계란으로 계란치기

int N, S[8], W[8], ans;

void f(int cnt, int sum) {
    if (cnt == N) {
        ans = max(ans, sum);
        return;
    }
    if (S[cnt] <= 0 || sum == N - 1)
        return f(cnt + 1, sum);
    for (int i=0; i<N; i++) {
        if (S[i] <= 0 || i == cnt) {
            continue;
        }
        S[cnt] -= W[i];
        S[i] -= W[cnt];
        f(cnt + 1, sum + (S[i] <= 0) + (S[cnt] <= 0));
        S[cnt] += W[i];
        S[i] += W[cnt];
    }
    return;
}

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> S[i] >> W[i];
    }
    f(0, 0);
    cout << ans;
}