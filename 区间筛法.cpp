#include<iostream>
#include<algorithm>
using namespace std;
#define MAX_L 1000000
#define MAX 1000000000
typedef long long ll;
ll a, b;
bool is_prime[MAX_L];//is_prime[i-a] is true iff i is prime
bool is_prime_small[MAX];
int prime[MAX_L];
void segemet_sieve(ll a, ll b) {
	//初始化[a,pow(b,2)]
	for (int i = 0; (ll)i * i < b; i++) {
		is_prime_small[i] = true;
	}
	//初始化[a,b)
	for (int i = 0; i < b - a; i++) {
		is_prime[i] = true;
	}
	for (int i = 2; (ll)i * i < b; i++) {
		if (is_prime_small[i]) {
			//筛[2,pow(b,2)]
			for (int j = 2 * i; (ll)j * j < b; j += i) {
				is_prime_small[j] = false;
			}
			//筛[a,b）
			for (ll j = max(2LL, (a + i - 1) / i) * i; j < b; j+=i) {
				is_prime[j-a] = false;
			}
		}
	}
}
int main() {
	cout << "input a and b(a<b):" << endl;
	cout << "a=";
	cin >> a;
	cout << "b=";
	cin >> b;
	int p = 0;
	segemet_sieve(a, b);
	for (int k = a; k < b; k++) {
		if (is_prime[k - a]) { prime[p++] = k; }
	}
	cout << "一共有" << p << "个素数" << endl;
	for (int i = 0; i < p; i++) {
		cout << prime[i] << "  ";
	}
	cout << endl;
	return 0;
}