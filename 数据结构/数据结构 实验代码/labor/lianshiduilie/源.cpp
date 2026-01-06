#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
//链式实现队列
typedef int elemtype;
typedef struct Lnode {
	elemtype data;
	Lnode* next;
}Lnode, *Linklist ;
typedef struct Linkqueue {
	Linklist front, rear;
}Linkqueue;
void init(Linkqueue& L) {
	L.front = L.rear = (Linklist)malloc(sizeof(Lnode));
	L.front->next = NULL;
}
bool insert(Linkqueue& L, elemtype * a,int n) {
	
	for (int i = 0; i <= n - 1; i++) {
		Linklist s = (Linklist)malloc(sizeof(Lnode));
		s->data = a[i];
		
		L.rear->next =s;
		L.rear = s;
		s->next = NULL;

	}
	return true;


}

void chudui(Linkqueue &L,elemtype &e) {
	Linklist s = L.front->next;
	e = s->data;
	L.front->next = s->next;
	free(s);
		printf("%d", e);
		
	}


int main() {
	Linkqueue L;
	init(L);
	int a[4] = {2,4,6,8};
	insert(L, a,4);
	elemtype e = 0;
	chudui(L,e);
	return 0;
}