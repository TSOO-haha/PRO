//ʹ�ôӴ�С��˳������ȡ����ֵ�����ȶ���
#include<iostream>
#include<queue>
using namespace std;
int L;//�ܾ��볤��
int P;//��ʼ����
int N;//����վ����
int MAX_N = 10000;
int A[10000 + 1], B[10000 + 1];
void inputdata() {
	cout << "L=";
	cin >> L;
	cout << "N=";
	cin >> N;
	cout << "P=";
	cin >> P;
	for (int i = 0; i < N; i++)
	{
		cout << "A[" << i << "]=";
		cin >> A[i];
	}
	for (int i = 0; i < N; i++)
	{
		cout << "B[" << i << "]=";
		cin >> B[i];
	}
}
void solve() {
	//���յ�Ҳ��ΪΪ����վ
	A[N] = L;
	B[N] = 0;
	N++;
	//ά������վ�����ȶ���
	priority_queue<int> que;
	//ans:���ʹ�����pos:���ڵ�λ�ã�tank:���������͵���
	int ans = 0, pos = 0, tank = P;
	for (int i = 0; i < N; i++) {
		//������ǰ���ľ���
		int d = A[i] - pos;
		//���ϼ���ֱ�������㹻��ʻ����һ������վ
		while (tank - d< 0) {
			if (que.empty()) {
				puts("-1");
				return;
			}
			cout << que.top() << endl;
			tank += que.top();
			que.pop();
			ans++;
		}
		tank -= d;
		pos = A[i];
		que.push(B[i]);
	}
	cout << ans << endl;
}

int main() {
	inputdata();
	solve();
	return 0;
}
