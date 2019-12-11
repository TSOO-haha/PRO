#include<iostream>
#include<cstdio>
using namespace std;
#define MAX 100
#define MAXCOST 0x7fffffff
struct VertexType {
	int no;//������
};
struct MGraph {
	int edge[MAX][MAX];
	int n, e;//n������,e����
	VertexType vex[MAX];
};
/*
	MGraph g:�ڽӾ���
	int v����һ�����ɵĵ�
*/
void Prim(MGraph g, int v) {
	int lowest[MAX], closest[MAX], min,k;
	//��ʼ��lowcost��closest����
	//lowcost[j]�洢���ǽڵ�j�뵱ǰ��ѡ�ڵ���������СȨֵ��lowcost[j]==0��ʾ�ڵ�j�ѱ�ѡ��
	//closest[j]�洢lowcost[j]��Ӧ�����ӵ�
	for (int i = 0; i <g.n; i++) {
		closest[i] = v;
		lowest[i] = g.edge[v][i];
	}
	for (int i = 1; i < g.n; i++) {
		/*****�ҵ�һ���ڵ㣬�ýڵ㵽��ѡ�ڵ��е�*/
		/*****ĳһ���ڵ��Ȩֵ�ǵ�ǰ��С��*****/
		min = MAXCOST;
		for (int j = 0; j <g.n; j++) {
			if (lowest[j] != 0 && lowest[j] < min) {
				min = lowest[j];
				k = j;
			}
		}
		/******��������ӽڵ������ӽڵ�******/
		/******�Լ����ǵ�Ȩֵ*****/
		printf("��(%d,%d)ȨΪ��%d\n", closest[k], k, min);
		/***********����lowcost���飬closest���飬�Ա�������һ���ڵ�********/
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
	cout << "������ڵ���Ŀ��" << endl;
	cin >>graph.n;
	cout << "������ߵ���Ŀ��" << endl;
	cin >> graph.e;
	//��ʼ��
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
	cout << "������ߵ�Ȩֵ��(����1 ����2 Ȩֵ��" << endl;
	for (int i = 0; i < graph.e; i++) {
		cin >> from >> to >> cost;
		graph.edge[from][to] = cost;
		graph.edge[to][from] = cost;
	}
	Prim(graph, 0);
	return 0;
}