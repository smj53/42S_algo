#include <iostream>
#include <algorithm>
#include <stack>
#include <set>
using namespace std;

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    long N, ans;
    int t, m;
    stack<pair<int, long> > s;
    cin >> N;
    int arr[N];
    ans = 0;
    for(int i=0; i<N; i++) {
        cin >> arr[i];
    }
    for (int i=0; i<N; i++) {
        long same = 1;
        while (!s.empty() && s.top().first <= arr[i]) {
            if (s.top().first == arr[i])
                same += s.top().second;
            else
                ans += s.top().second * (s.top().second - 1) / 2;
            s.pop();
        }
        if (!s.empty())
            ans++;
        s.push(make_pair(arr[i], same));
    }
    while (!s.empty()) { ans += s.top().second * (s.top().second - 1) / 2; s.pop(); }
    for (int i=N-1; i>=0; i--) {
        while (!s.empty() && s.top().first <= arr[i]) {
            s.pop();
        }
        if (!s.empty())
            ans++;
        s.push(make_pair(arr[i], 0));
    }
    cout << ans;
}