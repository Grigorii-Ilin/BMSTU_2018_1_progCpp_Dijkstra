#pragma once


#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector> 
#include <time.h> 
#include<iomanip>
using namespace std;

const int GRAPH_SIZE = 8;
const int INF = 100000;

class MyGraph
{
private:
	float Array[GRAPH_SIZE][GRAPH_SIZE]; // ������� ������
	float lengthMin[GRAPH_SIZE]; // ����������� ����������
	bool visited[GRAPH_SIZE]; // ���������� �������
	vector<int> bestWay;
	int setwLen;
public:
	
	MyGraph();
	void PrintGraphArray();
	void FindLengthMin();
	void PrintLengthMin();
	void TakeBestWayFromFirstToLast();
	void PrintBestWayFromFirstToLast();
};