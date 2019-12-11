#include<iostream>
#include<cstdio>
using namespace std;
#define MAX  0x3f3f3f3f 
#define N 1001
int nodenum, edgenum, original;//�ڵ����������������
struct Edge {
	int u, v;
	int cost;//Ȩֵ
};
Edge edge[N];
int dis[N], pre[N];
bool Bellman_Ford() {
	for (int i = 1; i <= nodenum; ++i) {
		//��ʼ��
		dis[i] = ( i==original ? 0 : MAX);
	}
	for (int i = 1; i <= nodenum - 1; ++i) {
		//ѭ��nodenum-1��
		for (int j = 1; j <= edgenum; ++j) {
			if (dis[edge[j].v] > dis[edge[j].u] + edge[j].cost) {
				dis[edge[j].v] = dis[edge[j].u] + edge[j].cost;
				pre[edge[j].v] = edge[j].u;
			}
		}
	}
	bool flag = 1;//�ж��Ƿ��и���·
	for (int i = 1; i <= edgenum; ++i) {
		if (dis[edge[i].v] > dis[edge[i].u] + edge[i].cost) {
			flag = 0;
			break;
		}
	}
	return flag;
}
//��ӡ���·��
void Print_Path(int root) {
	while (root != pre[root]) {
		//ǰ��
		printf("%d-->", root);
		root = pre[root];
	}
	if (root == pre[root]) {
		printf("%d\n", root);
	}
}
int main() {
	printf("Input Node and Edge Number,and oridinal:\n");
	scanf_s("%d %d %d", &nodenum, &edgenum, &original);
	pre[original] = original;
	printf("u v cost:\n");
	for (int i = 1; i <=edgenum; ++i) {
		scanf_s("%d %d %d", &edge[i].u, &edge[i].v, &edge[i].cost);
	}
	if (Bellman_Ford()) {
		for (int i = 1; i <= nodenum; ++i) {
			//ÿ��������·
			printf("The short distance:%d\n", dis[i]);
			printf("Path:");
			Print_Path(i);
		}
	}
	else {
		printf("have negative circle\n");
		return 0;
	}
}

