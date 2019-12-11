#include<iostream>
#include<stdio.h>
using namespace std;
#define MAX_N 40
int M[MAX_N][MAX_N];
int a[MAX_N];//用来存放某一行的最后一个1在第几列
int n;
void solve() {
	int ans = 0;
	for (int i = 0; i < n; i++) {
		a[i] = -1;
		for (int j = 0; j < n; j++) {
			if (M[i][j] == 1)a[i] = j;//存下第i行的最后一个1所在列
		}
	}
	for (int i = 0; i < n; i++) {
		int pos = -1;
		//每次前面的行都是已经排列好的，只需往后找
		for (int j = i; j < n; j++) {
			if (a[j] <= i) {
				//记录下满足条件的最近行的位置
				pos = j;
				break;
			}
		}
		//逐行交换
		for (int j = pos; j > i; j--) {
			swap(a[j], a[j - 1]);
			ans++;
		}
	}
	printf("一共交换%d\n", ans);
}
int main() {
	cout << "Please input n=";
	while (~scanf_s("%d",&n)) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf_s("%d", &M[i][j]);
			}
		}
		solve();
	}
	return 0;
}