#include<vector>
#include<shortest_reach.h>

Graph::Graph(int n)                                                            
{                                                                       
    size = n;                                                           
    for( int i=0;i < n;i++)                                             
    {                                                                   
        myGraph.push_back(vector<int>());                               
    }                                                                   
      std::cout<<"No of nodes" << myGraph.size() <<std::endl;           
}                                                                       
                                                                        
void Graph::add_edge(int u, int v) {                                           
   myGraph[u].push_back(v);                                             
   myGraph[v].push_back(u);                                             
}                                                                       
                                                                        
void Graph::addNebiuour(queue<int> *bft, int idx, vector<int> &distance, int currentDistance, vector<bool> &visited)
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
                                                                        
vector<int> shortest_reach(Graph& ref_graph, int start)                                   
{                                                                       
    std::vector<bool> visited(ref_graph.get_size(), false);                              
    std::vector<int> distance(ref_graph.get_size() ,-1);                                 
    std::queue<int> bft;                                                
    distance[start] = 0;                                                
    visited[start] = true;                                              
    ref_graph.addNebiuour(&bft, start, distance, distance[start], visited);       
    while( false == bft.empty())                                        
    {                                                                   
        int front = bft.front();                                        
        bft.pop();                                                      
        if( false == visited[front] )                                   
        {                                                               
            visited[front] = true;                                      
            ref_graph.addNebiuour(&bft, front, distance, distance[front], visited);
        }                                                               
    }                                                                   
                                                                        
    return distance;
}

