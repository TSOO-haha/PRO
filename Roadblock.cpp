#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define MAX_N 1000
#define INF 1000000
int N, R;
typedef pair<int,int> P;//first是最短距离，second是顶点编号
//图的邻接表表示
/*
3 3 (顶点数 边数）
0 1 （从0到1）
0 2 （从0到2）
1 2 （从1到2）
*/
struct edge {
	int to;
	int cost;
};
vector<edge> G[MAX_N];
int dist[MAX_N], dist2[MAX_N];//最短距离和次短距离
void solve(int s) {
	//优先队列
	priority_queue<P, vector<P>, greater<P>> que;
	fill(dist, dist + N, INF);
	fill(dist2, dist2 + N, INF);
	dist[s] = 0;
	que.push(P(0, s));
	while (!que.empty()) {
		P p = que.top(); que.pop();
		int v = p.second, d = p.first;
		if (dist2[v] < d) continue;
		for (int i = 0; i < G[v].size(); i++) {
			edge& e = G[v][i];
			int d2 = d + e.cost;
			if (dist[e.to] > d2) {
				swap(dist[e.to], d2);
				que.push(P(dist[e.to], e.to));
			}
			if (dist2[e.to] > d2&& dist[e.to] < d2) {
				dist2[e.to] = d2;
				que.push(P(dist2[e.to], e.to));
			}
		}
	}
	cout << dist2[N - 1] << endl;
}
int main() {
	//输入邻接表
	int N, R;//V顶点数，E为边数
	cout << "Please input the N(the number of node) and R(the number of edge):";
	cin >> N >> R;
	cout << "Please input from,to,cost" << endl;
	for (int i = 0; i < R; i++) {
		int s, t,w;
		edge start, end;
		cin >> s >> t>>w;
		start.to = t, start.cost = w;
		//从s向t连边
		G[s].push_back(start);
		//从t向s连边
		end.to = s, end.cost = w;
		G[t].push_back(end);
	}
	solve(1);
	return 0;
}