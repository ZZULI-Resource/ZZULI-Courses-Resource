//双链表
#include <stdio.h>
#include <stdlib.h>
typedef int elemtype;
typedef struct Lnode {
	elemtype data;
	struct Lnode* next;
	struct Lnode* prev;
}Lnode, * Linklist;
//带头结点的双链表初始化
bool headinsert(Linklist& L, elemtype e) {


	Lnode* s = (Lnode*)malloc(sizeof(Lnode));
	s->data = e;
	s->next = L->next;
	L->next = s;
	s->prev = L;
	return true;




}
//尾插法
bool endinsert(Linklist& L, int* e, int n) {
	Lnode* r, * s;
	r = L;
	for (int i = 0; i < n; i++) {
		s = (Lnode*)malloc(sizeof(Lnode));
		s->data = e[i];
		s->prev = r;
		s->next = r->next;
		r->next = s;
		r = s;
	}
	r->next = NULL;
	return true;
}
void init(Linklist& L) {
	L = (Lnode*)malloc(sizeof(Lnode));
	L->next = NULL;
	L->prev = NULL;
}
void printfl(Linklist L) {
	if (L->next == NULL) {
		return;
	}
	while (L->next != NULL) {
		printf("%d    ", L->next->data);
		L = L->next;
	}
}
Linklist byorder(Linklist L, int i) {
	if (L->next == NULL) {
		return L->next;
	}
	Linklist s = L->next;
	int j = 1;
	if (i == 1) {
		return s;
	}
	while (s != NULL && j < i) {
		s = s->next;
		j++;


	}
	return s;
}
bool deleteLnode(Linklist& L, int i, elemtype& e) {
	if (i < 1) {
		return NULL;


	}
	Linklist s = byorder(L, i);


	Linklist s1 = s->next;
	Linklist s0 = s->prev;
	if (s1 == NULL) {
		s0->next = NULL;
		free(s1);
		return true;


	}
	s0->next = s1;
	s1->prev = s0;
	free(s);
	return true;




}
int main()
{
	Linklist L;
	init(L);
	/*headinsert(L,1);
	headinsert(L, 4);
	headinsert(L, 7);*/
	int a[4];
	for (int i = 0; i < 4; i++)
	{
		a[i] = i + 1;


	}
	endinsert(L, a, 4);
	printf("%d\n", byorder(L, 1)->data);
	elemtype e;
	deleteLnode(L, 0, e);
	printfl(L);
}