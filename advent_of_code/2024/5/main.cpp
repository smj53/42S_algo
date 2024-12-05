#include <iostream>
#include <set>
#include <map>
#include <regex>
#include <fstream>

using namespace std;

map<int, set<int>> smallerThan;
vector<vector<int>> pages;

void parseRule(string str) {
	regex re("(\\d+)\\|(\\d+)");
	smatch m;
	int p, n;
	if (regex_match(str, m, re)) {
		p = stoi(m[1].str());
		n = stoi(m[2].str());
		auto it = smallerThan.find(p);
		if (it != smallerThan.end()) {
			it->second.insert(n);
		} else {
			set<int> tt;
			tt.insert(n);
			smallerThan.insert({p, tt});
		}
	}
}

vector<int> parsePages(string str) {
	regex re("\\d+");
	vector<int> pages;
	auto it = sregex_iterator(str.begin(), str.end(), re);
	auto word_end = sregex_iterator();
	while (it != word_end) {
		pages.push_back(stoi(it->str(0)));
		it++;
	}
	return pages;
}

void input(string filename) {
	ifstream fin;
	string str;
	fin.open(filename);
	while (true) {
		getline(fin, str);
		parseRule(str);
		if (str == "") break;
	}
	while (getline(fin, str)) {
		pages.push_back(parsePages(str));
	}
	fin.close();
}

bool isSmaller(int a, int b) {
	auto it = smallerThan.find(a);
	if (it == smallerThan.end()) return false;
	return it->second.find(b) != it->second.end();
}

bool checkValid(vector<int> &page) {
	for (int i=0; i<page.size(); i++) {
		for (int j=0; j<i; j++) {
			if (isSmaller(page[i], page[j])) return false;
		}
		for (int j=i+1; j<page.size(); j++) {
			if (isSmaller(page[j], page[i])) return false;
		}
	}
	return true;
}

int sumValid() {
	int sum = 0;
	for (auto p : pages) {
		if (checkValid(p)) sum += p[p.size() / 2];
	}
	return sum;
}

bool compare(int a, int b) {
	if (isSmaller(a, b)) return true;
	// if (isSmaller(b, a)) return false;
	return false;
}

int sumInvalid() {
	int sum = 0;
	for (auto p : pages) {
		if (!checkValid(p)) {
			sort(p.begin(), p.end(), compare);
			if (checkValid(p)) cout << "valid!!" << endl;
			sum += p[p.size() / 2];
		}
	}
	return sum;
}

int main(int argc, char **argv) {
	if (argc == 1) input("input");
	else input(argv[1]);
	cout << sumValid() << endl;
	cout << sumInvalid() << endl;
}