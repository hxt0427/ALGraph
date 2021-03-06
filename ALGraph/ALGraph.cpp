// ALGraph.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include"ALGraph.h"
#include"TuopuSort.h"
int main()
{
   //测试图的创建和输出
	/*ALGraph g("ABCD");
	g.addArc(0, 2);
	g.addArc(0, 1);
	g.addArc(2, 3);
	g.addArc(3, 0);
	g.addArc(0,3);
	g.output();*/
	/*int  in[4];
	findIndegree(g, in);
	for (int i = 0; i < 4; i++)
		cout << in[i] << " ";*/
	ALGraph G("123456789", 1);
	int in[10];
	G.addArc(0, 1);
	G.addArc(0, 2);
	G.addArc(0, 3);
	G.addArc(1, 4);
	G.addArc(2, 4);
	G.addArc(3, 5);
	G.addArc(4, 6);
	G.addArc(4, 7);
	G.addArc(5, 7);
	G.addArc(6, 8);
	G.addArc(7, 8);
	try {
		topSort(G,in);
	}
	catch (char * ex)
	{
		printf("%s\n", ex);
	}
	return 0;

}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
