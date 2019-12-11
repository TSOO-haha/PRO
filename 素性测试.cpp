#include<iostream>
#include<vector>
#include<map>
using namespace std;
int n;
//���Բ���
bool is_prime(int n) {
	for (int i = 2; i * i < n; i++) {
		if (n % i == 0)return false;
	}
	return n != 1;
}
//Լ��ö��
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
//�����ֽ�
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
	//���Բ���
	if (is_prime(n)) { cout << "this is prime" << endl; }
	else { 
		//ö��Լ��
		vector<int> divi = divisor(n);
		for (int i = 0; i < divi.size(); i++) {
			cout << divi[i] << "   ";
		}
		cout << endl;
		//�ֽ�����
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