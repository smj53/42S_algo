#include <iostream>
#include <algorithm>
using namespace std;

long N, M;

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N >> M;
	if (N <= M) {
        cout << 2 * (N-1) << "\n";
        cout << N/2+1 << " ";
        if (N % 2) cout << M-1-(N-1)/2 + 1;
        else cout << (N-1)/2 + 1;
    } else {
        cout << 2 * (M-1)+1<< "\n";
        if (M % 2) cout << N-M/2;
        else cout << M/2+1;
		cout << " " << (M-1)/2+1;
    }
}