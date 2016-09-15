#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list> 

using namespace std;

class Graph
{
    private:

    
    public:
        int vertices;
        list<pair<int,int>> *adjacency_list;
        
        Graph(int NumberVertices)
        {
                vertices = NumberVertices;
                adjacency_list = new list <pair<int,int>>[NumberVertices + 1]; //excluding 0, we don't use that
            
        }
        void addEdge(int v, int w);
        void BFS(int s);
};



void Graph::addEdge(int v, int w)
{
    //Undirected Graph
    adjacency_list[v].push_back(make_pair(w,6));
    adjacency_list[w].push_back(make_pair(v,6));
}

void print_graph(Graph *graphObj, int head_node)
{
    //cout << endl << "head node: " << head_node << endl;
    list<pair<int,int>>::iterator itr;
    list<int> visited_nodes;
    list<int>::iterator vnode_iterator;
    
    int i = head_node;
    itr = (graphObj -> adjacency_list[i]).begin();
    //cout << "here: " << (*itr).first; 
    //cout << endl << "list" << i << endl;
    while(itr != (graphObj -> adjacency_list[i]).end())
    {
        //cout << "HERE";
        //cout << "(*itr).first: " <<(*itr).first << "(" <<(*itr).second << ")"; 
        visited_nodes.push_back((*itr).first);
        itr++;
    }
    
    vnode_iterator = visited_nodes.begin();
    
    //cout << endl << "(graphObj -> vertices) + 1: " << (graphObj -> vertices) + 1 << endl;
    
    for(i = 1; i <= (graphObj -> vertices); i++)
    {
        if(i != head_node)
        {
            while(i != *vnode_iterator)
            {
                cout << "-1 ";
                i++;
                
                if(i == head_node)
                {
                    i++;
                }
                
                if(i >= (graphObj -> vertices) + 1)
                    break;
            }
            
            if(i == *vnode_iterator)
            {
                cout << "6 ";
                vnode_iterator++;
            }
        }
    }
    cout << endl;
}


int main() {  
    int num_queries = 0;
    cin >> num_queries;
    
    //Number of Vertices and Number of edges
    int n = 0;
    int m = 0;
    int head_node = 0;
    
    while(num_queries > 0)
    {
        cin >> n;
        cin >> m;
        
        Graph *graphObj = new Graph(n);
        
        for(int i = 0; i < m; i++)
        {
            int v = 0;
            int w = 0;
            
            cin >> v;
            cin >> w;
            
            graphObj -> addEdge(v, w);            
        }
        
        cin >> head_node;
        num_queries--; 
        print_graph(graphObj, head_node);
    }
    
    
    
    return 0;
}


