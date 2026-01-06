//链式实现栈
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
typedef int elemtype;
typedef struct cstatck {
	elemtype data;
	struct cstatck* next;
}cstack,*cstacks;
void init(cstacks &C) {
	C = (cstacks)malloc(sizeof(cstack));
	C->next = NULL;
}
//尾插法插入
bool insert(cstacks& C, elemtype* e, int n) {
	cstacks r, s;
	r = C;
	for (int i = 0; i < n; i++) {
		s= (cstacks)malloc(sizeof(cstack));
		s->data = e[i];
		s->next = r->next;
		r->next = s;
		r = s;
		
	}
	return true;
}
cstacks gettop(cstacks C) {
	cstacks s = C->next;
	while (s ->next!= NULL) {
		s = s->next;
	}
	printf("%d  ", s->data);
	return s;
}
void outstack(cstacks &C, elemtype e) {
	cstacks s= gettop(C);
	e = s->data;
	cstacks s1 = C->next;
	while (s1->next != s) {
		s1 = s1->next;
		
	}
	cstacks s2 = s1;
	s2->next = s->next;
	free(s);
	
}
int main() {
	cstacks C;
	elemtype e=0;
	init(C);
	int a[2] = { 1,3 };
	insert(C, a,2);

	gettop(C);
	outstack(C, e);
	gettop(C);
}