#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define MAX 100
int fa[MAX],r[MAX];
int sum;
/*******����ͼ�����ݽṹ********/
struct edge {
	int from, to;
	int cost;
};
/********�������鼯*********/
//��ʼ��nԪ��
void init(int i) {
	r[i] = 0;//���ĸ߶�
	fa[i] = i;
}
//���Ҹ��ڵ�
int find(int x) {
	return (fa[x] == x ? x : (fa[x] = find(fa[x])));
	/*
	if(fa[x]==x)return x;
	else return fa[x]=find(fa[x])
	*/
}
//�ϲ��ڵ�
void union_set(int x, int y, int cost) {
	if (r[x] > r[y]) {
		r[y] = x;
	}
	else if (r[x] < r[y]) {
		r[x] = y;
	}
	else {
		r[x]++;
		r[y]++;
	}
	sum += cost;
}
bool compare(edge a, edge b) {
	if (a.cost != b.cost) {
		return a.cost < b.cost;
	}
	else {
		return a.from < b.from;
	}
}
void kustral(vector<edge> &e, int m,int n) {
	sort(e.begin(), e.end(), compare);
	sum = 0;
	for (int i = 0; i < n; i++) {
		int x = find(e[i].from);
		int y = find(e[i].to);
		int w = e[i].cost;
		if (x != y) {
			union_set(x, y, w);
		}
	}
	cout << sum << endl;
}
int main() {
	int x, y, w;
	int m, n;//mΪ������nΪ����
	cout << "�����������������" << endl;
	cin >> n >> m;
	vector<edge> e(m);
	cout << "��������ߵ���㡢�յ��Ȩֵ(from to cost):" << endl;
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> w;
		e[i].from = x;
		e[i].to = y;
		e[i].cost = w;
		init(x), init(y);
	}
}