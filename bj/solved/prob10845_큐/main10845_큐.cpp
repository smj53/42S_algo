#include <iostream>
#include <algorithm>
#include <stack>
#include <set>
#include <cstdlib>

using namespace std;

class Queue {
public:
    int f, r, s;
    int *arr;

    Queue(int N) {
        s = N + 1;
        r = f = 0;
        arr = (int *)malloc(sizeof(int) * s);
    }

    int is_empty() {
        return f == r;
    }

    void push(int x) {
        r = (r + 1) % s;
        arr[r] = x;
    }

    int size() {
        int diff = r - f;
        if (diff < 0)
            return s + diff;
        return diff;
    }

    int pop() {
        if (is_empty())
            return -1;
        f = (f + 1) % s;
        return arr[f];
    }

    int front() {
        if (is_empty())
            return -1;
        return arr[(f + 1) % s];
    }

    int back() {
        if (is_empty())
            return -1;
        return arr[r];
    }
};

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    int N, t;
    string op;
    cin >> N;
    Queue q = Queue(N);
    while (N--) {
        cin >> op;
        if (op == "push") {
            cin >> t;
            q.push(t);
        } else if (op == "pop") {
            cout << q.pop() << "\n";
        } else if (op == "size") {
            cout << q.size() << "\n";
        } else if (op == "empty") {
            cout << q.is_empty() << "\n";
        } else if (op == "front") {
            cout << q.front() << "\n";
        } else if (op == "back") {
            cout << q.back() << "\n";
        }
    }
}