#include<iostream>
#include<cstdio>
using namespace std;
const int MAX_N = 100;
const int MAX_M = 100;
char map[MAX_N][MAX_M];
int n, m;
void input_data()
{
	cout << "input n:";
	cin >> n;
	cout << "input m:";
	cin >> m;
	cout << "input the map;";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}
}
void dfs(int x, int y)

{
	//��x��y��ʼ����
	map[x][y] = '.';
	for (int dx = -1; dx <= 1; dx++)//�˸���ֱ�Ϊ-1 0 1
	{
		for (int dy = -1; dy <= 1; dy++)
		{
			//��x�������dx����y�������dy
			int nx = x + dx;
			int ny = y + dy;
			//�ж�(nx,ny)�Ƿ���԰���ڣ��Լ��Ƿ��л�ˮ
			if (0 <= nx && nx < n && 0 <= ny && ny < m && map[nx][ny] == 'w')
			{
				dfs(nx, ny);
			}
		}
	}
	return;
}
void solve()
{
	//ͳ��dfsִ�д���
	int num = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 'w')
			{
				//����w�ĵط���ʼdfs
				dfs(i, j);
				num++;
			}
		}
	}
	printf("%d\n", num);
}
int main()
{
	input_data();
	solve();
	return 0;
}