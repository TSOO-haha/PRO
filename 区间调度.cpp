#include<iostream>
#include<algorithm>
using namespace std;
//每次选取结束时间最早的工作
const int MAX_N = 100000;
int N, S[MAX_N], T[MAX_N];
//用于对工作排序的pair的数组
pair<int, int> itv[MAX_N];
void input_data()
{
	cout << "N=" ;
	cin >> N;
	for (int i = 0; i < N; i++){
		cout << "S[" << i << "] = ";
		cin >> S[i];
		cout<< "T[" << i << "] = ";
		cin >> T[i];
	}
}
void solve() {
	//字典序比较
	//工作结束时间早的工作排在前面，T放在first,S放入second
	for (int i = 0; i < N; i++) {
		itv[i].first = T[i];
		itv[i].second = S[i];
	}
	sort(itv, itv + N);//按第一个元素排序
	//t为工作最后工作所选的结束时间
	int ans = 0, t = 0;
	for (int i = 0; i < N; i++) {
		if (t < itv[i].second) {
			ans++;
			t = itv[i].first;
		}
	}
	cout << ans;
}
int main() {
	input_data();
	solve();
	return 0;
}