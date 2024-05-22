#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int check(string str) {
    stack<char> s;
    int p;
    for (int i=0; i<str.length(); i++) {
        if (!s.empty() && s.top() == str[i]) {
            s.pop();
        } else {
            s.push(str[i]);
        }
    }
    return s.empty();
}

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    int N, cnt;
    string in;
    cin >> N;
    cin.ignore();
    cnt = 0;
    while (N--) {
        getline(cin, in);
        if (check(in)) {
            cnt++;
        }
    }
    cout << cnt;
}