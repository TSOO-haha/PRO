//ÿ�δӰ���ȡ��������̵����飬���ѳ���֮�ͼ��뼯��
#include<iostream>
#include<queue>
using namespace std;
typedef long long ll;
int N;
int L[1000];
void InputData() {
	cout << "N=" ;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cout << "L[" << i << "]=";
		cin >> L[i];
	}
}
void solve() {
	ll ans = 0;
	//����һ����С����ȡ����ֵ�����ȶ���,����ȡ��С������
	priority_queue<int, vector<int>, greater<int>> que;//greater<int>�������ʹӴ�С����
	for (int i = 0; i < N; i++) {
		que.push(L[i]);
	}
	while (que.size() > 0) {
		//ȡ����̵�ľ��ʹζ̵�ľ��
		int l1, l2;
		l1 = que.top();
		cout << l1 << endl;
		que.pop();
		l2 = que.top();
		cout << l2 << endl;
		que.pop();
		//����ľ��ϲ�
		ans += l1 + l2;
		que.push(l1 + l2);
	}
}
int main() {
	InputData();
	solve();
	return 0;
}