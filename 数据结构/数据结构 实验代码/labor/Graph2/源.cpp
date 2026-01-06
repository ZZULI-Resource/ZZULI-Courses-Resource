#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

#include <stdlib.h>
#define MAX 6
//邻接表法存储有向图
typedef char VertexType;
typedef struct ArcNode {
	int adjvex;//边与弧指向的位置
	struct ArcNode* next;//指向下一个弧的位置

}ArcNode;//存储弧与边的信息
typedef struct	VNode {
	VertexType data;//顶点数据
	ArcNode* first;//弧数据
	bool exist;

}VNode,AdList[MAX];//存储顶点以及与顶点相连的边或弧
typedef struct {
	AdList vertices;//图的所有顶点
	int vexnum, arcnum;//顶点数与边数
}ALGraph;
void initpoint(ALGraph& AL) {
	AL.arcnum = 0;
		AL.vexnum = 0;
	
		for (int i = 0; i < MAX; i++) {
			//(ArcNode*)malloc(sizeof(ArcNode));
			AL.vertices[i].first =new ArcNode;
			AL.vertices[i].exist = true;
			//AL.vertices[i].first->next = NULL;
		}
}
void init(ALGraph& AL) {
	int i = 0;
	initpoint(AL);
	char a = 'A';
	for (i = 0; i < MAX; i++) {
		if (i == MAX - 1) {
			break;
		}
		AL.vertices[i].data = a;
		a++;
		AL.vexnum++;
		
	}
}
int  charchangeint(ALGraph AL, char x) {
	for (int i = 0; i < AL.vexnum; i++) {
		if (AL.vertices[i].data == x) {
			return i;
		}
	}
	return -1;
}
bool gouzaobian(ALGraph &AL) {
	//A，B，C，D,E形成一个回路
	
		//将A的后面加上B的
		ArcNode* p = new ArcNode;
		p->adjvex = charchangeint(AL, 'B');
		p->next = NULL;
		AL.vertices[charchangeint(AL, 'A')].first->next = p;
		AL.arcnum++;
		//B后面加C
		ArcNode* p1 = new ArcNode;
		p1->adjvex = charchangeint(AL, 'C');
		p1->next = NULL;
		AL.vertices[charchangeint(AL, 'B')].first->next = p1;
		AL.arcnum++;
		//C后面加D；
		ArcNode* p2 = new ArcNode;
		p2->adjvex = charchangeint(AL, 'D');
		p2->next = NULL;
		AL.vertices[charchangeint(AL, 'C')].first->next = p2;
		AL.arcnum++;
		//D后面加E；
		ArcNode* p3 = new ArcNode;
		p3->adjvex = charchangeint(AL, 'E');
		p3->next = NULL;
		AL.vertices[charchangeint(AL, 'D')].first->next = p3;
		AL.arcnum++;
		//E后面加A；
		ArcNode* p4 = new ArcNode;
		p4->adjvex = charchangeint(AL, 'A');
		p4->next = NULL;
		AL.vertices[charchangeint(AL, 'E')].first->next = p4;
		AL.arcnum++;
	
	
	return true;
}
//分别遍历需要判断的两个点对应的有向边链表，如果第一个

bool judgeEdge(ALGraph AL, char x, char y)//以x为弧头，y为弧尾的边是否存在 {
{int x1 = charchangeint(AL, x);
	int y1 = charchangeint(AL, y);
	if (x1 == -1 || y1 == -1||AL.vertices[x1].exist==false&&AL.vertices[y1].exist==false) {
		return false;
	}
	
		ArcNode* p = AL.vertices[x1].first;
		
		while (p->next != NULL && p->adjvex != y1)
		{
			p = p->next;
		}
		if (p->adjvex == y1) {
     return true;
		}
		else {
			return false;
		}
		
	}

//判断是否有该结点
bool isVEX(ALGraph AL, char e) {
	int e1 = charchangeint(AL, e);
	if (e1!=-1) {
		printf("有向图中有该结点\n");

		return true;
	}
	printf("有向图中无该结点\n");
	return false;
}
void showpointEdge(ALGraph AL, char x) {
	int x1 = charchangeint(AL, x);
	if (!isVEX(AL,x1)) {
		printf("无该顶点\n");
		return;
	}
	ArcNode* p = AL.vertices[x1].first;
	while (p->next != NULL) {
		printf("%c", AL.vertices[p->next->adjvex].data);
		p = p->next;
	}
}
bool insertpoint(ALGraph& AL, char e) {
	
	if (!isVEX(AL, e)) {
		
	}
	else {
		return false;
	}
	if (AL.vexnum < MAX) {
		AL.vertices[AL.vexnum].data = e;
		AL.vertices[AL.vexnum].first->next = NULL;
		AL.vexnum++;
		printf("插入成功\n");
		return true;
	}
	else {
		printf("已满，无法进行插入\n");
		return false;
	}
}

