#include<iostream>
#include<algorithm>
using namespace std;
int w[5] = { 0,2,1,3,2 };//��Ʒ����
int v[5] = { 0,3,2,4,2 };//��Ʒ��ֵ
int bagV = 8;//������С
int dp[5][9] = { {0} };//��̬�滮��
int item[5];//�������
void findMax() {
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= bagV; j++) {
			if (j < w[i]) {
				//���������ȵ�i������С
				dp[i][j] = dp[i - 1][j];
			}
			else {
				//���㹻���������ж��ܷ񵽴�����
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
			}
		}
	}
}
//�������Ž�
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
	//��̬�滮������
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