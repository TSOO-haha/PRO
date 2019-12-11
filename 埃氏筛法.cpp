#include<iostream>
using namespace std;
#define MAX_N 1000000
int n;
int prime[MAX_N];//第i个素数
bool is_prime[MAX_N];//is_prime[i]为true表示i为素数
//返回n以内的素数
int sieve(int n) {
	int p = 0;
	//初始化
	for (int i = 0; i <= n; i++) {
		is_prime[i] = true;
	}
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i <= n; i++) {
		if (is_prime[i]) {
			prime[p++] = i;
			//i的倍数不是素数
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
	cout << "一共有" << p << "个素数" << endl;
	return 0;
}