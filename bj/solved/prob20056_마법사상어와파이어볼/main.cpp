#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

// using Fire = tuple<int, int, int, int, int>
// auto &[a, b, c, d, e] : List<Fire>
// get<n>(Fire)

class Fire {
public:
	int r, c, m, s, d;
	Fire(int r, int c, int m, int s, int d): r(r), c(c), m(m), s(s), d(d) {}
	friend ostream &operator<<(ostream &o, Fire &f) {
		o << f.r << ", " << f.c;
		return o;
	}
};

int dir[8][2] = {{-1, 0}, {-1,1}, {0,1}, {1,1}, {1,0}, {1,-1},{0,-1},{-1,-1}};
unordered_set<Fire *> map[50][50];
unordered_set<Fire*> fire;
int N, M, K, r, c, m, s, d;

int sum() {
	int s = 0;
	for (Fire *f : fire) s+= f->m;
	return s;
}

void move() {
	for (Fire *f : fire) {
		map[f->r][f->c].erase(f);
		f->r = (f->r + (dir[f->d][0] + N) * f->s) % N;
		f->c = (f->c + (dir[f->d][1] + N) * f->s) % N;
		map[f->r][f->c].insert(f);
	}
}

void merge() {
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			int cnt = map[i][j].size();
			if (cnt < 2) continue;
			int ms = 0, ss = 0;
			bool allOdd = true, allEven = true;
			for (Fire *f : map[i][j]) {
				ms += f->m;
				ss += f->s;
				if (f->d % 2) {allOdd &= true; allEven &= false;}
				else { allOdd &= false; allEven &= true; }
				fire.erase(f);
				delete f;
			}
			map[i][j].clear();
			if (ms / 5 == 0) continue;
			for (int k=!(allOdd || allEven); k<8; k+=2) {
				Fire *f = new Fire(i, j, ms / 5, ss / cnt, k);
				fire.insert(f);
				map[i][j].insert(f);
			}
		}
	}
}

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N >> M >> K;
	for (int i=0; i<M; i++) {
		cin >> r >> c >> m >> s >> d;
		r--; c--;
		Fire *f = new Fire(r,c,m,s,d);
		fire.insert(f);
		map[r][c].insert(f);
	}
	while (K--) {
		move();
		merge();
	}
	cout << sum();
}