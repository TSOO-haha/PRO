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
int V, E;//V���ڵ㣬E����
int par[MAX_R];//���ڵ�
int depth[MAX_R];//�������
int x[MAX_R], y[MAX_R], d[MAX_R];//���ڼ�¼x,y,d
edge es[MAX_R];//��¼�����ڵ�֮��Ĺ�ϵ
bool compare(const edge &e1,const edge &e2) {
	return e1.cost < e2.cost;
}
//��ʼ��n��Ԫ��
void init(int n) {
	for (int i = 0; i < n; i++) {
		par[i] = i;
		depth[i] = 0;
	}
}
//��ѯ���ĸ�
int find(int x) {
	if (par[x] == x)return x;
	else return par[x] = find(par[x]);
}
//�ϲ�x��y�����ļ���
void unite(int x, int y) {
	x = find(x);
	y = find(y);
	//���С���±�
	if (depth[x] < depth[y]) {
		par[x] = y;
	}
	else {
		par[y] = x;
		if (depth[x] == depth[y]) depth[x]++;
	}
}
//�ж�x��y�Ƿ�����ͬһ����
bool same(int x, int y) {
	return find(x) == find(y);
}
int kruskal() {
	/*����costҲ�������ܶȴ�С�����˳������
	 *��ô����ط�����ÿ��cost��ֵ��Ϊ��ֵ
	 *�Ӿ���ֵ�������ǴӴ�С������
	 *���ռ�ȥ��ֵ�ľ���ֵ�������ֵ
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
	//�ܷ���-���ܶ����ֵ
	cout << 10000 * (N + M) + kruskal() << endl;
}
int main() {
	cin >> num;
	while (num--)
		solve();
	return 0;
}
