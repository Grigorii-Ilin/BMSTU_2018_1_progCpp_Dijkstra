// Dijkstra.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "header.h"
#pragma warning(disable:4996)
using namespace std;



int main()
{
	setlocale(LC_ALL, "");

	MyGraph g;
	g.PrintGraphArray();
	g.FindLengthMin();
	g.PrintLengthMin();
	g.TakeBestWayFromFirstToLast();
	g.PrintBestWayFromFirstToLast();

	system("Pause");
    return 0;
}

MyGraph::MyGraph() 
{ 
	srand(time(NULL));

	for (size_t i = 0; i<GRAPH_SIZE; i++)
	{
		Array[i][i] = 0;
		for (size_t j = i + 1; j<GRAPH_SIZE; j++)
		{
			Array[i][j] = Array[j][i]= (50+rand()) * (j-i)/100.0;
		}
	}

	for (size_t i = 0; i<GRAPH_SIZE; i++)
	{
		lengthMin[i] = INF;
		visited[i] = false;
	}

	setwLen = 10;
	cout << "Граф построен" << endl;
}

void MyGraph::PrintGraphArray()
{
	cout << setw(setwLen) << "";
	for (size_t i = 0; i < GRAPH_SIZE; i++)
	{
		cout << setw(setwLen) << i+1;
	}
	cout << endl;

	for (size_t i = 0; i < GRAPH_SIZE; i++)
	{
		cout << setw(setwLen) << i + 1;
		for (size_t j = 0; j < GRAPH_SIZE; j++)
		{
			cout << setw(setwLen) << Array[i][j];
		}
		cout << endl;
	}
}	

void MyGraph::FindLengthMin()
{	
	lengthMin[0] = 0;
	while (true) 
	{
		int minIndex = INF;
		float min = INF;	
		for (size_t i = 0; i<GRAPH_SIZE; i++)
		{
			if ((visited[i] == false) && (lengthMin[i]<min))
			{
				min = lengthMin[i];
				minIndex = i;
			}
		}

		if (minIndex == INF) 
		{
			break;
		}			

		for (size_t i = 0; i<GRAPH_SIZE; i++)
		{
			
			if (Array[minIndex][i] == 0)
			{
				continue;
			}

			float additionalLen = min + Array[minIndex][i];
			if (additionalLen < lengthMin[i])
			{
				lengthMin[i] = additionalLen;
			}		
			
		}
		visited[minIndex] = true;
	} 
}

void MyGraph::PrintLengthMin()
{
	cout <<"Минимальные пути:"<< endl;
	cout << setw(setwLen) << "";
	for (size_t i = 0; i < GRAPH_SIZE; i++)
	{
		cout << setw(setwLen) << lengthMin[i];
	}
	cout << endl;
}

void MyGraph::TakeBestWayFromFirstToLast()
{

	int end = GRAPH_SIZE - 1;
	bestWay.emplace(bestWay.begin(), end+1);
	float weight = lengthMin[end];

	while (end >0) 
	{
		for (size_t i = 0; i<GRAPH_SIZE; i++) // просматриваем все вершины
		{
			if (Array[end][i] == 0)
			{
				continue;
			}
			float temp = weight - Array[end][i]; // определяем вес пути из предыдущей вершины
			if ((int)temp == (int)lengthMin[i]) // если вес совпал с рассчитанным
			{                 // значит из этой вершины и был переход
				weight = temp; // сохраняем новый вес
				end = i;       // сохраняем предыдущую вершину
				bestWay.emplace(bestWay.begin(), i+1);; // и записываем ее в вектор
			}
		}
			
	}
}

void MyGraph::PrintBestWayFromFirstToLast()
{
	cout << "Кратчайший маршрут от 1 до "<< GRAPH_SIZE <<":"<< endl;
	for (size_t i = 0; i < bestWay.size(); i++) {
		cout << setw(setwLen)<< bestWay[i];
	}
	cout << endl;
}