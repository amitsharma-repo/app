#include <queue>
#include <vector>
using namespace std;
class ShortestPathGraph 
    {
    public:
        ShortestPathGraph(int n); 
        void add_edge(int u, int v); 
        void addNebiuour(queue<int> *bft, int idx, vector<int> &distance, int currentDistance, vector<bool> &visited);
        int get_size() { return size; }
    private:
        vector<vector<int>> myGraph; 
        int size;
    };
