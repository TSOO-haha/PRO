#include<iostream>
#include<vector>
#include<map>
using namespace std;
int n;
//素性测试
bool is_prime(int n) {
	for (int i = 2; i * i < n; i++) {
		if (n % i == 0)return false;
	}
	return n != 1;
}
//约数枚举
vector<int> divisor(int n) {
	vector<int> divi;
	for (int i = 2; i * i < n; i++) {
		if (n % i == 0) {
			divi.push_back(i);
			if (i != n / i) divi.push_back(n / i);
		}
	}
	return divi;
}
//整数分解
map<int, int> prime_factor(int n) {
	map<int, int> res;
	for (int i = 2; i * i < n; i++) {
		while (n % i == 0) {
			++res[i];
			n /= i;
		}
	}
	if (n != 1)res[n] = 1;
	return res;
}
int main(){
	cout << "n=";
	cin >> n;
	//素性测试
	if (is_prime(n)) { cout << "this is prime" << endl; }
	else { 
		//枚举约数
		vector<int> divi = divisor(n);
		for (int i = 0; i < divi.size(); i++) {
			cout << divi[i] << "   ";
		}
		cout << endl;
		//分解整数
		map<int, int> divi_vec = prime_factor(n);
		for (int i = 0; i < divi_vec.size(); i++) {
			if (divi_vec[i]!=0) {
				int t = divi_vec[i];
				cout << i << "(" << t << ")" << "   ";
			}
		}
	}

	return 0;
}