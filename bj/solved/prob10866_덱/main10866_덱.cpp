#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

class deque {
public:
    int f, r, s;
    int *arr;

    deque (int N) {
        f = r = 0;
        s = N + 1;
        arr = (int *)malloc(sizeof(int) * s);
    }

    int empty() {
        return f == r;
    }
    
    void push_front(int x) {
        arr[f] = x;
        f = (f - 1 + s) % s;
    }

    void push_back(int x) {
        r = (r + 1) % s;
        arr[r] = x;
    }

    int pop_front() {
        if (empty()) {
            return -1;
        }
        f = (f + 1) % s;
        return (arr[f]);
    }

    int pop_back() {
        if (empty()) {
            return -1;
        }
        int t = arr[r];
        r = (r - 1 + s) % s;
        return t;
    }

    int size() {
        int diff = r - f;
        if (diff < 0)
            return s + diff;
        return (diff);
    }

    int front() {
        if (empty())
            return -1;
        return arr[(f + 1) % s];
    }

    int back() {
        if (empty())
            return -1;
        return arr[r];
    }
};

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    int N, t;
    string op;
    cin >> N;
    deque d = deque(N);
    while (N--) {
        cin >> op;
        if (op == "push_back") {
            cin >> t;
            d.push_back(t);
        } else if (op == "push_front") {
            cin >> t;
            d.push_front(t);
        } else if (op == "pop_front") {
            cout << d.pop_front() << "\n";
        } else if (op == "pop_back") {
            cout << d.pop_back() << "\n";
        } else if (op == "size") {
            cout << d.size() << "\n";
        } else if (op == "front") {
            cout << d.front() << "\n";
        } else if (op == "back") {
            cout << d.back() << "\n";
        } else if (op == "empty") {
            cout << d.empty() << "\n";
        }
    }
}