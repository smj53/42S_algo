#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int check(string str) {
    stack<char> s;
    int p;
    for (int i=0; i<str.length(); i++) {
        if (str[i] == '(') {
            s.push('(');
        } else {
            if (s.empty()) {
                return 0;
            }
            s.pop();
        }
    }
    return s.empty();
}

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    string in;
    int N;
    cin >> N;
    while (N--) {
        cin >> in;
        cout << (check(in) ? "YES" : "NO") << "\n";
    }
}