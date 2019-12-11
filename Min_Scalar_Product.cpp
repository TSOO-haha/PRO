#include<iostream>
#include<algorithm>
#define MAX_N 1000
typedef long long ll;
using namespace std;
int n;
int v1[MAX_N], v2[MAX_N];
/*************************************/
/************快速排序算法*************/
/*************************************/
/*
	par：
		int p :起点
		int r:终点
*/
int partition(int *a, int p, int r) {
	int key = a[r];//去最后一个元素作为基数
	int i = p - 1;
	for (int j = p; j < r; j++) {
		if (a[j] <= key) {
//i一直代表小于key元素的最后一个索引，当发现有比key小的a[j]时候，i+1 后交换 
			i++;
			int k = a[i];
			a[i] = a[j];
			a[j] = k;
		}
	}
	//将key切换到中间，左边小于key，右边大于key
	int temp = a[i + 1];
	a[i + 1] = a[r];
	a[r] = temp;
	return i + 1;
}
/*
	par：
		int p :起点
		int r:终点
*/
void quickSort(int *a, int p, int r) {
	int position = 0;
	if (p < r) {
		position = partition(a, p, r);
		quickSort(a, p, position - 1);//划分左边递归
		quickSort(a, position + 1, r);//划分右边递归
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