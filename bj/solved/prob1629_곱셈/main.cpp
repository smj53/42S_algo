#include <iostream>
#include <algorithm>
using namespace std;
int A, B, C;

int mul(int A, int B) {
    long ans = 1;
    if (B == 0)
        return ans % C;
    if (B % 2 == 1)
        ans = (ans * A) % C;
    long t = mul(A, B / 2) % C;
    return (t * t % C) * ans % C;
}

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> A >> B >> C;
    cout << mul(A, B);
}