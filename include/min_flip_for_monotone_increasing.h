#include<iostream>
//leetcode.com/problems/flip-string-to-monotone-increasing/
/*
Example 1:

Input: "00110"
Output: 1
Explanation: We flip the last digit to get 00111.

Example 2:

Input: "010110"
Output: 2
Explanation: We flip to get 011111, or alternatively 000111.

Example 3:

Input: "00011000"
Output: 2
Explanation: We flip to get 00000000.
*/
int min_flip_monotone_increasing( const std::string& input_string );
