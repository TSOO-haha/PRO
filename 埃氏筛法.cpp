#include<iostream>
using namespace std;
#define MAX_N 1000000
int n;
int prime[MAX_N];//��i������
bool is_prime[MAX_N];//is_prime[i]Ϊtrue��ʾiΪ����
//����n���ڵ�����
int sieve(int n) {
	int p = 0;
	//��ʼ��
	for (int i = 0; i <= n; i++) {
		is_prime[i] = true;
	}
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i <= n; i++) {
		if (is_prime[i]) {
			prime[p++] = i;
			//i�ı�����������
			for (int j = 2*i; j <= n; j+=i ){
				is_prime[j] = false;
			}
		}
	}
	for (int i = 0; i < p; i++) {
		cout << prime[i] << "   ";
	}
	cout << endl;
	return p;
}
int main() {
	cout << "n=";
	cin >> n;
	int p = sieve(n);
	cout << "һ����" << p << "������" << endl;
	return 0;
}