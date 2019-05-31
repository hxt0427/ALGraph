#pragma once
#include"ALGraph.h"
#include"../../Queue/Queue/Queue.h"

#define MAX_VERTEX_NUM 9
void findIndegree(ALGraph &G, int *in)
{
	//初始化数组，存储所有结点入度
	VexNode * p = G.vertices;
	ArcNode * q;
	for (int i = 0; i < G.vexnum; i++)
		in[i] = 0;
	for (int i = 0; i < G.vexnum; i++)
	{
		if (p[i].firstarc)
			q = p[i].firstarc;
		else
			continue;
		while(q)
		{
			in[q->adjvex]++;
			q = q->nextarc;
		}
	}
	return;
}
void topSort(ALGraph &G, int *in)
{
	findIndegree(G, in);
	Queue<VexNode> J(10);
	VexNode * p = G.vertices;
	for (int i = 0; i < G.vexnum; i++)
	{
		if (in[i] == 0)
		{
			J.enqueue(p[i]);//入度为0 入队
		}		
	}
	while (J.length) {
		VexNode chu = J.dequeue();
		cout << chu.data << "->";
		ArcNode *q = chu.firstarc;
		while (q)
		{
			in[q->adjvex]--;
			if(in[q->adjvex] == 0)
				J.enqueue(p[q->adjvex]);
			q = q->nextarc;
		}
	}
	return;
}