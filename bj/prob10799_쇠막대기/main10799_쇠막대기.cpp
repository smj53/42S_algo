#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int check(string str) {
    int cnt = 0, tot = 0;
    char prev;
    for (int i=0; i<str.length(); i++) {
        if (str[i] == '(') {
            prev = '(';
            cnt++;
        } else {
            if (cnt == 0) {
                return 0;
            }
            cnt--;
            if (prev == '(')
                tot += cnt;
            else
                tot++;
            prev = ')';
        }
    }
    return tot;
}

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    string in;
    cin >> in;
    cout << check(in);
}