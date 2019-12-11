#include<iostream>
using namespace std;
int heap[1000], sz = 0;
//插入值
void push(int x) {
	//自己节点的编号
	int i = sz++;
	while (i > 0) {
		//父亲节点的编号
		int p = (i - 1) / 2;
		//如果已经没有大小颠倒则退出
		if (heap[p] <= x)break;
		//父亲节点和自己交换
		heap[i] = heap[p];
		i = p;
	}
	heap[i] = x;
}
//取出最小值
int pop() {
	int ret = heap[0];//最小值
	//要提到根的数值
	int x = heap[--sz];
	//从根开始向下交换
	int i = 0;
	while (i * 2 + 1 < sz) {
		//比较儿子的值
		int a = i * 2 + 1;
		int b = i * 2 + 2;
		if (b < sz && heap[b] < heap[a])a = b;
		if (heap[a] >= x)break;
		//和较小值的儿子交换
		heap[i] = heap[a];
		i = a;
	}
	heap[i] = x;
	return ret;
}
int main() {
	return 0;
}