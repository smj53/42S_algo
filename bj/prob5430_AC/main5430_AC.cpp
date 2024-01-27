#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdlib>
using namespace std;
class deque {
public:
    int f, r, s, is_r;
    int *arr;

    deque (int N) {
        f = r = is_r = 0;
        s = N + 1;
        arr = (int *)malloc(sizeof(int) * s);
    }

    int empty() {
        return f == r;
    }

    void R() {
      is_r ^= 1;
    }

    int D() {
      if (is_r) {
        return pop_back();
      } else {
        return pop_front();
      }
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

    void clear() {
      f = r = is_r = 0;
    }
};
int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    deque q = deque(100000);
    int T;
    cin >> T;
    while (T--) {
      string op, out, tok;
      int N, t;
      cin >> op >> N >> out;
      out = out.substr(1, out.size() - 2);
      istringstream iss(out);
      while (N--) {
        getline(iss, tok, ',');
        q.push_back(atoi(tok.c_str()));
      }
      for (int i = 0; i < op.size(); i++) {
        if (op.at(i) == 'R') {
          q.R();
        } else {
          int t = q.D();
          if (t == -1) {
            out = "error";
            break;
          }
        }
      }
      if (out != "error") {
        out = "[";
        int is_first = 1;
        while (!q.empty()) {
          if (!is_first)
            out += ",";
          out += to_string(q.D());
          is_first = 0;
        }
        out += "]";
      }
      cout << out << "\n";
      q.clear();
    }
}