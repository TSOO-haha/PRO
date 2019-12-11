#include<iostream>
#include<cstring>
#include<stack>
using namespace std;
#define MAX 100
#define INF 0x3f3f3f3f
int dist[MAX], path[MAX];
struct Graph {
	int edges[MAX][MAX];//邻接矩阵,记录权值
	int n, e;//顶点数和边数
}G;
void init() {
	memset(G.edges, INF, sizeof(G.edges));
}
void insert(int x, int y, int w) {
	G.edges[x][y] = w;
}
void Dijkstra(Graph g, int v, int dist[], int path[]) {
	int set[MAX], min, i, j, u;
	//Step1：初始化
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
	//Step2:每次从剩余顶点中选出一个顶点，通往这个顶点的路径在通往所有剩余顶点的路径中是长度最短的
	for (i = 0; i < g.n - 1; i++) {
		min = INF;
		for (j = 0; j < g.n; j++) {
			if (set[j] == 0 && dist[j] < min) {
				u = j;
				min = dist[j];
			}
		}
		//将选出的顶点并入最短路径中
		set[u] = 1;
		//这个循环以刚并入的顶点作为中间点，对所有通往剩余顶点的路径进行检测
		for (j = 0; j < g.n; j++) {
			//判断顶点u的加入是否会出现通往j的更短路径，若有则改变原路径和长度
			if (set[j] == 0 && (dist[u] + g.edges[u][j] < dist[j])) {
				dist[j] = dist[u] + g.edges[u][j];//更新路径长度
				path[j] = u;
			}
		}
	}
}
void printPath(int path[], int a) {
	stack<int> s;
	//以由叶子结点到根结点的顺序将其入栈
	while (path[a] != -1) {
		s.push(a);
		a = path[a];
	}
	s.push(a);
	while (!s.empty()) {
		cout << s.top() << "  ";//打印栈顶元素，逆序打印
		s.pop();
	}
	cout << endl;
}
int main() {
	//初始化
	init();
	cout << "Please input the number of nodes and edges：" << endl;
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
