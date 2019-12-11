#include<iostream>
#include <utility> 
#include<queue>
using namespace std;
const int INF = 100000000;
//��ʾ��ǰ״̬
typedef pair<int, int> P;
int maze[5][5] = {
		0,1,0,0,0,
		0,1,0,1,0,
		0,0,0,0,0,
		0,1,1,1,0,
		0,0,0,1,0 };//n=5,m=5
int sx=0, sy=0;//�������
int gx=4, gy=4;//�յ�����
int d[5][5];//��¼������λ����̾��������
//�ĸ�������ƶ���
int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
int bfs()
{
	//��������
	queue<P> que;
	//�����е�λ�ö���ʼ��ΪINF
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			d[i][j] = INF;
		}
	}
	//����������У��������Ϊ0
	que.push(P(sx, sy));
	d[sx][sy] = 0;
	//����ѭ��ֱ�����г���Ϊ��
	while (que.size())
	{
		//�Ӷ�����ǰ��ȡ��Ԫ��
		P p = que.front();
		que.pop();
		//��ȡ����״̬Ϊ�յ㣬�����
		if (p.first == gx && p.second == gy) break;
		//�ĸ��������ѭ��
		for (int i = 0; i < 4; i++)
		{
			//�ƶ����λ��Ϊ(nx,ny)
			int nx = p.first + dx[i];
			int ny = p.second + dy[i];
			//�ж��ƶ����λ���Ƿ��Ѿ����ʹ���(d[nx][ny]!=INF��Ϊ�Ѿ����ʹ���)
			if (0 <= nx && nx < 5 && 0 <= ny && ny<5 && maze[nx][ny] != 1 && d[nx][ny] == INF)
			{
				//�����ƶ��������У����Ҿ���+1
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