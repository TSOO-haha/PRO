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
	//从x，y开始遍历
	map[x][y] = '.';
	for (int dx = -1; dx <= 1; dx++)//八个点分别为-1 0 1
	{
		for (int dy = -1; dy <= 1; dy++)
		{
			//向x方向进行dx，向y方向进行dy
			int nx = x + dx;
			int ny = y + dy;
			//判断(nx,ny)是否在园子内，以及是否有积水
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
	//统计dfs执行次数
	int num = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 'w')
			{
				//从有w的地方开始dfs
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