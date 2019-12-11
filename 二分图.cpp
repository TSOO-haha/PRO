#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
using namespace std;
const int N = 1e4 + 50;
const int M = 1e5 + 50;
int n, m;
int u, v;
int color[1000];//������ɫ��1 or -1��
vector<int> G[1000];
struct edge {
	int v, next;
};
//������ȾΪ1��-1
bool dfs(int v, int c) {
	color[v] = c;//������ȾΪ��ɫc
	for (int i = 0; i < G[v].size(); i++) {
		//���������ɫ��ͬ���򷵻�false
		if (color[G[v][i]] == c) return false;
		//������ڵĶ���δ��Ⱦɫ����Ⱦ��-c
		if (color[G[v][i]] == 0 && !dfs(G[v][i], -c)) return false;
	}
	return true;
}
int main() {
	int t;
	cin >> t;
	//����ͼ
	while (t--) {
		scanf_s("%d %d", &n, &m);
		for (int i = 1; i <= n; i++) {
			G[i].clear();
		}
		while (m--) {
			int s, t;
			scanf_s("%d %d", &s, &t);
			G[s].push_back(t);//��s��t����
			G[t].push_back(s);//��t��s����
		}
	}
	memset(color, 0, sizeof(color));
	for (int i = 0; i <= n; i++) {
		if (color[i] == 0) {
			//�������i��û��Ⱦɫ����ȾΪ1
			if (!dfs(i, 1)) {
				printf("No\n");
				break;
			}
		}
	}
	printf("Yes\n");
	return 0;
}
