#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#define MaxSize 5
typedef int elemtype;
//栈
//特点：先入后出
typedef struct {
	elemtype data[MaxSize];//数据域
	int top;//栈顶指针
}ostack;
//初始化空栈
void init(ostack& O) {
	O.top = -1;
	
}
bool isnull(ostack O) {
	if (O.top == -1) {
		printf("栈为空\n"); 
		return false;
	}
	printf("栈不为空\n");
	return true;
}
bool isfull(ostack O) {
	if (O.top == MaxSize-1) {
		printf("栈已满\n");
		return true;
	}
	printf("栈未满\n");
	return false;
}
bool insert(ostack &O,elemtype e) {
	if (isfull(O)) {
		
		return false;
	}
	O.data[O.top + 1] = e;
	O.top++;
	return true;
}
void printfo(ostack O) {
	for (int i = 0; i <= O.top; i++) {
		printf("%d  ", O.data[i]);
	}
}
bool deletedata(ostack& O, elemtype e) {
	if (!isnull(O)) {
		return false;
	}
	e = O.data[O.top];
	O.top--;
	return true;
}
bool ReadTop(ostack O,elemtype e) {
	if (!isnull(O)) {
		return false ;
	}
	e = O.data[O.top];
	printf("%d   ", e);
	return true;
}
int main() {
	ostack O;
	elemtype e=0;
	init(O);
	isnull(O);
	insert(O, 1);
	insert(O, 2);
	insert(O, 3);
	insert(O, 4);
	insert(O, 5);
	//deletedata(O, e);
	ReadTop(O, e);
	printfo(O);
}