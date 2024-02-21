#include <iostream>
#include <algorithm>
using namespace std;
int N, K, arr[10];
int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N >> K;
    for (int i=0; i<N; i++) {
        cin >> arr[i];
    }
    int ans = 0, i = N-1;
    while (K) {
        ans += K / arr[i];
        K %= arr[i];
        i--;
    }
    cout << ans;
}