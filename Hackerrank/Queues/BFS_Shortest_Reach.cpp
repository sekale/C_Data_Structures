#include <iostream>
#include <list>
#include <vector>
#include <queue>

using namespace std;

/*void print_graph()
{
    for(int i = 1; i < vertices + 1; i++)
    {
        cout << endl << "For Node i: " << i << endl ;
        list<pair <int,int>>::iterator itr;
        itr = adj_list[i].begin();

        while(itr != adj_list[i].end())
        { 
            cout << endl << (*itr).first << "\t" <<  (*itr).second;
            itr++;
        } 
    }
}*/

int main()
{
	int queries = 0;
	cin >> queries;

	while(queries != 0)
	{
		int vertices = 0; //number of vertices
		int num_edges = 0; //number of edges
        int source_node = 0;
        
        int e1, e2; //edges

		cin >> vertices >> num_edges;

        vector<list < pair <int, int> > > adj_list(vertices + 1);

        //building the graph
        for(int i = 1; i <= num_edges; i++)
        {
            cin >> e1 >> e2;
            adj_list[e1].push_back(make_pair(e2, 6));
            adj_list[e2].push_back(make_pair(e1, 6));
        }
       
        cin >> source_node;
        //cout << "here breakpoint 1";
        
        vector <pair<int,int>> visited_node_level;
        list <pair<int,int>>::iterator itr;
        queue<pair<int, int>> bfsqueue;
        
        bool *visited = new bool[vertices + 1]();
        
        bfsqueue.push(make_pair(source_node, 0));
        visited[source_node] = true;
        
        while(!bfsqueue.empty())
        {
            //cout << "here" << endl;
            itr = adj_list[bfsqueue.front().first].begin();
            while(itr != adj_list[bfsqueue.front().first].end())
            {
                if(visited[(*itr).first] == false)
                {
                    bfsqueue.push(make_pair((*itr).first, bfsqueue.front().second + 1));
                    visited_node_level.push_back(make_pair((*itr).first, bfsqueue.front().second + 1));
                    visited[(*itr).first] = true;
                    //cout << "\n pushing node:" << (*itr).first;
                }
                itr++;
            }
            //cout << "\n count incrementing now";
            bfsqueue.pop();
        }
        //cout << "here breakpoint 2";
        
        vector < pair <int,int> >::iterator itr2;
        itr2 = visited_node_level.begin();
        
        int *count_jumps = new int[vertices + 1];
        
        for(int i = 0; i < vertices + 1; i++)
        {
            count_jumps[i] = -1;
        }
            
        
        while(itr2 != visited_node_level.end())
        {
            count_jumps[(*itr2).first] = (*itr2).second;
            //cout << endl << "x:  "<< (*itr2).first << "  y:  "<< (*itr2).second;
            itr2++;
        }
        
        for(int i = 1; i < vertices + 1; i++)
        {
            if(i != source_node)
            {
                if(count_jumps[i] != -1)
                    cout << 6 * count_jumps[i] << " ";
                else
                    cout << -1 << " ";
            }
        }
        cout << endl;

        queries--;
        //cout << endl << "Graph Ends" << endl << endl ;
        //cout << "\n queries:" << queries << endl;
    }
}