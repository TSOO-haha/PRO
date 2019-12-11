#include<iostream>
#include<stdio.h>
#include<string.h>
#include<queue>
#include<algorithm>
using namespace std;
int extgcd(int a, int b, int &x, int &y) {
	int d = a;
	if (b != 0) {
		d = extgcd(b, a % b, y, x);
		y -=(a / b)*x;
	}
	else {
		x = 1;
		y = 0;
	}
	return d;
}
int main() {
	int a, b, x, y;
	int cnt[4] = {};
	scanf_s("%d %d", &a, &b);
	if (extgcd(a, b, x, y) != 1) {
		cout << -1 << endl;
		return 0;
	}
	if (x > 0) {cnt[0] = x;}
	else if (x < 0) { cnt[2] = -x; }
	if (y > 0) { cnt[1] = y; }
	else if (y < 0) { cnt[3] = -y; }
	for (int i = 0; i < 4; i++) {
		cout << cnt[i];
	}
	cout << endl;
	return 0;
}