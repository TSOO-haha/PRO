#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
//���ֵ���Ƚ�S�ͷ�ת�ַ���S'
//��S��СȡS��ĩβ
//��S'��СȡS'
const int MAX_N = 2000+10;
char s[MAX_N];
int main() {
	int n;
	cout << "n=";
	cin>>n;
	cout << endl;
	for (int i = 0; i < n; i++) {
		getchar();
		cin >> s[i];
	}
	int a = 0, b = n - 1;
	while (a <= b){
		//�����������ַ����Ƚ�
		bool left = false;
		for (int i = 0; a + i < b; i++){
			if (s[a + i] < s[b - i]) {
				left = true;
				break;
			}
			else if (s[a + i] > s[b - i]) {
				left = true;
				break;
			}
		}
		if (left) putchar(s[a++]);
		else putchar(s[b--]);
	}
	putchar('\n');
	return 0;
}