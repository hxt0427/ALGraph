#pragma once
#include<iostream>
using namespace std;

struct ArcNode
{
	int adjvex;
	ArcNode * nextarc;
	int info;//���Դ�����Ϣ
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
		printf("����%c", data);
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
	void addArc(int adj, int w)		//�򶥵���ӻ�
	{
		ArcNode *p = new ArcNode(adj, w);
		p->nextarc = firstarc;
		firstarc = p;
	}
};

struct ALGraph		//(�ڽ�����ʽ�洢��)ͼ
{
	VexNode *vertices;
	int vexnum;//��������
	int kind;//ͼ�����࣬0-����ͼ��1-����ͼ
	ALGraph(const char *names, int k = 1)
	{
		//����һ���ַ��������������ַ�Ϊÿ���������
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
		//���ͼ
		for (int i = 0; i < vexnum; i++)
			vertices[i].output();
	}
	void addArc(int tail, int head, int w = 0)
	{
		//��ͼ��ӻ�
		vertices[tail].addArc(head, w);
		if (kind == 0)//���������ͼ
			vertices[head].addArc(tail, w);
	}
};