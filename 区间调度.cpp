#include<iostream>
#include<algorithm>
using namespace std;
//ÿ��ѡȡ����ʱ������Ĺ���
const int MAX_N = 100000;
int N, S[MAX_N], T[MAX_N];
//���ڶԹ��������pair������
pair<int, int> itv[MAX_N];
void input_data()
{
	cout << "N=" ;
	cin >> N;
	for (int i = 0; i < N; i++){
		cout << "S[" << i << "] = ";
		cin >> S[i];
		cout<< "T[" << i << "] = ";
		cin >> T[i];
	}
}
void solve() {
	//�ֵ���Ƚ�
	//��������ʱ����Ĺ�������ǰ�棬T����first,S����second
	for (int i = 0; i < N; i++) {
		itv[i].first = T[i];
		itv[i].second = S[i];
	}
	sort(itv, itv + N);//����һ��Ԫ������
	//tΪ�����������ѡ�Ľ���ʱ��
	int ans = 0, t = 0;
	for (int i = 0; i < N; i++) {
		if (t < itv[i].second) {
			ans++;
			t = itv[i].first;
		}
	}
	cout << ans;
}
int main() {
	input_data();
	solve();
	return 0;
}