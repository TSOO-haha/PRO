#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
//用字典序比较S和反转字符串S'
//若S较小取S放末尾
//若S'较小取S'
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
		//左起和右起的字符串比较
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