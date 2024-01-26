#include <iostream>

using namespace std;

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    int N, X, t;
    cin >> N >> X;
    while (N--) {
        cin >> t;
        if (t < X)
            cout << t << " ";
    }
}