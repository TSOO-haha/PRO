#include<iostream>
#include<stdio.h>
using namespace std;
#define MAX_N 40
int M[MAX_N][MAX_N];
int a[MAX_N];//�������ĳһ�е����һ��1�ڵڼ���
int n;
void solve() {
	int ans = 0;
	for (int i = 0; i < n; i++) {
		a[i] = -1;
		for (int j = 0; j < n; j++) {
			if (M[i][j] == 1)a[i] = j;//���µ�i�е����һ��1������
		}
	}
	for (int i = 0; i < n; i++) {
		int pos = -1;
		//ÿ��ǰ����ж����Ѿ����кõģ�ֻ��������
		for (int j = i; j < n; j++) {
			if (a[j] <= i) {
				//��¼����������������е�λ��
				pos = j;
				break;
			}
		}
		//���н���
		for (int j = pos; j > i; j--) {
			swap(a[j], a[j - 1]);
			ans++;
		}
	}
	printf("һ������%d\n", ans);
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