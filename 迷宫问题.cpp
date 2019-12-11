#include<iostream>
#include <utility> 
#include<queue>
using namespace std;
const int INF = 100000000;
//表示当前状态
typedef pair<int, int> P;
int maze[5][5] = {
		0,1,0,0,0,
		0,1,0,1,0,
		0,0,0,0,0,
		0,1,1,1,0,
		0,0,0,1,0 };//n=5,m=5
int sx=0, sy=0;//起点坐标
int gx=4, gy=4;//终点坐标
int d[5][5];//记录到各个位置最短距离的数组
//四个方向的移动量
int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
int bfs()
{
	//建立队列
	queue<P> que;
	//将所有的位置都初始化为INF
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			d[i][j] = INF;
		}
	}
	//将起点加入队列，并设距离为0
	que.push(P(sx, sy));
	d[sx][sy] = 0;
	//不断循环直至队列长度为零
	while (que.size())
	{
		//从队列最前端取出元素
		P p = que.front();
		que.pop();
		//若取出的状态为终点，则结束
		if (p.first == gx && p.second == gy) break;
		//四个方向进行循环
		for (int i = 0; i < 4; i++)
		{
			//移动后的位置为(nx,ny)
			int nx = p.first + dx[i];
			int ny = p.second + dy[i];
			//判断移动后的位置是否已经访问过了(d[nx][ny]!=INF即为已经访问过了)
			if (0 <= nx && nx < 5 && 0 <= ny && ny<5 && maze[nx][ny] != 1 && d[nx][ny] == INF)
			{
				//可以移动则加入队列，并且距离+1
				que.push(P(nx, ny));
				d[nx][ny] = d[p.first][p.second] + 1;
				cout << nx <<","<< ny << endl;
				cout << d[nx][ny] << endl;
			}
		}
	}
	return d[gx][gy];
}
int main()
{
	
	int res = bfs();
	cout << res;
	return 0;
}