#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    int arr[N], ans[N];
    for (int i=0; i<N;i++)
        cin >> arr[i];
    stack<int> s;
    s.push(-1);
    for (int i=N-1; i>=0; i--) {
        while (s.top() != -1 && s.top() <= arr[i]) {
            s.pop();
        }
        ans[i] = s.top();
        s.push(arr[i]);
    }
    for(int i=0; i<N;i++)
        cout << ans[i] << " ";
}