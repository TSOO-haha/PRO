#include<iostream>
#include<cstring>
#include<stack>
using namespace std;
#define MAX 100
#define INF 0x3f3f3f3f
int dist[MAX], path[MAX];
struct Graph {
	int edges[MAX][MAX];//�ڽӾ���,��¼Ȩֵ
	int n, e;//�������ͱ���
}G;
void init() {
	memset(G.edges, INF, sizeof(G.edges));
}
void insert(int x, int y, int w) {
	G.edges[x][y] = w;
}
void Dijkstra(Graph g, int v, int dist[], int path[]) {
	int set[MAX], min, i, j, u;
	//Step1����ʼ��
	for (i = 0; i < g.n; i++) {
		dist[i] = g.edges[v][i];
		set[i] = 0;
		if (g.edges[v][i] < INF) {
			path[i] = v;
		}
		else {
			path[i] = -1;
		}
	}
	set[v] = 1;
	path[v] = -1;
	//Step2:ÿ�δ�ʣ�ඥ����ѡ��һ�����㣬ͨ����������·����ͨ������ʣ�ඥ���·�����ǳ�����̵�
	for (i = 0; i < g.n - 1; i++) {
		min = INF;
		for (j = 0; j < g.n; j++) {
			if (set[j] == 0 && dist[j] < min) {
				u = j;
				min = dist[j];
			}
		}
		//��ѡ���Ķ��㲢�����·����
		set[u] = 1;
		//���ѭ���Ըղ���Ķ�����Ϊ�м�㣬������ͨ��ʣ�ඥ���·�����м��
		for (j = 0; j < g.n; j++) {
			//�ж϶���u�ļ����Ƿ�����ͨ��j�ĸ���·����������ı�ԭ·���ͳ���
			if (set[j] == 0 && (dist[u] + g.edges[u][j] < dist[j])) {
				dist[j] = dist[u] + g.edges[u][j];//����·������
				path[j] = u;
			}
		}
	}
}
void printPath(int path[], int a) {
	stack<int> s;
	//����Ҷ�ӽ�㵽������˳������ջ
	while (path[a] != -1) {
		s.push(a);
		a = path[a];
	}
	s.push(a);
	while (!s.empty()) {
		cout << s.top() << "  ";//��ӡջ��Ԫ�أ������ӡ
		s.pop();
	}
	cout << endl;
}
int main() {
	//��ʼ��
	init();
	cout << "Please input the number of nodes and edges��" << endl;
	cin >> G.n >> G.e;
	int m = G.e, n = G.n;
	int a, x, y, w;
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> w;
		insert(x, y, w);
	}
	Dijkstra(G, 0, dist, path);
	printPath(path, 5);
	for (int i = 0; i < n; i++) {
		cout << dist[i] << " ";
	}
	return 0;
}
