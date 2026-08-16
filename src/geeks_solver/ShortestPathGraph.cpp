 #include <queue>
 #include <vector>
 #include <iostream>
 #include <ShortestPathGraph.h>
 using namespace std;

 
ShortestPathGraph::ShortestPathGraph(int n)                                                            
{                                                                       
    size = n;                                                           
    for( int i=0;i < n;i++)                                             
    {                                                                   
        myGraph.push_back(vector<int>());                               
    }                                                                   
      std::cout<<"No of nodes" << myGraph.size() <<std::endl;           
}                                                                       
                                                                        
void ShortestPathGraph::add_edge(int u, int v) {                                           
   myGraph[u].push_back(v);                                             
   myGraph[v].push_back(u);                                             
}                                                                       
                                                                        
void ShortestPathGraph::addNebiuour(queue<int> *bft, int idx, vector<int> &distance, int currentDistance, vector<bool> &visited)
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