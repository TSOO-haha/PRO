#include<iostream>
#include<algorithm>
using namespace std;
int w[5] = { 0,2,1,3,2 };//商品重量
int v[5] = { 0,3,2,4,2 };//商品价值
int bagV = 8;//背包大小
int dp[5][9] = { {0} };//动态规划表
int item[5];//最优情况
void findMax() {
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= bagV; j++) {
			if (j < w[i]) {
				//包的容量比第i个物体小
				dp[i][j] = dp[i - 1][j];
			}
			else {
				//有足够的容量，判断能否到达最优
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
			}
		}
	}
}
//回溯最优解
void findWhat(int i, int j) {
	if (i >= 0) {
		if (dp[i][j] == dp[i - 1][j]) {
			item[i] = 0;
			findWhat(i - 1, j);
		}
		else if ((j - w[i]) >= 0 && dp[i][j] == dp[i-1][j - w[i]] + v[i]) {
			item[i] = 1;
			findWhat(i - 1, j - w[i]);
		}
	}
}
void print() {
	//动态规划表的输出
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 9; j++) {
			cout << dp[i][j] << "   ";
		}
		cout << endl;
	}
	for (int i = 0; i < 5; i++) {
		cout << item[i] << "  ";
	}
	cout << endl;
}
int main() {
	findMax();
	findWhat(4,8);
	print();
	return 0;
}