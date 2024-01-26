#include <iostream>
#include <algorithm>
#include <stack>
#include <sstream>
using namespace std;

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    stack<int> s;
    int n, t, num;
    stringstream ss;
    cin >> n;
    num = 1;

    for (int i=0; i<n; i++) {
        cin >> t;
        while (num <= t && num <= n) {
            s.push(num++);
            ss << "+\n";
        }
        if (s.empty() || s.top() != t)
        {
            ss.str("");
            ss << "NO";
            break;
        }
        s.pop();
        ss << "-\n";
    }
    cout << ss.str();
}