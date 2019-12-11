#include<iostream>
using namespace std;
const int MAX_N = 1000 + 10;
int n, m, M;
int dp[MAX_N][MAX_N];
void solve() {
	int i, j;
	dp[0][0] = 1;
	for (i = 1; i <= m; i++) {
		for (j = 0; j <= n; j++) {
			if ((j - i)>=0) {
				dp[i][j] = (dp[i][j - i] + dp[i - 1][j]) % M;
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	cout << dp[m][n] << endl;
}
int main() {
	cout << "M=";
	cin >> M;
	cout << "n=";
	cin >> n;
	cout << "m=";
	cin >> m;
	solve();
	return 0;
}