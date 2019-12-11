#include<iostream>
#include<algorithm>
#include<queue>
#include<cstdio>
using namespace std;
#define MAX_R 50010
struct edge {
	int u, v, cost;
};
int num, N, M, R;
int V, E;//V个节点，E条边
int par[MAX_R];//父节点
int depth[MAX_R];//树的深度
int x[MAX_R], y[MAX_R], d[MAX_R];//用于记录x,y,d
edge es[MAX_R];//记录两个节点之间的关系
bool compare(const edge &e1,const edge &e2) {
	return e1.cost < e2.cost;
}
//初始化n个元素
void init(int n) {
	for (int i = 0; i < n; i++) {
		par[i] = i;
		depth[i] = 0;
	}
}
//查询树的根
int find(int x) {
	if (par[x] == x)return x;
	else return par[x] = find(par[x]);
}
//合并x和y所属的集合
void unite(int x, int y) {
	x = find(x);
	y = find(y);
	//深度小在下边
	if (depth[x] < depth[y]) {
		par[x] = y;
	}
	else {
		par[y] = x;
		if (depth[x] == depth[y]) depth[x]++;
	}
}
//判断x和y是否属于同一集合
bool same(int x, int y) {
	return find(x) == find(y);
}
int kruskal() {
	/*按照cost也就是亲密度从小到大的顺序排列
	 *那么这个地方由于每个cost的值都为负值
	 *从绝对值来看就是从大到小排列了
	 *最终减去的值的绝对值就是最大值
	 */
	sort(es, es + E, compare);
	init(V);
	int res = 0;
	for (int i = 0; i < E; i++) {
		edge e = es[i];
		if (!same(e.u, e.v))
		{
			unite(e.u, e.v);
			res += e.cost;
		}
	}
	return res;
}
void solve() {
	cin >> N >> M >> R;
	for (int i = 0; i < R; i++) {
		cin >> x[i] >> y[i] >> d[i];
	}
	V = N + M;
	E = R;
	for (int i = 0; i < R; i++) {
		es[i] = edge {x[i],N + y[i],-d[i] };
	}
	//总费用-亲密度最大值
	cout << 10000 * (N + M) + kruskal() << endl;
}
int main() {
	cin >> num;
	while (num--)
		solve();
	return 0;
}
