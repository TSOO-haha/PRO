#include<iostream>
#include<algorithm>
using namespace std;
//����ʹ�ô�����Ӳ��
const int V[6] = { 1,5,10,50,100,500 };
int C[6];//ÿ����ֵӲ�ҵ�����������C[0]=10,C[1]=5,...,C[5]=1
int A;//����
void Input_Data()
{
	cout << "please input the number:" << endl;
	for (int i = 0; i < 6; i++){
		cout << "C_" << V[i] << "=" ;
		cin >> C[i] ;
	}
	cout << "A =" << " ";
	cin >> A;
}
void solve() {
	int ans = 0;
	for (int i = 5; i >= 0; i--) {//����ʹ�ô���ֵ
		int t = min(A / V[i], C[i]);//ʹ����ֵΪV[i]������
		A -= t * V[i];
		cout << "��ֵ" << V[i] << "ʹ����" << t << "��"<<endl;
		ans += t;
	}
	cout << "һ��ʹ����" << ans << "Ӳ��";
}
int main()
{
	Input_Data();
	solve();
	return 0;
}