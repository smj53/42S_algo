#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int main(void) {
    int K, t;
    stack<int> s;
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> K;
    while (K--) {
        cin >> t;
        if (t == 0)
            s.pop();
        else
            s.push(t);
    }
    t = 0;
    while (!s.empty()) {
        t += s.top();
        s.pop();
    }
    cout << t;
}