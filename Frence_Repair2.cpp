//每次从板里取出长度最短的两块，并把长度之和加入集合
#include<iostream>
#include<queue>
using namespace std;
typedef long long ll;
int N;
int L[1000];
void InputData() {
	cout << "N=" ;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cout << "L[" << i << "]=";
		cin >> L[i];
	}
}
void solve() {
	ll ans = 0;
	//声明一个从小到大取出数值的优先队列,优先取出小的数据
	priority_queue<int, vector<int>, greater<int>> que;//greater<int>内置类型从大到小排序
	for (int i = 0; i < N; i++) {
		que.push(L[i]);
	}
	while (que.size() > 0) {
		//取出最短的木板和次短的木板
		int l1, l2;
		l1 = que.top();
		cout << l1 << endl;
		que.pop();
		l2 = que.top();
		cout << l2 << endl;
		que.pop();
		//两块木板合并
		ans += l1 + l2;
		que.push(l1 + l2);
	}
}
int main() {
	InputData();
	solve();
	return 0;
}