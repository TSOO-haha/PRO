#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define INF 1e8
using namespace std;
const int maxn = 10005;
int n, M, D;
int d[1005];
int AL[maxn], BL[maxn], DL[maxn];
int AD[maxn], BD[maxn], DD[maxn];
void solve() {
	fill(d, d + n, INF);
	d[0] = 0;
	//使用Bellman-Ford算法求解d
	for (int k = 0; k < n; k++) {
		//从i+1到i的权值为0
		for (int i = 0; i < n - 1; i++) {
			if (d[i + 1] < INF) { d[i] = min(d[i], d[i + 1]); }
		}
		//从BL到AL的边为DL
		for (int i = 0; i < M; i++) {
			if (d[AL[i] - 1] < INF) {
				d[BL[i] - 1] = min(d[BL[i] - 1], d[AL[i] - 1] + DL[i]);
			}
		}
		//从BD向AD的边为-DD
		for (int i = 0; i < D; i++) {
			if (d[BD[i] - 1] < INF) {
				d[AD[i] - 1] = min(d[AD[i] - 1], d[BD[i] - 1] - DD[i]);
			}
		}
	}
	int res = d[n - 1];
	if (d[0] < 0) {
		//存在负圈则无解
		res = -1;
	}
	else if (res == INF) { res = -2; }
	printf("%d\n", res);
}
int main() {
	cin >> n >> M >> D;
	for (int i = 0; i < M; i++) {
		scanf_s("%d %d %d", &AL[i], &BL[i], &DL[i]);
	}
	for (int i = 0; i < D; i++) {
		scanf_s("%d %d %d", &AD[i], &BD[i], &DD[i]);
	}
	solve();
}