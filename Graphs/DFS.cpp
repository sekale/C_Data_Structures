#include <iostream>
#include <unordered_set>
#include <stack>
#include "graph.h"

using namespace std;

void depthFS(Graph *testGraph);
void visitNode(Graph *testGraph, unordered_set<int> &visitedSet, int k);

int main()
{
	Graph *testGraph = new Graph(4);
	testGraph -> addEdge(0,1);
	testGraph -> addEdge(0,2);
	testGraph -> addEdge(2,3);
	testGraph -> addEdge(1,3);
}

void depthFS(Graph *testGraph)
{
	unordered_set<int> visitedSet;
	for(int i = 0; i < testGraph -> getNumberVertices(); ++i)
	{
		if(visitedSet.find(i) != visitedSet.end())
			continue; 
		else
			visitNode(testGraph, visitedSet, i);
	}
}

void visitNode(Graph *testGraph, unordered_set<int> &visitedSet, int k)
{
	int **adjMatrixRef = testGraph -> getAdjMatrix();
	visitedSet.insert(k);
	for(int i = 0; i < testGraph -> getNumberVertices(); ++i)
	{
		if(adjMatrixRef[k][i])
		{
			if(visitedSet.find(i) == visitedSet.end())
			{
				visitNode(testGraph, visitedSet, i);
			}
		}
	}
}