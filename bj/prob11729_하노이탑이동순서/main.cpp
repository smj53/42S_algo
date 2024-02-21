#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;

stringstream ss;
int N, K, ans;

void hanoi(int from, int to, int o, int n) {
    if (n == 1) {
        ans++;
        ss << from << " " << to << "\n";
        return;
    }
    hanoi(from, o, to, n - 1);
    ans++;
    ss << from << " " << to << "\n";
    hanoi(o, to, from, n - 1);
}

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N;
    hanoi(1, 3, 2, N);
    cout << ans << "\n";
    cout << ss.str();
}