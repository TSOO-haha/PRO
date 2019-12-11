#include<iostream>
#include<algorithm>
using namespace std;
//优先使用大面额的硬币
const int V[6] = { 1,5,10,50,100,500 };
int C[6];//每个面值硬币的数量，例如C[0]=10,C[1]=5,...,C[5]=1
int A;//总数
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
	for (int i = 5; i >= 0; i--) {//首先使用大面值
		int t = min(A / V[i], C[i]);//使用面值为V[i]的数量
		A -= t * V[i];
		cout << "面值" << V[i] << "使用了" << t << "张"<<endl;
		ans += t;
	}
	cout << "一共使用了" << ans << "硬币";
}
int main()
{
	Input_Data();
	solve();
	return 0;
}