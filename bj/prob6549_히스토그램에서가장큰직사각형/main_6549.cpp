#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    while (n) {
        long ans = n;
        long arr[n], right[n], left[n];
        stack<int> s;
        for (int i=0; i<n; i++) {
            cin >> arr[i];
            if (!arr[i]) ans = 0; // 어이 없네 0 들어와도 1 찍어서 문제였음
        }
        for (int i=0; i<n; i++) {
            left[i] = 0;
            while (!s.empty() && arr[s.top()] >= arr[i])
            {
                left[i] += left[s.top()] + 1;
                s.pop();
            }
            s.push(i);
        }
        while (!s.empty()) s.pop();
        for (int i=n-1; i>=0; i--) {
            right[i] = 0;
            while (!s.empty() && arr[s.top()] >= arr[i])
            {
                right[i] += right[s.top()] + 1;
                s.pop();
            }
            s.push(i);
        }
        for (int i=0; i<n; i++) {
            ans = max(ans, (left[i] + right[i] + 1) * arr[i]);
        }
        cout << ans << "\n";
        cin >> n;
    }
}