#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    int N, K;
    queue<int> q;
    cin >> N >> K;
    for (int i = 1; i<=N; i++) {
        q.push(i);
    }
    cout << "<";
    while (!q.empty()) {
        int k = (K - 1) % q.size();
        while (k--) {
            q.push(q.front());
            q.pop();
        }
        if (q.size() != N)
            cout << ", ";
        cout << q.front();
        q.pop();
    }
    cout << ">";
}