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
	//�������ʱ��
	int minT = 0;
	//ÿ��ant���������Լ��߽��Ķ˵㣬û�н���
	for (int i = 0; i < n; i++)
	{
		minT = max(minT, min(x[i], L - x[i]));
	}
	//�����ʱ��
	int maxT = 0;
	//�൱��ÿ��ant���������Լ���Զ��
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