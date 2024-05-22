#include <iostream>
#include <algorithm>
using namespace std;

int motor[4];
int K, num, dir;

#include <bitset>
void printBinary(int val) {
	bitset<8> bit(val);
	cout << "==== BINARY: " << val << "\n" << bit << endl;
}

void printMotors() {
	for (int i=0; i<4; i++) {
		cout << "motor " << i << " ============\n";
		printBinary(motor[i]);
		cout << endl;
	}
}

void move(int num, bool isCircle) {
	if (isCircle) {
		int bit = motor[num] >> 7;
		motor[num] <<= 1;
		motor[num] |= bit;
		motor[num] &= ~(1<<8);
	} else {
		int bit = motor[num] & 1;
		motor[num] >>= 1;
		motor[num] |= bit << 7;
	}
}

bool isMove(int left, int right) {
	return ((motor[left] & 1<<2)>>2) ^ ((motor[right] & 1<<6)>>6);
}

void moveLeft(int num, bool isCircle) {
	if (num == 0)
		return;
	int left = num - 1;
	if (isMove(left, num)) {
		moveLeft(left, !isCircle);
		move(left, isCircle);
	}
}

void moveRight(int num, bool isCircle) {
	if (num == 3)
		return;
	int right = num + 1;
	if (isMove(num, right)) {
		moveRight(right, !isCircle);
		move(right, isCircle);
	}
}

int score() {
	int score = 0;
	for (int i=0; i<4; i++) {
		score += (motor[i]&1)<<i;
	}
	return score;
}

int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	for (int i=0; i<4; i++) {
		string in;
		cin >> in;
		motor[i] = 0;
		for (int j=0; j<in.size(); j++) {
			motor[i] |= (in[j] & 1)<<j;
		}
	}
	cin >> K;
	while (K--) {
		cin >> num >> dir;
		bool isCircle = dir == 1;
		num--;
		moveLeft(num, !isCircle);
		moveRight(num, !isCircle);
		move(num, isCircle);
	}
	
	cout << score();
}