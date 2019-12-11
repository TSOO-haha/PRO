#include<iostream>
using namespace std;
typedef long long ll;
int N, L[1000];
void input_data() {
	cout << "N=";
	cin >> N;
	for (int i = 0; i < N; i++) {
		cout << "L[" << i << "]=";
		cin >> L[i];
	}
}
void solve() {
	ll ans = 0;
	//直到木板长度为l块为止
	while (N > 1) {
		//求出最短的板和次短的板
		int min1 = 0, min2 = 1;
		if (L[min1] > L[min2])swap(min1, min2);
		for (int i = 0; i < N; i++) {
			if (L[i] < L[min1]) {
				min2 = min1;
				min1 = i;
			}
			else if(L[i]<L[min2]){
				min2 = i;
			}
		}
		//将两块板合并
		int t = L[min1] + L[min2];
		ans += t;
		if (min1 == N - 1)swap(min1, min2);
		L[min1] = t;
		L[min2] = L[N - 1];
		N--;
	}
	cout << ans;
}

int main() {
	input_data();
	solve();
	return 0;
}
