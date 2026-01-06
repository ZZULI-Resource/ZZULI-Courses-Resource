#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

#include <stdlib.h>
#define MAX 6
bool read[MAX] = {false,false,false,false,false};

typedef struct elemtype {
	char vex[MAX];
	bool exist;
}elemtype;//删除结点是有可以使用
typedef struct {
	
	char vex[MAX];//顶点表
	int edge[MAX][MAX];//邻接矩阵
	int vexnum, edgenum;//顶点数，边数
	

}Graph;
void init(Graph& G) {
	G.vexnum = 0;
	G.edgenum = 0;
	printf("图初始化成功\n");
}
bool judgeVex(Graph G, char x) {
	for (int i = 0; i < G.vexnum; i++) {
		if (x == G.vex[i]) {
			return true;
		}
	}
	return false;
}
void createGraph(Graph& G) {
	char a = 'A';
	for (int i = 0; i < MAX-1; i++) {
		G.vex[i] = a;
		a++;
		G.vexnum++;
	}
	for (int j = 0; j < MAX; j++) {
		for (int k = 0; k < MAX; k++) {
			G.edge[j][k] = 0;
		}
	}
	for (int z = 1; z < G.vexnum; z++) {
		G.edge[0][z]++;
		G.edgenum++;
	}
	for (int z = 1; z < G.vexnum; z++) {
		G.edge[z][0]++;
		
	}

	//暂定图为A与BCDE顶点都有一条边
	//A对应的二维数组下标为0类推
	
}
int NoWaydu(Graph G) {
	int result=0;
	for (int i = 0; i < G.vexnum; i++) {
		for (int j = 0; j < G.vexnum; j++) {
			if (G.edge[i][j ]== 1) {
				result++;
		}
		}
		
	}
	return result/2;

}
int HaveWayDu(Graph G, char C, int L) {
	int result = 0;
	int   i = 0;
	if (L) {

		for (i = 0; i < G.vexnum; i++) {
			if (C == G.vex[i]) {
				break;
			}
		}
		
			for (int k = 0; k < G.vexnum; k++) {
				if (G.edge[i][k] == 1) {
					result++;
				}
			}

		
	return result;
}
	
	else {
		for (int i = 0; i < G.vexnum; i++) {
			if (C == G.vex[i]) {
				break;
			}
		}for (int j = 0; j < G.vexnum; j++) {
				
					if (G.edge[j][i] == 1) {
						result++;
					
				}

			}
		
		return result;
	}
}
int charCHANGEint(Graph G, char x) {
	for (int i = 0; i < G.vexnum; i++) {
		if (x == G.vex[i]) {
			return i;
		}
}
	return -1;
}

bool judgeisEdge(Graph G, char x, char y) {//判断是否顶点是否存在边
	int x1 = charCHANGEint(G, x);
	int y1 = charCHANGEint(G, y);
	if (x1 == -1 || y1 == -1) {
		return false;
	}
	if (G.edge[x1][y1] == 1) {
		return true;
	}
	return false;
}
int* neighbor(Graph G, char x) {//找出与x结点邻接的顶点
	int data[MAX];
	int x1 = charCHANGEint(G, x);
	
	for (int i = 0; i <G.vexnum; i++) {
		data[i] = 0;
		if (G.edge[x1][i] == 1) {
			data[i]++;
		}
	}
	return data;
}
void printfListChar(int* data,Graph G) {
	int sum = 0;
	for (int i = 0; i < G.vexnum; i++) {
		if (data[i] == 1) {
			printf("%c    ", G.vex[i]);
			sum++;
		}
		
	}
	if (sum == 0) {
		printf("无相邻顶点");
	}
}
bool insertpoint(Graph& G, char x) {
	for (int i = 0; i < G.vexnum; i++) {
		if (x == G.vex[i])
			return false;
	}
	if (G.vexnum == MAX) {
		return false;
	}
	G.vexnum++;
	return true;
}
bool addedge(Graph& G, char x, char y) {
	if (!judgeisEdge(G, x, y)) {
		int x1 = charCHANGEint(G, x);
		int y1 = charCHANGEint(G, y);
		G.edge[x1][y1]++;
		G.edge[y1][x1]++;
		return true;
	}
	else {
		return false;
	}
	
}
void removeedge(Graph& G, char x, char y) {
	if (judgeVex(G, x) && judgeVex(G, y) ){
		int x1 = charCHANGEint(G, x);
			int y1 = charCHANGEint(G, y);
			if (judgeisEdge(G, x, y)) {
				G.edge[x1][y1]--;
					G.edge[y1][x1]--;
					printf("已删除\n");
					return;
			}
		printf("未有该边，删除失败\n");


	}
	printf("无顶点");
}
void FirstNeighbor(Graph G, char x) {
	if (judgeVex(G, x)) {


		int x1 = charCHANGEint(G, x);
			for (int i = 0; i < G.vexnum; i++) {
				if (G.edge[x1][i] == 1) {
					printf("%c\n", G.vex[i]);
						return;
				}


			}
		printf("该结点无边\n");
	}
	printf("无该结点\n");
}
int NextNeigor(Graph G, char x) {
	int x1 = charCHANGEint(G, x);
	
	
	if (judgeVex(G,x)) {
		for (int i = 0; i < G.vexnum; i++) {
			if (G.edge[x1][i] == 1 && read[i] == false) {
				
				
				
				printf("%c", G.vex[i]);
				read[x1] = true;
					return i;
					
					
				
			}
		}
		printf("无下一个边\n");
		return -1;
	}
	printf("无该结点");
}
int main() {
	Graph G;
	init(G);
	createGraph(G);
	//printf("%d", NoWaydu(G));
	//printf("%d\n", HaveWayDu(G, 'A', 0));
	/*if (judgeisEdge(G, 'A', 'E')) {
		printf("存在边\n");
	}
	else {
		printf("不存在边\n");
	}
	printfListChar(neighbor(G, 'E'), G);
	if (insertpoint(G, 'F')) {
		printf("插入成功\n");
	}
	else {
		printf("插入失败\n");
	}*/
	addedge(G, 'C', 'D');
	removeedge(G, 'B', 'A');
	//printfListChar(neighbor(G, 'A'), G);
	//printfListChar(neighbor(G, 'D'), G);
	FirstNeighbor(G, 'B');
	//NextNeigor(G, 'A');
	int x=NextNeigor(G,G.vex[NextNeigor(G, 'A')]);
}