#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Node {
	int start;
	int end;
	int cost;
};
//升序
bool compare(Node a, Node b) {
	return a.cost < b.cost;
}
void Kruskal(vector<Node> &arr,vector<bool> &visited) {
	int M, N;
	M = visited.size();
	N = arr.size();
	cout << "input graph structure(start end cost):" << endl;
	for (int i = 0; i < N; i++) {
		cin >> arr[i].start >> arr[i].end >> arr[i].cost;
	}
	sort(arr.begin(), arr.end(), compare);
	cout << "最小生成树的边：" << endl;
	int weight = 0;
	for (int i = 0; i < N; i++) {
		if (!visited[arr[i].start] || !visited[arr[i].end]) {
			weight += arr[i].cost;
			visited[arr[i].start] = true;
			visited[arr[i].end] = true;
			cout << arr[i].start << "   " << arr[i].end << endl;
		}
	}
	cout << "最小生成树的权值：" << weight << endl;
}
int main() {
	int M, N;//M节点数，N边数
	cin >> M >> N;
	vector<Node> arr(N);
	vector<bool> visited(M);
	Kruskal(arr, visited);
	return 0;
}