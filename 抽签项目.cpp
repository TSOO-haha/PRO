#include<iostream>
using namespace std;
//冒泡排序
void sort(int* kk, int N)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N - i - 1; j++)
		{
			if (kk[j] > kk[j + 1])
			{
				int temp = kk[j];
				kk[j] = kk[j + 1];
				kk[j + 1] = temp;
			}
		}
	}
}
bool binary_search(int x,int *k,int N)
{
	int l = 0;
	int r = N;
	while (r - l >= 1)
	{
		int i = (r + l) / 2;
		if (k[i] = x) return true;
		else if (k[i] < x)l = i + 1;
		else r = i;
	}
	return false;
}
int main()
{
	int n, sum;
	cout << "please input n :" << endl;
	cin >> n;
	cout << "please input the sum:" << endl;
	cin >> sum;
	int* x = new int[n];
	cout << "input the n numbers:" << endl;
	for (int i = 0; i <n; i++)
	{
		cin >> x[i];
	}
	//遍历所有c+d情况,存入kk数组中
	int N = (n + 1) * n / 2;
	int* kk = new int[N];
	int k = 0;
	for (int c = 0; c < n; c++)
	{
		for (int d = c + 1; d < n; d++)
		{
			kk[k] = x[c] + x[d];
			k++;
		}
	}
	//对kk中元素进行排序
	sort(kk,N);
	for (int i = 0; i < N; i++)
	{
		cout << kk[i] << endl;
	}
	//实现二分法查找
	bool f = false;
	for (int a = 0; a < n; a++)
	{
		for (int b = a+1; b < n; b++)
		{
			if (binary_search((sum - x[a] - x[b]),x,N))
			{
				f = true;
			}
		}
	}
	if (f) puts("Yes");
	else puts("No");
	return 0;
}