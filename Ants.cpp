#include<iostream>
#include<vector>
#include<iterator>
#include<cstdio>
using namespace std;
int max(int a, int b)
{
	if (a < b)
	{
		return b;
	}
	else {
		return a;
	}
}
int min(int a, int b)
{
	if (a < b)
	{
		return a;
	}
	else {
		return b;
	}
}
void solve(int L, int n, int *x)
{
	//计算最短时间
	int minT = 0;
	//每个ant都走向离自己走进的端点，没有交错
	for (int i = 0; i < n; i++)
	{
		minT = max(minT, min(x[i], L - x[i]));
	}
	//计算最长时间
	int maxT = 0;
	//相当于每个ant都走向离自己最远点
	for (int i = 0; i < n; i++)
	{
		maxT = max(maxT, max(x[i], L - x[i]));
	}
	printf("min:%d,max:%d\n", minT, maxT);
}
int main()
{
	int L;
	cout << "Please input L:" << endl;
	cin >> L;
	int n;
	cout << "Please input n:" << endl;
	cin >> n;
	int *x = new int[n];
	cout << "Please input the xi:" << endl;
	for (int i =0; i<n;i++)
	{
		cin>>x[i];
	}
	solve(L, n, x);
	return 0;

}