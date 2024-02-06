#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

void password(string in) {
    list<char> lst;
    list<char>::iterator c;
    char op;
    c = lst.begin();
    for (int i=0; i<in.length(); i++) {
        op = in[i];
        if (op == '<') {
            if (c != lst.begin())
                c--;
        } else if (op == '>') {
            if (c != lst.end())
                c++;
        } else if (op == '-') {
            if (c != lst.begin()) {
                c--;
                c = lst.erase(c);
            }
        } else {
            lst.insert(c, op);
        }
    }
    for (auto i = lst.begin(); i != lst.end(); i++) {
        cout << *i;
    }
    cout << "\n";
}

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    int T;
    string in;
    cin >> T;
    cin.ignore();
    while (T--) {
        getline(cin, in);
        password(in);
    }
}