bool deletepoint(ALGraph& AL, char x) {
	int x1 = charchangeint(AL, x);
	if (isVEX(AL, x)) {
		for (int i = 0; i < AL.vexnum; i++) {
			
			ArcNode* p = AL.vertices[i].first;
			if (p->next == NULL) {
				continue;
			}
			while (p ->next!= NULL) {
				if (p->next->adjvex == x1) {
					ArcNode* q = p->next;
					if (q->next != NULL)
					{
						p->adjvex = q->next->adjvex;
						p = q->next;

						free(q);
					}
					else {
						break;
					}
				}
				p = p->next;
			}
			//删除结点，并把对应的状态量设为false
			if (i == charchangeint(AL, x)) {
				free(AL.vertices[i].first);
				AL.vertices[i].exist = false;
				AL.vexnum--;
			}
			
		}
		printf("已删除成功\n");
		return true;
	}
	else {
		return false;
	}
}                           //x为头，y为尾
bool addedge(ALGraph& AL, char x,char y) {
	int x1 = charchangeint(AL, x);
	int y1 = charchangeint(AL, y);
	if (x1 != -1 && y1 != -1) {
		if (AL.vertices[charchangeint(AL, x)].exist && AL.vertices[charchangeint(AL, y)].exist) {
			if (judgeEdge(AL, x, y)) {
				printf("已存在边添加失败\n");
				return false;
			}
			else
			{
				ArcNode* p1 = new ArcNode;
				p1->adjvex = charchangeint(AL, y);
				p1->next = NULL;
				ArcNode* p = AL.vertices[charchangeint(AL, x)].first;//把x的对应的链表的第一个储存到p中
				while (p->next != NULL) {
					p = p->next;
					//遍历到结点的最后一个
				}

				//把p是最后一个结点
				p->next = p1;
				AL.arcnum++;
				//添加x与y对应的边
			}
			return true;
		}
	}
	printf("不存在该点\n");
	return false;
}
int  FirstNeighbor(ALGraph AL, char x) {
	int x1 = charchangeint(AL, x);
	if (x1 != -1) {
		if (AL.vertices[x1].first->next == NULL) {
			printf("该结点无边");
			return -1;
		}
		printf("%c\n", AL.vertices[AL.vertices[x1].first->next->adjvex].data);
		return AL.vertices[x1].first->next->adjvex;
	}
	printf("不存在该点\n");
	return -1;

}

int NextNeigor(ALGraph AL, char x ) {
	int x1 = charchangeint(AL, x);
	ArcNode* p = AL.vertices[x1].first;
	int sum = 0;
	for (int i = 0; i <AL.arcnum; i++) {
		if (p->next != NULL) {
			sum++;
			p = p->next;
	}
		else {
			if (sum == 0) {
				printf("该点没有与其他边相连");
				return -1;
			}
			int x2 = charchangeint(AL, AL.vertices[p->adjvex].data);
			ArcNode* p1=AL.vertices[x2].first;
			p = p1->next;
			sum++;
		}
		if (sum == 1) {
			printf("找的点的下一个点没有与其他边相连");
			return -1;
		}
		if (sum == 2) {
			
			printf("%c\n", AL.vertices[p->adjvex].data);
			return p->adjvex;
		}
	}
	return -1;
}
int main() {
	ALGraph AL;
	init(AL);
	//judgeEdge(AL, 'A', 'B');
	gouzaobian(AL);
	if (judgeEdge(AL, 'E', 'B')) {
		printf("有边\n");
	}
	else {
		printf("无边\n");
	}
	showpointEdge(AL, 'A');
	insertpoint(AL, 'F');
	insertpoint(AL, 'G');
		//deletepoint(AL, 'A');
		addedge(AL,'A','F');
	//char x='a', y='b';
	//addedge(AL, x, y);
		//FirstNeighbor(AL, 'F');
		printf("%c\n",AL.vertices[NextNeigor(AL, 'C')].data);
		
}
