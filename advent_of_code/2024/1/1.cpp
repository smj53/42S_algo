#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> a, b;
string filename;

void input() {
  ifstream fin;
  fin.open(filename);
  int aa, bb;
  while (fin >> aa >> bb) {
    a.push_back(aa);
    b.push_back(bb);
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
}

void sum() {
  int sum = 0;
  for (int i = 0; i < a.size(); i++) {
    sum += abs(a[i] - b[i]);
  }
  cout << sum << endl;
}

void sim() {
  int score = 0;
  for (int i = 0; i < a.size(); i++) {
    int cnt = 0;
    for (int j = 0; j < b.size(); j++) {
      if (a[i] == b[j])
        cnt++;
    }
    score += a[i] * cnt;
  }
  cout << score;
}

int main(int argc, char **argv) {
  if (argc == 1)
    filename = "input.txt";
  else
    filename = argv[1];
  input();
  sum();
  sim();
}