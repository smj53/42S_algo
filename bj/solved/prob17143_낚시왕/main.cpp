#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

class Shark {
	public:
	int r, c, s, d, z;
	bool isDead;
	Shark() {}
	Shark(int r, int c, int s, int d, int z): r(r), c(c), s(s), d(d), z(z), isDead(false) {}
};

ostream &operator<<(ostream &o, Shark &s) {
	o << "[" << s.r << ", " << s.c << ", " << s.s << ", " << s.d << ", " << s.z << "]";
	return o;
}

int R, C, M, r, c, s, dd, z, ans;
int d[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
Shark *map[100][100];
vector<Shark*> sharks;

void printMap() {
	cout << "-=-----------------------\n";
	for (int i=0; i<R; i++) {
		for (int j=0; j<C; j++) {
			if (map[i][j])
				cout << *map[i][j] << " ";
			else
				cout << "[-, -, -, -, -] ";
		}
		cout << endl;
	}
}

void catchShark(int sj) {
	for (int i=0; i<R; i++) {
		if (map[i][sj] == 0 || map[i][sj]->isDead) continue;
		ans += map[i][sj]->z;
		map[i][sj]->isDead = true;
		map[i][sj] = 0;
		break;
	}
}

void moveSharks() {
	Shark *newmap[100][100];
	for (int i=0; i<R; i++) for (int j=0; j<C; j++) newmap[i][j] = 0;
	for (vector<Shark*>::iterator it=sharks.begin(); it!=sharks.end(); it++) {
		Shark *s = *it;
		if (s->isDead) continue;
		int ni = (s->r + d[s->d][0] * s->s), nj = (s->c + d[s->d][1] * s->s);
		while (ni<0 || ni>=R || nj<0 || nj>=C) {
			s->d ^= 1;
			if (ni<0) ni = -ni;
			else if (nj<0) nj = -nj;
			else if (ni>=R) ni = (R - 1) * 2 - ni;
			else if (nj>=C) nj = (C - 1) * 2 - nj;
		}
		s->r = ni;
		s->c = nj;
		cout << *s << endl;
		if (newmap[ni][nj] != 0) {
			Shark *prey = s;
			if (s->z > newmap[ni][nj]->z) {
				prey = newmap[ni][nj];
			} else s = newmap[ni][nj];
			prey->isDead = true;
		}
		newmap[ni][nj] = s;
	}
	for (int i=0; i<R; i++) for (int j=0; j<C; j++) map[i][j] = newmap[i][j];
}

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> R >> C >> M;
	for (int i=0; i<M; i++) {
		cin >> r >> c >> s >> dd >> z;
		r--; c--; dd--;
		if (dd < 2) s = s % ((R - 1) * 2);
		else s = s % ((C - 1) * 2);
		Shark *shark = new Shark(r, c, s, dd, z);
		sharks.push_back(shark);
		map[r][c] = shark;
	}
	for (int i=0; i<C; i++) {
		cout << i+1 << " === before: ";
		printMap();
		// 상어 잡기
		catchShark(i);
		// 상어 이동
		moveSharks();
		cout << "after: ";
		printMap();
	}
	cout << ans;
}
