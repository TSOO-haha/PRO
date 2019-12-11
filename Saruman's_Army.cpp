//从最左边开始考虑，标记其R以内的最右点。然后以标记点开始
//找出其右侧R距离最远的点
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int N, R;
int X[100];
void input_data() {
	cout << "N=";
	cin >> N;
	cout << "R="; cin >> R;
	for (int i = 0; i < N; i++) {
		cout << "X[" << i << "]=";
		cin >> X[i];
	}
}
void solve() {
	sort(X, X + N);
	int i=0, ans=0;
	while (i < N) {
		//s是没有被标记的最左的端点
		int s = X[i++];
		//一直向右直到距离超过R
		while (i < N && X[i] <= s + R) {
			i++;
		}
		//p是新加标记的位置
		int p = X[i - 1];
		while (i < N && X[i] <= p + R) {
			i++;
		}
		ans++;
		cout << s<<"  ";
	}
	cout << ans;
}
int main()
{
	input_data();
	solve();
	return 0;
}