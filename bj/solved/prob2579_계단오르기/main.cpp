#include <iostream>
#include <algorithm>
using namespace std;
int N, arr[301], ans[301];
int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N;
    for (int i=1; i<=N; i++)
        cin >> arr[i];
    if (N == 1) {
        cout << arr[1];
        return 0;
    }
    ans[0] = 0;
    ans[1] = arr[1];
    ans[2] = arr[1] + arr[2];
    for (int i=3; i<=N; i++) {
        ans[i] = max(ans[i-2], ans[i-3] + arr[i-1]) + arr[i];
    }
    cout << ans[N];
}