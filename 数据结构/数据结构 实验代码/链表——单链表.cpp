//单链表
#include <stdio.h>

#include <stdlib.h>
typedef int elemtype;
typedef struct LNode {
	elemtype data;
	struct LNode* next;
}LNode, * Linklist;
//带头结点的单链表初始化
bool init(Linklist& L) {

	L = (LNode*)malloc(sizeof(LNode));
	L->next = NULL;
	return true;
}
//头插法
bool headinsert(Linklist& L, elemtype e) {

	Linklist s = (LNode*)malloc(sizeof(LNode));
	s->data = e;
	s->next = L->next;
	L->next = s;
	return true;
}
//尾插法
bool endinsert(Linklist& L, int* a, int n) {
	Linklist s, rear;
	rear = L;
	//必须循环，不然的话尾指针无法保存起来
	for (int i = 0; i < n; i++) {
		s = (LNode*)malloc(sizeof(LNode));
		s->data = a[i];
		s->next = rear->next;
		rear->next = s;
		rear = s;
		rear->next = NULL;
	}

	return true;
}
//按序查找
Linklist  byorder(Linklist L, int i) {
	int j = 1;
	if (i < 1) {
		return NULL;
	}
	Linklist p = L->next;
	//因为是带头结点，所以第一个结点不保存数据，所以要从第2个来
	while (p != NULL && j < i) {
		p = p->next;
		j++;
	}


	return p;
}
//按数据查找

Linklist bydata(Linklist L, elemtype e) {
	int j = 0;

	Linklist p = L->next;
	//因为是带头结点，所以第一个结点不保存数据，所以要从第2个来
	while (p != NULL && p->data != e) {
		p = p->next;
		j++;
	}


	return p;
}
void printlink(Linklist L) {
	while (L->next != NULL) {
		printf("%d  ", L->next->data);
		L = L->next;
	}
}
bool deletedata(Linklist& L, int i, elemtype& e) {
	if (i < 1) {
		return false;
	}
	if (i == 1) {
		Linklist p = byorder(L, 1);
		L->next = p->next;
		e = p->data;
		free(p);
		return true;
	}
	Linklist q = byorder(L, i - 1);
	Linklist p = byorder(L, i);
	q->next = p->next;
	e = p->data;
	free(p);
	return true;
}
bool deletedata2(Linklist& L, elemtype e) {
	Linklist s1 = L;
	Linklist s2 = L->next;

	while (s2->data != e && s2 != NULL) {
		s1 = s1->next;
		s2 = s2->next;
		if (s2 == NULL) {
			return false;
		}
	}
	
	s1->next = s2->next;
	e = s2->data;
	free(s2);
	return true;
	
}
//删除多个值为x的结点
Linklist deletex(Linklist head, elemtype x) {
	//常规写法
	Linklist temp;
	while (head != NULL && head->data == x) {
		temp = head;
		head = head->next;
		free(temp);
	}//处理头节点的数据
	Linklist cur = head;   //直接将temp赋值为cur.next
	while (cur != NULL && (temp = cur->next)) {
		if (temp->data == x) {
			cur->next = temp->next;
			free(temp);
		}
		else {
			cur = cur->next;
		}
		
	}
	return head;
}
//创建个新链表，通过遍历原链表将数据筛选再通过尾插法插入新链表，再将新链表输出

Linklist deletex2(Linklist head, elemtype x) {
	Linklist p = head->next;
	Linklist head2 = (LNode*)malloc(sizeof(LNode));
	head2->next = NULL;
	Linklist rear;
	rear = head2;
	while (p != NULL) {
    if (p->data != x) {
	Linklist s = (LNode*)malloc(sizeof(LNode));
	s->data = p->data;
			s->next = rear->next;
			rear->next = s;
			rear = s;
			rear->next = NULL;


		}
	p = p->next;
	}
	return head2;
}
		
Linklist deletex3(Linklist head, elemtype x) {
	Linklist p = head->next;//将头节点赋给p
	Linklist rear = head , q;//尾结点赋给rear以便于使用尾插法
	head->next = NULL;//断链

	while (p != NULL) {//遍历原链表
		if (p->data != x) {
			rear->next = p;//直接把这个结点放进去
			rear = p;
			p = p->next;//不能将这句提到ifelse外面的原因是因为在else语句中free语句直接将p所指的结点消除，自然也就不会有p->next结点了
		}
		else {
			q = p;
			p = p->next;
			free(q);
			
			
		}
		rear->next = NULL;
	}
	return head;

}
int main() {
	Linklist L;
	int a[4];
	
	if (init(L)) {
		printf("初始化成功\n");
	}
	for (int i = 0; i < 4; i++)
	{
		a[i] = i;

		//	headinsert(L, a[i]);



	}
	endinsert(L, a, 4);
	//printf("%d\n", byorder(L,1)->data);
	elemtype e=1;

//	L=deletex(L, 1);
	L = deletex3(L,0);
	printlink(L);
}