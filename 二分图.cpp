#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
using namespace std;
const int N = 1e4 + 50;
const int M = 1e5 + 50;
int n, m;
int u, v;
int color[1000];//顶点颜色（1 or -1）
vector<int> G[1000];
struct edge {
	int v, next;
};
//将顶点染为1或-1
bool dfs(int v, int c) {
	color[v] = c;//将顶点染为颜色c
	for (int i = 0; i < G[v].size(); i++) {
		//如果相邻颜色相同，则返回false
		if (color[G[v][i]] == c) return false;
		//如果相邻的顶点未被染色，则染成-c
		if (color[G[v][i]] == 0 && !dfs(G[v][i], -c)) return false;
	}
	return true;
}
int main() {
	int t;
	cin >> t;
	//创建图
	while (t--) {
		scanf_s("%d %d", &n, &m);
		for (int i = 1; i <= n; i++) {
			G[i].clear();
		}
		while (m--) {
			int s, t;
			scanf_s("%d %d", &s, &t);
			G[s].push_back(t);//从s向t连边
			G[t].push_back(s);//从t向s连边
		}
	}
	memset(color, 0, sizeof(color));
	for (int i = 0; i <= n; i++) {
		if (color[i] == 0) {
			//如果顶点i还没被染色，则染为1
			if (!dfs(i, 1)) {
				printf("No\n");
				break;
			}
		}
	}
	printf("Yes\n");
	return 0;
}
