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
}stack;
typedef struct {
	stack containstack;//储存栈
	stack outstack;//输出栈
}Line;
//初始化
void init(Line& L) {
		L.containstack.top = -1;
		L.outstack.top = -1;
}
//判栈空
bool isStackNull(stack s) {
	if (s.top == -1) 
	{
		return true;
	}
	return false;
}
//判栈满
bool isStackFull(stack s)
{
	if (s.top == MaxSize - 1)
	{
		return true;
	}
	return false;
}
bool isLineNULL(Line L){
	if (L.containstack.top == -1&&L.outstack.top==-1) {
		return true;
}
	else {
		return false;
	}
}
//判队满
bool isLineFull(Line L) {

	//1，存储满，输出未满，先将输出栈全部输出完之后才能将存储栈进
	// 2，输出满，存储未满，
	// 3，存储与输出都满，
	//有两种已满的情况，一种是存储栈满，但输出栈不满，只可以出队不能入队，另一种满的情况是存储栈与输出栈全满，也是只能出队不能入队，
	if (L.containstack.top == MaxSize - 1) {
		return true;
	}
	return false;
}
//出栈
bool outstack(stack& s, elemtype &e) {
	if (isStackNull(s)) {
	 	return false ;
	}
	e = s.data[s.top];
	s.top--;
	return true;
}
//入栈

bool insertstack(stack& s, elemtype& e) {
	if (isStackFull(s)) {

		return false;
	}
	s.data[s.top + 1] = e;
	s.top++;
	return true;
}
//出队
bool outline(Line& L, elemtype &e)
{
	int result[MaxSize];
	
	if (!isLineNULL(L)) {
		int k = L.containstack.top;
		for (int i = 0; i <= k; i++) 
		{
			//把所有存储栈里的元素全部出栈，然后再全部入栈到输出栈里
			outstack(L.containstack, result[i]);
			insertstack(L.outstack, result[i]);
		}
		
		outstack(L.outstack, e);
		printf("%d\n", e);
		return true;
	}
	return false;
}
//入队
bool insertLine(Line& L,elemtype e) {
	if (!isLineFull(L)) {
		L.containstack.data[++L.containstack.top] = e;
		return true;
}
	return false;
}
int main(){
	Line L;
	init(L);

	
	insertLine(L, 35);
	insertLine(L, 34);
	insertLine(L, 33);
	insertLine(L, 32);
	insertLine(L, 31);
	insertLine(L, 30);
	int e = 134564;
	outline(L, e);
	int e1 = 0, e2 = 0,e3 = 0,e4 = 0,e5=0;
	outline(L, e1);
	outline(L, e2);
	outline(L, e3);
	outline(L, e4);
	outline(L, e5);

	
}