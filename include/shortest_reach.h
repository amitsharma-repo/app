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
    Graph(int n); 
    void add_edge(int u, int v); 
    void addNebiuour(queue<int> *bft, int idx, vector<int> &distance, int currentDistance, vector<bool> &visited);
    int get_size() { return size; }
private:
    vector<vector<int>> myGraph; 
    int size;
};
vector<int> shortest_reach(Graph& ref_graph, int start); 

