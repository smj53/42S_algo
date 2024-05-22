#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    int N;
    queue<int> q;
    cin >> N;
    for(int i=1; i<=N;i++) {
        q.push(i);
    }
    while (q.size() > 1) {
        q.pop();
        int t = q.front();
        q.pop();
        q.push(t);
    }
    cout << q.front();
}