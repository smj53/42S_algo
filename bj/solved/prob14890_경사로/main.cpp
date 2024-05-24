#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, L, ans;
int map[100][100];

template<typename T>
void printVec(vector<T> &t) {
	cout << "vec: ";
	for (T i : t) {
		cout << i << ", ";
	}
	cout << endl;
}

bool check(vector<int> &vec, vector<bool> &isUp) {
	// printVec(vec);
	// printVec(isUp);
	for (int j=0; j<vec.size()-1; j++) {
		if (isUp[j]) {
			if (vec[j] < L)
				return false;
			vec[j] -= L;
		} else {
			if (vec[j+1] < L) {
				return false;
			}
			vec[j+1] -= L;
		}
	}
	return true;
}

void solve() {
	for (int i=0; i<N; i++) {
		int cnt = 1;
		bool flag = true;
		vector<int> vec;
		vector<bool> isUp;
		for (int j=0; j<N-1; j++) {
			if (map[i][j] != map[i][j+1]) {
				if (abs(map[i][j] - map[i][j+1]) > 1) {
					flag = false;
					break;
				}
				vec.push_back(cnt);
				isUp.push_back(map[i][j] < map[i][j+1]);
				cnt = 1;
			} else
				cnt++;
		}
		vec.push_back(cnt);
		if (flag && check(vec, isUp)) {
			// cout << i << endl;
			ans++;
		}
	}
	for (int i=0; i<N; i++) {
		int cnt = 1;
		bool flag = true;
		vector<int> vec;
		vector<bool> isUp;
		for (int j=0; j<N-1; j++) {
			if (map[j][i] != map[j+1][i]) {
				if (abs(map[j][i] - map[j+1][i]) > 1) {
					flag = false;
					break;
				}
				vec.push_back(cnt);
				isUp.push_back(map[j][i] < map[j+1][i]);
				cnt = 1;
			} else cnt++;
		}
		vec.push_back(cnt);
		if (flag && check(vec, isUp)) {
			// cout << i << endl;
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
	solve();
	cout << ans;
}