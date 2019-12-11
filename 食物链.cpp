//DΪ˵��������
//D=1��X��Yͬ�ࣻD=2��X��Y
//N������������K����Ϣ����
#include<iostream>
using namespace std;
int n;
int f[50005];//���游�ڵ�
int r[50005];//�����ϵ��0��ͬ�࣬1���Ը��ڵ㣬2�������ڵ��
int find(int p) {
	//���ҽ�㣬���ز��鼯�ĸ��ڵ�
	int fp = p;
	if (p != f[p]) {
		fp = find(f[p]);//ѹ��·��
		r[p] = (r[p] + r[f[p]]) % 3;//��ٷ�
		f[p] = fp;
	}
	return f[p];
}
int Union(int d, int x, int y) {
	//�ϲ����ڵ����ڵļ���
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
		//��ʼ�����ڵ㣬ÿ�����ڵ�Ϊ�Լ�����ϵΪͬ��
		f[i] = i;
		r[i] = 0;
	}
	for (int i = 0; i < k; i++) {
		(cin >> d >> x >> y).get();
		if (x > n || y > n || (d == 2 && x == y)) {
			//������Ϣ
			ans++;
			continue;
		}
		if (Union(d, x, y))ans++;
	}
	cout << ans << endl;
	return 0;
}