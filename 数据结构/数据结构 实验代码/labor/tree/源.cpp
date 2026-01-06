#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
//构造二叉排序树
typedef int elemtype;
typedef struct tree{
	elemtype data;
	tree* leftchild, * rightchild;
}*treepoint;

treepoint createpoint(elemtype e) {
	treepoint r= (tree*)malloc(sizeof(treepoint));
	r->data = e;
	return r;
 }
void init(treepoint &r, elemtype e) {
	if (r == NULL) {
		r = createpoint(e);
		r->leftchild = NULL;
		r->rightchild = NULL;
		
		return ;
	}
}
void insert(treepoint& r, elemtype e) {
	//递归思想

	if (r == NULL) {
		init(r, e);
		return;
	}
	if (e > r->data) {

		insert(r->rightchild, e);
	}
	else if (e < r->data) {
	insert(r->leftchild, e);
	}
	else {
		r->data = e;
	}
	
}
//对结点进行操作输出
void visit(treepoint r) {
	printf("%d    ", r->data);
}
//前序遍历，左中右
void preorder(treepoint r) {
	if (r != NULL) {
		preorder(r->leftchild);
		visit(r);
	
		preorder(r->rightchild);
	}
}
/// 中序遍历 中左右
void midorder(treepoint r) {
	if (r != NULL) {
		visit(r);
		midorder(r->leftchild);
		midorder(r->rightchild);
	}
}///后序遍历 左右中
void lastorder(treepoint r) {
	if (r != NULL) {
		lastorder(r->leftchild);
		lastorder(r->rightchild);
		visit(r);
	}
}
int main() {
	treepoint r=NULL;
	init(r,1);
	insert(r, 5);
	insert(r, 8);
	insert(r, 0);
	insert(r, 4);
	insert(r, -1);
	insert(r, 9);
	insert(r, 10);
	lastorder(r);
}