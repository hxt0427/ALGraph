#pragma once
#include<iostream>
using namespace std;

struct ArcNode
{
	int adjvex;
	ArcNode * nextarc;
	int info;//弧自带的信息
	ArcNode(int adj, int w)
	{
		adjvex = adj;
		info = w;
		nextarc = NULL;
	}
	void output()
	{
		printf("->(adj=%d,w=%d)", adjvex, info);
	}
};

struct VexNode
{
	char data;
	ArcNode *firstarc;
	VexNode()
	{
		firstarc = NULL;
	}
	~VexNode()
	{
	//	ArcNode *p = firstarc;
	//	ArcNode *q = p;
	//	while (p->nextarc)
	//	{
	//		q = p->nextarc;
	//		delete p;
	//		p = q;
	//	}
	//	delete p;
	}
	void output()
	{
		printf("顶点%c", data);
		ArcNode* p = firstarc;
		while (p)
		{
			p->output();
			if (p->nextarc)
				p = p->nextarc;
			else
				break;
		}
		printf("\n");
	}
	void addArc(int adj, int w)		//向顶点添加弧
	{
		ArcNode *p = new ArcNode(adj, w);
		p->nextarc = firstarc;
		firstarc = p;
	}
};

struct ALGraph		//(邻接链表方式存储的)图
{
	VexNode *vertices;
	int vexnum;//顶点数量
	int kind;//图的种类，0-无向图，1-有向图
	ALGraph(const char *names, int k = 1)
	{
		//传入一个字符串，根据其中字符为每个结点命名
		kind = k;
		vexnum = strlen(names);
		vertices = new VexNode[vexnum];
		for (int i = 0; i < vexnum; i++)
		{
			vertices[i].data = names[i];
		}
			
	}
	~ALGraph()
	{
		delete vertices;
	}
	void output()
	{
		//输出图
		for (int i = 0; i < vexnum; i++)
			vertices[i].output();
	}
	void addArc(int tail, int head, int w = 0)
	{
		//向图添加弧
		vertices[tail].addArc(head, w);
		if (kind == 0)//如果是无向图
			vertices[head].addArc(tail, w);
	}
};