#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    stack<pair<int, int> > s;
    int N;
    cin >> N;
    int arr[N];
    long ans[N];
    for(int i=0; i<N; i++) {
        cin >> arr[i];
        ans[i] = 0;
    }
    long sum = 0; // 8만 개라 최대 32억개 정도는 될 수 있을듯
    s.push(make_pair(1000000001, 0));
    for (int i=N-1; i>=0; i--) {
        while (s.top().first < arr[i]) {
            ans[i] += ans[s.top().second] + 1;
            s.pop();
        }
        sum += ans[i];
        s.push(make_pair(arr[i], i));
    }
    cout << sum;
}