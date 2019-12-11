#include<iostream>
#include<algorithm>
#define MAX_N 1000
typedef long long ll;
using namespace std;
int n;
int v1[MAX_N], v2[MAX_N];
/*************************************/
/************���������㷨*************/
/*************************************/
/*
	par��
		int p :���
		int r:�յ�
*/
int partition(int *a, int p, int r) {
	int key = a[r];//ȥ���һ��Ԫ����Ϊ����
	int i = p - 1;
	for (int j = p; j < r; j++) {
		if (a[j] <= key) {
//iһֱ����С��keyԪ�ص����һ���������������б�keyС��a[j]ʱ��i+1 �󽻻� 
			i++;
			int k = a[i];
			a[i] = a[j];
			a[j] = k;
		}
	}
	//��key�л����м䣬���С��key���ұߴ���key
	int temp = a[i + 1];
	a[i + 1] = a[r];
	a[r] = temp;
	return i + 1;
}
/*
	par��
		int p :���
		int r:�յ�
*/
void quickSort(int *a, int p, int r) {
	int position = 0;
	if (p < r) {
		position = partition(a, p, r);
		quickSort(a, p, position - 1);//������ߵݹ�
		quickSort(a, position + 1, r);//�����ұߵݹ�
	}
}
void minScalarProduct() {
	quickSort(v1, 0, n-1);
	quickSort(v2, 0, n - 1);
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		ans += (ll)v1[i] * v2[n - i - 1];
	}
	cout << ans;
}
void main() {
	cout << "n=";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "v1[" << i << "]=";
		cin >>v1[i];
	}
	for (int i = 0; i < n; i++) {
		cout << "v2[" << i << "]=";
		cin >> v2[i];
	}
	minScalarProduct();
}