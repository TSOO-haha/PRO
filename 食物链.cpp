//D为说话的种类
//D=1，X和Y同类；D=2，X吃Y
//N：动物数量，K：信息数量
#include<iostream>
using namespace std;
int n;
int f[50005];//储存父节点
int r[50005];//储存关系，0：同类，1：吃父节点，2：被父节点吃
int find(int p) {
	//查找结点，返回并查集的根节点
	int fp = p;
	if (p != f[p]) {
		fp = find(f[p]);//压缩路径
		r[p] = (r[p] + r[f[p]]) % 3;//穷举法
		f[p] = fp;
	}
	return f[p];
}
int Union(int d, int x, int y) {
	//合并两节点所在的集合
	int fx = find(x); int fy = find(y);
	
	if (fx != fy) {
		f[fy] = fx;
		r[fy] = (3 + r[x] - d - r[y] + 1) % 3;
		return 0;
	}
	if (((r[x] - r[y] + 3) % 3) != (d - 1)) {
		return 1;
	}
	return 0;
}
int main() {
	int n; int k; int ans = 0;
	int d, x, y;
	(cin >> n >> k).get();
	for (int i = 1; i <= n; i++) {
		//初始化父节点，每个父节点为自己，关系为同类
		f[i] = i;
		r[i] = 0;
	}
	for (int i = 0; i < k; i++) {
		(cin >> d >> x >> y).get();
		if (x > n || y > n || (d == 2 && x == y)) {
			//错误信息
			ans++;
			continue;
		}
		if (Union(d, x, y))ans++;
	}
	cout << ans << endl;
	return 0;
}