#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int check(string str) {
    stack<int> s;
    int t;
    // (: -1, [: -2
    for (int i=0; i<str.length(); i++) {
        if (str[i] == '(') {
            s.push(-1);
        } else if (str[i] == '[') {
            s.push(-2);
        } else if (str[i] == ')') {
            t = 0;
            while (!s.empty() && s.top() >= 0) {
                t += s.top();
                s.pop();
            }
            if (s.empty() || s.top() == -2)
                return 0;
            if (t == 0)
                t = 1;
            s.pop();
            s.push(t * 2);
        } else {
            t = 0; 
            while (!s.empty() && s.top() >= 0) {
                t += s.top();
                s.pop();
            }
            if (s.empty() || s.top() == -1)
                return 0;
            if (t == 0)
                t = 1;
            s.pop();
            s.push(t * 3);
        }
    }
    t = 0;
    while (!s.empty() && s.top() >= 0) {
        t += s.top();
        s.pop();
    }
    if (!s.empty())
        return 0;
    return t;
}

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    string in;
    cin >> in;
    cout << check(in);
}