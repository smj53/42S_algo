#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;
int main(void) {
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
    int N, t, ans;
    stack<pair<int, int> > s;
    cin >> N;
    for(int i=1; i<=N; i++) {
        cin >> t;
        while (!s.empty() && s.top().first < t) {
            s.pop();
        }
        if (!s.empty()) {
            ans = s.top().second;
        } else {
            ans = 0;
        }
        cout << ans << " ";
        s.push(make_pair(t, i));
    }
}