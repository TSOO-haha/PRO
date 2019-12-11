//使用从大到小的顺序依次取出数值的优先队列
#include<iostream>
#include<queue>
using namespace std;
int L;//总距离长度
int P;//初始油量
int N;//加油站数量
int MAX_N = 10000;
int A[10000 + 1], B[10000 + 1];
void inputdata() {
	cout << "L=";
	cin >> L;
	cout << "N=";
	cin >> N;
	cout << "P=";
	cin >> P;
	for (int i = 0; i < N; i++)
	{
		cout << "A[" << i << "]=";
		cin >> A[i];
	}
	for (int i = 0; i < N; i++)
	{
		cout << "B[" << i << "]=";
		cin >> B[i];
	}
}
void solve() {
	//将终点也认为为加油站
	A[N] = L;
	B[N] = 0;
	N++;
	//维护加油站的优先队列
	priority_queue<int> que;
	//ans:加油次数，pos:现在的位置，tank:邮箱中汽油的量
	int ans = 0, pos = 0, tank = P;
	for (int i = 0; i < N; i++) {
		//接下来前进的距离
		int d = A[i] - pos;
		//不断加油直到油量足够行驶到下一个加油站
		while (tank - d< 0) {
			if (que.empty()) {
				puts("-1");
				return;
			}
			cout << que.top() << endl;
			tank += que.top();
			que.pop();
			ans++;
		}
		tank -= d;
		pos = A[i];
		que.push(B[i]);
	}
	cout << ans << endl;
}

int main() {
	inputdata();
	solve();
	return 0;
}
