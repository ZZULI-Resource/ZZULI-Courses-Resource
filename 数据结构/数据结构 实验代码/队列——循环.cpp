//循环队列
#include <stdio.h>
#include <stdlib.h>
#define MaxSize 6//只有五个元素，因为有一个位置用于判断
typedef  int elemtype;
typedef struct {
	elemtype data [MaxSize];
	int front,rear;
}loopq;
void init(loopq &L) {
	L.front = L.rear = 0;

 }
bool  isnull(loopq L){
	if (L.front == L.rear) {
		return  true;
	}
	return false;
}
bool isfull(loopq L) {
	if ((L.rear + 1) % MaxSize == L.front) {
	//牺牲一个数据域数组的空间作为判断队列是否已满，而%MaxSize是为了保证循环队列数据域的取值可以落到0到5之间
		return true;

	}
	return false;

}
int GetLength(loopq L) {
	int length;
	length = (L.rear - L.front+MaxSize) % MaxSize;
	return length;
	//L.rear为上一个数据存储位置的下一个下标的值，
	//若不为循环队列，则长度为L.rear-L.front,由于为循环队列则当L.rear小于L.front时保证计算正确，不然的话就会为负，显然错误
}
bool insert(loopq& L, elemtype e) {
	if (isfull(L)) {
		return false;
	}
	L.data[L.rear] = e;
	L.rear=(L.rear+1)%MaxSize;
	return true;
}
bool deletedata(loopq& L, elemtype e) {
	if (isnull(L)) {
		return false;
	}
	e = L.data[L.front];
	L.front=(L.front+1)%MaxSize;
	return true;

}

int main() {
	loopq L;

	init(L);
	printf("%d    ", GetLength(L));
	insert(L, 1);
	printf("%d    ", GetLength(L));
	insert(L, 2);
	printf("%d    ", GetLength(L));
	elemtype e = 0;

	deletedata(L, e);
	printf("%d    ", GetLength(L));
}
