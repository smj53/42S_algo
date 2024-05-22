#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

int count_front(deque<int> q, int n) {
  int t = 0, cnt = 0;
  while (q.front() != n) {
    t = q.front();
    q.pop_front();
    q.push_back(t);
    cnt++;
  }
  return cnt;
}

void move_front(deque<int>& q, int n) {
  int t = 0;
  while (q.front() != n) {
    t = q.front();
    q.pop_front();
    q.push_back(t);
  }
  q.pop_front();
}

int count_rear(deque<int> q, int n) {
  int t = 0, cnt = 0;
  while (q.front() != n) {
    t = q.back();
    q.pop_back();
    q.push_front(t);
    cnt++;
  }
  return cnt;
}

void move_rear(deque<int>& q, int n) {
  int t = 0;
  while (q.front() != n) {
    t = q.back();
    q.pop_back();
    q.push_front(t);
  }
  q.pop_front();
}

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    deque<int> q;
    int N, M, t, ans = 0;
    cin >> N >> M;
    int arr[N];
    for (int i = 1; i <= N; i++) {
      q.push_back(i);
    }
    while (M--) {
      cin >> t;
      int front = count_front(q, t);
      int rear = count_rear(q, t);
      if (front <= rear) {
        move_front(q, t);
        ans += front;
      } else {
        move_rear(q, t);
        ans += rear;
      }
    }
    cout << ans;
}