#include<iostream>
#include<cstdio>
using namespace std;
#define MAX 100
#define MAXCOST 0x7fffffff
struct VertexType {
	int no;//顶点编号
};
struct MGraph {
	int edge[MAX][MAX];
	int n, e;//n顶点数,e边数
	VertexType vex[MAX];
};
/*
	MGraph g:邻接矩阵
	int v：第一个生成的点
*/
void Prim(MGraph g, int v) {
	int lowest[MAX], closest[MAX], min,k;
	//初始化lowcost和closest数组
	//lowcost[j]存储的是节点j与当前已选节点相连的最小权值（lowcost[j]==0表示节点j已被选）
	//closest[j]存储lowcost[j]对应的连接点
	for (int i = 0; i <g.n; i++) {
		closest[i] = v;
		lowest[i] = g.edge[v][i];
	}
	for (int i = 1; i < g.n; i++) {
		/*****找到一个节点，该节点到已选节点中的*/
		/*****某一个节点的权值是当前最小的*****/
		min = MAXCOST;
		for (int j = 0; j <g.n; j++) {
			if (lowest[j] != 0 && lowest[j] < min) {
				min = lowest[j];
				k = j;
			}
		}
		/******输出被连接节点与连接节点******/
		/******以及它们的权值*****/
		printf("边(%d,%d)权为：%d\n", closest[k], k, min);
		/***********更新lowcost数组，closest数组，以便生成下一个节点********/
		lowest[k] = 0;
		for (int j = 0; j < g.n; j++) {
			if (g.edge[k][j] != 0 && g.edge[k][j] < lowest[j]) {
				lowest[j] = g.edge[k][j];
				closest[j] = k;
			}
		}
	}
}
int main() {
	MGraph graph;
	int x,y,cost;
	cout << "请输入节点数目：" << endl;
	cin >>graph.n;
	cout << "请输入边的数目：" << endl;
	cin >> graph.e;
	//初始化
	for (int i = 0; i <graph.n; i++) {
		for (int j = 0; j <graph.n; j++) {
			if (i == j) {
				graph.edge[i][j] = 0;
			}
			else {
				graph.edge[i][j] = MAXCOST;
			}
			
		}
	}
	int from, to;
	cout << "请输入边的权值：(顶点1 顶点2 权值）" << endl;
	for (int i = 0; i < graph.e; i++) {
		cin >> from >> to >> cost;
		graph.edge[from][to] = cost;
		graph.edge[to][from] = cost;
	}
	Prim(graph, 0);
	return 0;
}