#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<string> m;
const string XMAS = "XMAS";
int d[8][2] = {{1, 1}, {-1, -1}, {-1, 1}, {1, -1}, {0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void input(string filename) {
	ifstream fin;
	fin.open(filename);
	string str;
	while (getline(fin, str)) {
		m.push_back(str);
	}
	fin.close();
}

bool isXMAS(int si, int sj, int d[2]) {
	for (int i = 0; i<4; i++) {
		if (si<0 || si>=m.size() || sj<0 || sj>=m[si].size()) return false;
		if (m[si][sj] != XMAS[i]) return false;
		si += d[0];
		sj += d[1];
	}
	return true;
}

int countXMAS() {
	int cnt = 0;
	for (int i=0; i<m.size(); i++) {
		for (int j=0; j<m[i].size(); j++) {
			for (int k=0; k<8; k++) {
				if (isXMAS(i, j, d[k])) cnt++;
			}
		}
	}
	return cnt;
}

bool isCrossXMAS(int si, int sj) {
	if (m[si][sj] != 'A') return false;
	string MS = "MS";
	for (int i=0; i<2; i++) {
		bool flag = true;
		bool rflag = true;
		for (int j=0; j<2; j++) {
			int ni = si + d[i*2 + j][0];
			int nj = sj + d[i*2 + j][1];
			if (ni<0 || ni>=m.size() || nj<0 || nj>=m[ni].size()) return false;
			if (m[ni][nj] != MS[j]) flag = false;
			if (m[ni][nj] != MS[j ^ 1]) rflag = false;
		}
		if (!flag && !rflag) return false;
	}
	return true;
}

int countCrossXMAS() {
	int cnt = 0;
	for (int i=0; i<m.size(); i++) {
		for (int j=0; j<m[i].size(); j++) {
			if (isCrossXMAS(i, j)) cnt++;
		}
	}
	return cnt;
}

int main(int argc, char **argv) {
	if (argc == 1) input("input");
	else input(argv[1]);
	cout << countXMAS() << endl;
	cout << countCrossXMAS();
}