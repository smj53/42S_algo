#include <iostream>
#include <algorithm>
using namespace std;

int N, M, r, c, d, ans;
int map[50][50];
int delta[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N >> M >> r >> c >> d;
	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			cin >> map[i][j];
		}
	}
	while (true) {
		// 청소
		if (map[r][c] != 2) {
			map[r][c] = 2;
			ans++;
		}
		// 주변 4칸 확인
		bool hasUncleaned = false;
		for (int i=0; i<4; i++) {
			int nr = r + delta[i][0];
			int nc = c + delta[i][1];
			if (map[nr][nc] != 0)
				continue;
			hasUncleaned = true;
			break;
		}
		// 청소되지 않은 빈 칸이 없는 경우
		if (!hasUncleaned) {
			// 방향 유지하고 한칸 후진 가능하면 후진
			int nr = r + delta[(d + 2) % 4][0];
			int nc = c + delta[(d + 2) % 4][1];
			// 뒷칸이 벽이면 작동 중지
			if (map[nr][nc] == 1)
				break;
			r = nr;
			c = nc;
			continue;
		}
		// 회전 후 앞쪽 칸 확인
		d = (d + 3) % 4;
		int nr = r + delta[d][0];
		int nc = c + delta[d][1];
		if (map[nr][nc] == 0) {
			// 청소되지 않은 빈칸인 경우 전진
			r = nr;
			c = nc;
		}
	}
	cout << ans;
}