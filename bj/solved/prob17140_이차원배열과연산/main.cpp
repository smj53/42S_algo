#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int R, C, r, c, k, A[100][100], maxCnt;
pair<int, int> cnt[101];

void printArr() {
	cout << R << ", " << C << "======================\n";
	for (int i=0;i<R; i++) {
		for (int j=0; j<C; j++) {
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
}

void clear(int max) {
	for (int i=0; i<101; i++) {
		cnt[i].first = 0;
		cnt[i].second = i;
	}
}

void op(vector<int> &vec, int max) {
	clear(max);
	for (int i=0; i<vec.size(); i++) {
		cnt[vec[i]].first++;
	}
	sort(cnt, cnt+101);
}

void rowOp() {
	maxCnt = 0;
	for (int i=0; i<R; i++) {
		vector<int> tmp;
		int rowCnt = 0;
		for (int j=0; j<C; j++) {
			tmp.push_back(A[i][j]);
		}
		op(tmp, C);
		for (int j=0; j<101; j++) {
			if (cnt[j].first == 0 || cnt[j].second == 0) continue;
			if (rowCnt > 100) break;
			A[i][rowCnt++] = cnt[j].second;
			A[i][rowCnt++] = cnt[j].first;
		}
		maxCnt = max(maxCnt, rowCnt);
		for (int j=rowCnt; j<100; j++) A[i][j] = 0;
	}
	C = maxCnt;
}

void colOp() {
	maxCnt = 0;
	for (int i=0; i<C; i++) {
		vector<int> tmp;
		int colCnt = 0;
		for (int j=0; j<R; j++) {
			tmp.push_back(A[j][i]);
		}
		op(tmp, C);
		for (int j=0; j<101; j++) {
			if (cnt[j].first == 0 || cnt[j].second == 0) continue;
			if (colCnt > 100) break;
			A[colCnt++][i] = cnt[j].second;
			A[colCnt++][i] = cnt[j].first;
		}
		maxCnt = max(maxCnt, colCnt);
		for (int j=colCnt; j<100; j++) A[j][i] = 0;
	}
	R = maxCnt;
}

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	R = C = 3;
    cin >> r >> c >> k;
	r--; c--;
	for (int i=0; i<3; i++) {
		for (int j=0; j<3; j++) {
			cin >> A[i][j];
		}
	}
	int ans = -1;
	for (int t=0; t<=100; t++) {
		if (r < R && c < C && A[r][c] == k) {
			ans = t;
			break;
		}
		if (R >= C) rowOp();
		else colOp();
		// printArr();
	}
	cout << ans;
}