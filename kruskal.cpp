#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Node {
	int start;
	int end;
	int cost;
};
//����
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
	cout << "��С�������ıߣ�" << endl;
	int weight = 0;
	for (int i = 0; i < N; i++) {
		if (!visited[arr[i].start] || !visited[arr[i].end]) {
			weight += arr[i].cost;
			visited[arr[i].start] = true;
			visited[arr[i].end] = true;
			cout << arr[i].start << "   " << arr[i].end << endl;
		}
	}
	cout << "��С��������Ȩֵ��" << weight << endl;
}
int main() {
	int M, N;//M�ڵ�����N����
	cin >> M >> N;
	vector<Node> arr(N);
	vector<bool> visited(M);
	Kruskal(arr, visited);
	return 0;
}