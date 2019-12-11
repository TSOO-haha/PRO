//程序中下标从零开始，而题目中要求从1开始
#include<iostream>
#include<cstdio>
using namespace std;
bool dfs(int i, int sum,int k,int n,int *a)
{
	//如果前n项计算好了，则返回sum和k是否相等
	if (i == n)  return sum == k;
	//不加a[i]的情况
	if (dfs(i + 1, sum, k, n,a)) return true;
	//加上a[i]
	if (dfs(i + 1, sum + a[i], k, n, a)) return true;
	//进行到最后都凑不成
	return false;
}
int main()
{
	int n;
	int k;
	printf("please input the n:");
	cin >> n;
	printf("please input the k:");
	cin >> k;
	int* a = new int[n];
	printf("please input n numbers:");
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	//从第一个节点开始，和为零
	if (dfs(0, 0,k,n,a)) printf("Yes\n");
	else printf("NO\n");
}