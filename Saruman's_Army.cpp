//������߿�ʼ���ǣ������R���ڵ����ҵ㡣Ȼ���Ա�ǵ㿪ʼ
//�ҳ����Ҳ�R������Զ�ĵ�
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int N, R;
int X[100];
void input_data() {
	cout << "N=";
	cin >> N;
	cout << "R="; cin >> R;
	for (int i = 0; i < N; i++) {
		cout << "X[" << i << "]=";
		cin >> X[i];
	}
}
void solve() {
	sort(X, X + N);
	int i=0, ans=0;
	while (i < N) {
		//s��û�б���ǵ�����Ķ˵�
		int s = X[i++];
		//һֱ����ֱ�����볬��R
		while (i < N && X[i] <= s + R) {
			i++;
		}
		//p���¼ӱ�ǵ�λ��
		int p = X[i - 1];
		while (i < N && X[i] <= p + R) {
			i++;
		}
		ans++;
		cout << s<<"  ";
	}
	cout << ans;
}
int main()
{
	input_data();
	solve();
	return 0;
}