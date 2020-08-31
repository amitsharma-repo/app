#include<vector>
#include<iostream>
//https://leetcode.com/problems/partition-array-into-disjoint-intervals/
/*
 Example 1:

Input: [5,0,3,8,6]
Output: 3
Explanation: left = [5,0,3], right = [8,6]

Example 2:

Input: [1,1,1,0,6,12]
Output: 4
Explanation: left = [1,1,1,0], right = [6,12]

*/
int find_partition_array_into_disjoint_interval( std::vector< int >& input_data );
