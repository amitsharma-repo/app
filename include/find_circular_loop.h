//https://leetcode.com/problems/circular-array-loop/
#include<vector>
bool dfs_check_loop(int nIndex, std::vector<bool>& arrVisited, const std::vector<int>& arrCircular, int& nLoopLen, bool bSign);
bool check_circular_loop(std::vector<int>& arrCircular);
