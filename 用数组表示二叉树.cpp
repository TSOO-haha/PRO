#include<iostream>
using namespace std;
int heap[1000], sz = 0;
//����ֵ
void push(int x) {
	//�Լ��ڵ�ı��
	int i = sz++;
	while (i > 0) {
		//���׽ڵ�ı��
		int p = (i - 1) / 2;
		//����Ѿ�û�д�С�ߵ����˳�
		if (heap[p] <= x)break;
		//���׽ڵ���Լ�����
		heap[i] = heap[p];
		i = p;
	}
	heap[i] = x;
}
//ȡ����Сֵ
int pop() {
	int ret = heap[0];//��Сֵ
	//Ҫ�ᵽ������ֵ
	int x = heap[--sz];
	//�Ӹ���ʼ���½���
	int i = 0;
	while (i * 2 + 1 < sz) {
		//�Ƚ϶��ӵ�ֵ
		int a = i * 2 + 1;
		int b = i * 2 + 2;
		if (b < sz && heap[b] < heap[a])a = b;
		if (heap[a] >= x)break;
		//�ͽ�Сֵ�Ķ��ӽ���
		heap[i] = heap[a];
		i = a;
	}
	heap[i] = x;
	return ret;
}
int main() {
	return 0;
}