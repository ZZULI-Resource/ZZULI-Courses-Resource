#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#define MaxSize 6
//À≥–Ú∂”¡–
typedef int elemtype;
typedef struct {
	elemtype data[MaxSize];
	int front, rear;
}queue;
void init(queue &Q) {
	Q.front = 0;
	Q.rear = 0;
}
bool isnull(queue Q) {
	if (Q.front == Q.rear) {
		return true;
	}
	return false;
}
bool isfull(queue Q) {
	if (Q.rear == MaxSize - 1) {
		return true;
	}
	return false;
}
bool insert(queue &Q, elemtype e) {
	if (!isfull(Q)) {
		Q.data[Q.rear] = e;
		Q.rear++;
		return true;
	}
	return false;
}
bool deletedata(queue& Q, elemtype e) {

	if (!isnull(Q) ){
		e = Q.data[Q.front];
		Q.front++;
		return true;
	}
	return false;
}
int getqueuelength(queue Q) {
	int length = Q.rear - Q.front;
	return length;
}
void printqueue(queue Q) {
	for (int i = Q.front; i < Q.rear; i++) {
		printf("%d    ", Q.data[i]);
	}
}
int main() {
	queue Q;
	elemtype e = 0;
	init(Q);
	insert(Q, 1);
	insert(Q,2);
	insert(Q, 3);
	insert(Q, 4);
	insert(Q, 5);
	insert(Q, 6);
	insert(Q, 7);
	//deletedata(Q, e);
	printqueue(Q);
	printf("%d", getqueuelength(Q));
}