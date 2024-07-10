#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
using namespace std;

class Fire {
public:
	int r, c, m, s, d;
	Fire(int r, int c, int m, int s, int d): r(r), c(c), m(m), s(s), d(d) {}
};

int dir[8][2] = {{-1, 0}, {-1,1}, {0,1}, {1,1}, {1,0}, {1,-1},{0,-1},{-1,-1}};
list<Fire *> map[50][50];
vector<Fire*> fire;
int N, M, K, r, c, m, s, d;

int sum() {
	int s = 0;
	for (int i=0; i<fire.size(); i++) s+= fire[i]->m;
	return s;
}

void move() {
	for (Fire *f : fire) {
		map[f->r][f->c].remove(f);
		f->r = (f->r + dir[f->d][0] * f->s) % N;
		f->c = (f->c + dir[f->d][1] * f->s) % N;
		map[f->r][f->c].push_back(f);
	}
}

void merge() {
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			int ms = 0, ss = 0;
			int cnt = map[i][j].size();
			bool allOdd = true, allEven = true;
			for (Fire *f : map[i][j]) {
				ms += f->m;
				ss += f->s;
				if (f->d % 2) {allOdd &= true; allEven &= false;}
				else {allOdd &= false; allEven &= true; }
				delete f;
			}
			map[i][j].clear();
			if (ms / 5 == 0) continue;
			for (int i=!(allOdd || allEven); i<8; i+=2) {
				map[i][j].push_back(new Fire(i, j, ms / 5, ss / cnt, i));
			}
		}
	}
}

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N >> M >> K;
	for (int i=0; i<M; i++) {
		cin >> r >> c >> m >> s >> d;
		fire.push_back(new Fire(r,c,m,s,d));
		map[r][c].push_back(fire[i]);
	}
	while(K--) {
		move();
		merge();
	}
	cout << sum();
}