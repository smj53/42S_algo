#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;

vector<vector<int>> v;
string filename;

void input() {
  ifstream fin;
  fin.open(filename);
  string str;
  while (getline(fin, str)) {
    stringstream ss(str);
    int a;
    vector<int> t;
    while (ss >> a) {
      t.push_back(a);
    }
    v.push_back(t);
  }
}

bool isSafe(vector<int> &v) {
  if (v[0] - v[1] == 0)
    return false;
  int diff = (v[0] - v[1]) / abs(v[0] - v[1]);
  for (int i = 0; i < v.size() - 1; i++) {
    if (diff * (v[i] - v[i + 1]) <= 0)
      return false;
    if (abs(v[i] - v[i + 1]) > 3)
      return false;
  }
  return true;
}

void safeCount() {
  int cnt = 0;
  for (auto vec : v) {
    if (isSafe(vec))
      cnt++;
  }
  cout << cnt << endl;
}

bool dampener(vector<int> &v) {
  for (int i=0; i<v.size(); i++) {
    int t = v[i];
    v.erase(v.begin() + i);
    if (isSafe(v)) return true;
    v.insert(v.begin() + i, t);
  }
  return false;
}

void safeCount2() {
  int cnt = 0;
  for (auto vec : v) {
    if (isSafe(vec))
      cnt++;
    else if (dampener(vec))
      cnt++;
  }
  cout << cnt << endl;
}

int main(int argc, char **argv) {
  if (argc == 1)
    filename = "input.txt";
  else
    filename = argv[1];
  input();
  safeCount();
  safeCount2();
}