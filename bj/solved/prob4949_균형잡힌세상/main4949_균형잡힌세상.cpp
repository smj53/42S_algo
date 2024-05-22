#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int check(string str) {
    stack<char> s;
    string openp = "([";
    string closep = ")]";
    int p;
    for (int i=0; i<str.length(); i++) {
        if ((p = openp.find(str[i])) != std::string::npos) {
            s.push(closep[p]);
        } else if ((p = closep.find(str[i])) != std::string::npos) {
            if (s.empty() || s.top() != str[i]) {
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
    getline(cin, in);
    while (in != ".") {
        cout << (check(in) ? "yes" : "no") << "\n";
        getline(cin, in);
    }
}