//顺序表
#include <stdio.h>
#include <stdlib.h>

#define m  6
typedef int elemtype;
typedef struct
{
	elemtype data[m];
	//数据域

	int length;
}L;
//顺序表的初始化
bool init(L& l) {
	l.length = 0;
	for (int i = 0; i < m - 3; i++) {
		l.data[i] = i;
		l.length++;
	}
	return true;
}
//插入数据
bool insert(L& l, int i, elemtype e) //顺序表l,插入位置，插入元素
{
	if (i<0 || i>l.length - 1 || l.length >= m) {
		return false;
	}
	else {
		for (int j = l.length; j > i; j--) {
			l.data[j] = l.data[j - 1];
			l.data[i] = e;


			l.length++;
		}

		return true;
	}
}
bool deletedata(L& l, int i, elemtype& e1)
//顺序表，删除的位置，储存删除的值
{
	if (i<0 || i>l.length - 1 || l.length >= m) {
		return false;
	}
	else {
		for (int j = i; j <= l.length - 1; j++) {
			e1 = l.data[i - 1];
			l.data[j - 1] = l.data[j];
		}
		l.length--;
		return true;
	}
}
//按值查找
int get(L l, int i) {


	int j = 0;
	for (int j = 0; j <= l.length - 1; j++) {
		if (i == l.data[i]) {
			return i;
		}
		continue;
	}
	return -1;

}
//按序查找
int getlocation(L l, int i) //次序为顺序表的第i个元素
{
	if (i<1 || i>l.length) {
		return -1;
	}
	int j = 0;

	while (j <= l.length - 1) {

		if (j == i)
			return l.data[i - 1];
		j++;
	}
}
//按顺序输出
void printl(L l) {
	for (int i = 0; i < l.length; i++) {
		printf("%d  ", l.data[i]);
	}
}
int main() {
	L  l;
	elemtype e, e1 = 0;

	if (init(l)) {
		printf("初始化成功\n");
	}
	else
	{
		printf("初始化失败\n");
	}

	scanf("%d", &e);
	if (insert(l, 2, e)) {
		printf("插入成功\n");
	}
	printl(l);
	if (deletedata(l, 2, e1)) {
		printf("删除成功\n");
		printf("删除的数据为%d\n", e1);
		printl(l);

	}
	else {
		printf("删除失败，请重试");
	}
	if (get(l, 1) == -1) {
		printf("无数据，请重新输入");
	}
	else {
		printf("存在该数据，下标为%d", get(l, 1) + 1);
	}
	if (getlocation(l, 2) == -1) {
		printf("错误\n");
	}
	else {
		printf("该下标在表中的值为%d", getlocation(l, 2));
	}
}

