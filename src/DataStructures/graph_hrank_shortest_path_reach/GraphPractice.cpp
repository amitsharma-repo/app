#include <cmath>
#include <cstdio>
#include <ostream>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

class Graph 
{
    public:
        Graph(int n) 
        {
            size = n;
            for( int i=0;i < n;i++)
            {
                myGraph.push_back(vector<int>());
            }
//            std::cout<<"No of nodes" << myGraph.size() <<std::endl;
        }
    
        void add_edge(int u, int v) 
        {
           myGraph[u].push_back(v); 
           myGraph[v].push_back(u); 
        }

        void addNebiuour(queue<int> *bft, int idx, vector<int> &distance, int currentDistance, vector<bool> &visited)
        {
            for_each(myGraph[idx].begin(), myGraph[idx].end(), [&](int val)
                    {
                    if(false == visited[val] )
                    {
                    bft->push(val);
                    if(distance[val] == -1 ||  distance[val] > currentDistance+6)
                    {
                        distance[val] = currentDistance+6;
                    }
                    }
                    });

        }
    
        vector<int> shortest_reach(int start) 
        {
            std::vector<bool> visited(size,false);
            std::vector<int> distance(size,-1);
            std::queue<int> bft;
            distance[start] = 0;
            visited[start] = true;
            addNebiuour(&bft, start, distance, distance[start], visited);
            while( false == bft.empty())
            {
                int front = bft.front();
                bft.pop();
                if( false == visited[front] )
                {
                    visited[front] = true;
                    addNebiuour(&bft, front, distance, distance[front], visited);
                }
            }

            return distance;
        }


    private:
        vector<vector<int>> myGraph; 
        int size;
};

int main() 
{
    int queries;
    cin >> queries;
        
    for (int t = 0; t < queries; t++) {
      
		int n, m;
        cin >> n;
        // Create a graph of size n where each edge weight is 6: 
        Graph graph(n);
        cin >> m;
        // read and set edges
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            // add each edge to the graph
            graph.add_edge(u, v);
        }
		int startId;
        cin >> startId;
        startId--;
        // Find shortest reach from node s
        vector<int> distances = graph.shortest_reach(startId);

        for (int i = 0; i < distances.size(); i++) {
            if (i != startId) {
                cout << distances[i] << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}
