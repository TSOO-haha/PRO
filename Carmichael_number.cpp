#include<iostream>
#include<string.h>
using namespace std;
const int MAXN =650005;
bool is_prime[MAXN];
typedef long long ll;
void getprime() {
	memset(is_prime, true, sizeof(is_prime));
	for (int i = 2; i <= MAXN; i++) {
		if (is_prime[i]) {
			for (int j = 2 * i; j <= MAXN; j += i) {
				is_prime[j] = false;
			}
		}
	}
}
//二进制思想快速求(a^n)%c
int qmod(int a, int n, int mod) {
	int res = 1;
	while (n > 0) {
		if (n & 1) {//二进制最低位为1，则为奇数
			res = res * a % mod;
		}
		a = a * a % mod;
		n >>= 1;//向右移位n+=1
	}
	return res;
}
int main() {
	int n;
	getprime();
	while (scanf_s("%d", &n), n) {
		bool flag = true;
		if (!is_prime[n]) {
			printf("%d is normal\n", n);
			continue;
		}
		for (int a = 2; a < n; a++) {
			if (qmod(a, n, n) != a) {
				flag = false;
				break;
			}
		}
		if (flag) {
			printf("The number %d is Carmichael number.\n", n);
		}
		else {
			printf("%d is normal\n", n);
		}
	}
	return 0;
}