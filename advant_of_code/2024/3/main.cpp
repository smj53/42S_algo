#include <iostream>
#include <vector>
#include <fstream>
#include <regex>

using namespace std;

string filename;
string str;

void mul() {
	int sum = 0;
	regex re("mul\\((\\d{1,3}),(\\d{1,3})\\)");

	auto word_begin = sregex_iterator(str.begin(), str.end(), re);
	auto word_end = sregex_iterator();
	while (word_begin != word_end) {
		sum += stoi((*word_begin).str(1)) * stoi((*word_begin).str(2));
		++word_begin;
	}
	cout << sum << endl;
}

void removeDont() {
	int sum = 0;
	regex re("don't\\(\\).*?do\\(\\)");
	str = regex_replace(str, re, "");
}

void input() {
	ifstream fin;
	string s;
	fin.open(filename);
	while (getline(fin, s)) {
		str += s;
	}
}

int main(int argc, char **argv) {
	if (argc == 1)
		filename = "input.txt";
	else
		filename = argv[1];
	input();
	removeDont();
	mul();
}
