//�������±���㿪ʼ������Ŀ��Ҫ���1��ʼ
#include<iostream>
#include<cstdio>
using namespace std;
bool dfs(int i, int sum,int k,int n,int *a)
{
	//���ǰn�������ˣ��򷵻�sum��k�Ƿ����
	if (i == n)  return sum == k;
	//����a[i]�����
	if (dfs(i + 1, sum, k, n,a)) return true;
	//����a[i]
	if (dfs(i + 1, sum + a[i], k, n, a)) return true;
	//���е���󶼴ղ���
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
	//�ӵ�һ���ڵ㿪ʼ����Ϊ��
	if (dfs(0, 0,k,n,a)) printf("Yes\n");
	else printf("NO\n");
}