#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> s;
int main(void) {
    int N, t;
    string op;
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N;
    while (N--) {
        cin >> op;
        if (op == "push") {
            cin >> t;
            s.push_back(t);
        } else if (op == "pop") {
            if (s.size() == 0)
                cout << -1 << "\n";
            else
            {
                cout << s.back() << "\n";
                s.pop_back();
            }
        } else if (op == "size") {
            cout << s.size() << "\n";
        } else if (op == "empty") {
            cout << (s.size() == 0 ? 1 : 0) << "\n";
        } else if (op == "top") {
            if (s.size() == 0)
                cout << -1 << "\n";
            else
                cout << s.back() << "\n";
        }
    }
}