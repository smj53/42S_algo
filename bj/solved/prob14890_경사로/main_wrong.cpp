#include <iostream>
#include <algorithm>
using namespace std;

int N, L, ans;
int map[100][100];

void checkV() {
	for (int i=0; i<N; i++) {
		int cnt = 1;
		int needsCheck = false;
		int flag = true;
		for (int cur=0; cur<N-1; cur++) {
			int next = cur + 1;
			if (map[cur][i] == map[next][i]) {
				cnt++;
			} else {
				if (needsCheck) {
					if (cnt < L) {
						flag = false;
						break;
					}
					cnt = cnt - L + 1;
				}
				if (abs(map[cur][i] - map[next][i]) > 1) {
					flag = false;
					break;
				}
				else if (map[cur][i] > map[next][i]) {
					needsCheck = true;
					cnt = 1;
				} else {
					if (cnt < L) {
						flag = false;
						break;
					}
					cnt = cnt - L + 1;
				}
			}
			if (needsCheck && cnt < L)
				flag = false;
			if (flag)
				ans++;
		}
	}
}

void checkH() {
	for (int i=0; i<N; i++) {
		int cnt = 1;
		int needsCheck = false;
		int flag = true;
		for (int cur=0; cur<N-1; cur++) {
			int next = cur + 1;
			if (map[i][cur] == map[i][next]) {
				cnt++;
			} else {
				if (needsCheck) {
					if (cnt < L) {
						flag = false;
						break;
					}
					cnt = cnt - L + 1;
				}
				if (abs(map[i][cur] - map[i][next]) > 1) {
					flag = false;
					break;
				}
				else if (map[i][cur] > map[i][next]) {
					needsCheck = true;
					cnt = 1;
				} else {
					if (cnt < L) {
						flag = false;
						break;
					}
					cnt = cnt - L + 1;
				}
			}
			if (needsCheck && cnt < L)
				flag = false;
			if (flag)
				ans++;
		}
	}
}

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N >> L;
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			cin >> map[i][j];
		}
	}
	checkH();
	checkV();
	cout << ans;
}