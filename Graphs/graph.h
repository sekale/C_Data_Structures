#include <iostream>
#define ADJMATRIX
using namespace std;

#ifdef ADJMATRIX
class Graph
{
private:
    int v;
    int **adjMatrix;
public:
    Graph(int n)
    {
        v = n;
        adjMatrix = new int*[n];
        for(int i = 0; i < n; ++i)
        {
            adjMatrix[i] = new int[n];
            for(int j = 0; j < n; ++j)
                adjMatrix[i][j] = 0;
        }
    }

    bool addEdge(int src, int dest)
    {
        if(src < 0 || src >= v || dest < 0 || dest >= v)
            return false;

        adjMatrix[src][dest] = 1;
        return true;
    }

    int getNumberVertices()
    {
        return v;
    }

    int **getAdjMatrix()
    {
        return adjMatrix;
    }
};
#endif

#ifdef ADJLIST

#endif