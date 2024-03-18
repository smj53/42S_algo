#include <iostream>
#include <algorithm>
using namespace std;
int N, M, arr[8], selected[8];
// FIXME: bj15663 N과 M 9
void comb(int cnt, int v) {
    if (cnt == M) {
        for (int i=0; i<M; i++)
            cout << arr[selected[i]] << " ";
        cout << "\n";
        return;
    }
    int tmp = 0;
    for (int i=0; i<N; i++) {
        if (v & 1 << i || tmp == arr[i])
            continue;
        selected[cnt] = i;
        tmp = arr[i];
        comb(cnt + 1, v | 1 << i);
    }
}

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N >> M;
    for (int i=0; i<N; i++)
        cin >> arr[i];
    sort(&arr[0], &arr[N]);
    comb(0, 0);
}