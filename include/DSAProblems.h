#include<vector>
#include<level_order_spiral_traversal.inl>
#include<binary_tree_utils.h>
#include<util_struct.h>
#include<next_rightptr_tree.h>
#include<ShortestPathGraph.h>

#include <set>

#pragma once
using namespace std;

class Node1 {
    public:
        int val;
        Node1* left;
        Node1* right;
        Node1* next;
        Node1() : val(0), left(nullptr), right(nullptr), next(nullptr) {}
//. 
        Node1(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}
//. 
        Node1(int _val, Node1* _left, Node1* _right, Node1* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
    };
     template<typename T>
    struct Node_with_nxt_right{
        Node<T>* p_node_;
    Node<T>* p_next_right_;    
        Node<T>* get_left() { return p_node_->p_left; }
        Node<T>* get_right() { return p_node_->p_right; }
        Node_with_nxt_right( Node<T>* p_node ): p_node_(p_node) {}
        Node_with_nxt_right(int n_data):p_node_(new Node( n_data )), p_next_right_( nullptr ) 
        {}
    };
    
class GeekSolver
{
    public:

    TreeNode* sortedListToBST(List* head);
    Node<int>* bst_to_gst( Node<int>* p_root );
    int maxPathSum(TreeNode* root); 
    //https://www.hackerrank.com/challenges/3d-surface-area/problem
    int calculate_3d_surface_area(int nWidth, int nHeight, int** dimension );
    //https://www.hackerrank.com/challenges/larrys-array/problem
    bool check_larry_array(std::vector<int> vecInputArray);
   
    //. 
    template<typename T>
    Node_with_nxt_right<T>* connect_node_at_same_level( Node_with_nxt_right<T>* p_node );
    //https://leetcode.com/problems/count-and-say/
    std::string countAndSay(int n);
    //https://leetcode.com/problems/number-of-atoms/
    std::string countOfAtoms(std::string formula);
    List* reverse( List* p_root );
    List* delete_node_with_greater_on_right(List* p_list);
    //https://leetcode.com/problems/substrings-of-size-three-with-distinct-characters/
    int countGoodSubstrings(std::string s);
    bool check_duplicate_sub_tree( Node<char>* p_root );
    bool dfs( Node<char>* p_node, std::set<std::string>& set_sub_tree_matcher );
    //https://leetcode.com/problems/circular-array-loop/
    bool dfs_check_loop(int nIndex, std::vector<bool>& arrVisited, const std::vector<int>& arrCircular, int& nLoopLen, bool bSign);
    bool check_circular_loop(std::vector<int>& arrCircular);
    std::vector<int> find_duplicate_in_n_time( int n_size, int* p_arr );
    std::vector<int> searchRange(std::vector<int>& nums, int target); 
    int find_first_in_rotated_sorted_array( int* arr, int nSize );
    //finding last element in completely binary tree
    template<typename T>
    void create_complete_binary_tree(const std::vector<T>& vec_input);
    template<typename T>
    int find_last_in_complete_binary_tree(Node<T>* p_root, int& n_level );
    template<typename T>
    Node<T>* add_next_node( Node<T>* p_node, T n_value );
    template<typename T>
    Node<T>* check_right_most_is_leaf( Node<T>* p_node, int n_level );
    //https://leetcode.com/problems/container-with-most-water/
    int find_max_area(const std::vector<int>& heights);
    int find_min_number_from_given_sequence( int n_size, int* p_arr );
    std::vector<int> find_setes_with_last_occurance( std::vector< char> vec_occurance );
    std::tuple<int,int> find_smallest_range( int nList_cnt, List** pplist_collection);
    std::tuple<int, int> find_subarray_with_given_sum(std::vector<int> vec_input, int n_sum);
    //https://leetcode.com/problems/generate-parentheses/
    std::vector<std::string> generateParenthesis(int n);
    //https://leetcode.com/problems/gray-code/
    std::vector<int> grayCode(int n);
    //https://leetcode.com/problems/rotate-image/
    void rotate(std::vector<std::vector<int>>& matrix); 
    //https://leetcode.com/problems/jump-game-ii/
    int jump(std::vector<int>& nums);
    //https://practice.geeksforgeeks.org/problems/jumping-numbers/0/
    std::vector<int> find_jumping_number_list( int n_input );
    std::vector<std::string> recurse_nxt_digit( int nDigit_Idx,const std::string& rStrDigit);
    std::vector<std::string> letter_combination_of_phone_number(const std::string& rStrDigit);
    template<typename T>
    void level_order_spiral_traversal( Node<T>* pNde, std::string& result );
    //https://leetcode.com/problems/longest-nice-substring/
    std::string longestNiceSubstring(std::string s); 
    //https://leetcode.com/problems/longest-palindromic-substring/
    std::string longestPalindrome(std::string s);
    //https://leetcode.com/problems/longest-substring-without-repeating-characters/
    int lengthOfLongestSubstring(std::string s);
    //https://practice.geeksforgeeks.org/problems/longest-valid-parentheses/0
    int find_longest_valid_parantheses( const std::string& input_string );
    //https://leetcode.com/problems/majority-element/description/
    int majorityElement(std::vector<int>& nums);
    //https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
    int maxProfitOnce(std::vector<int>& prices);
    //https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/
    int maxProfit(std::vector<int>& prices);
    //Given an array A[] of N positive integers. The task is to find the maximum of j - i subjected to the constraint of A[i] <= A[j].
    int find_max_index(std::vector<int> vec_input);
    //https://leetcode.com/problems/maximum-subarray/?envType=study-plan-v2&envId=top-interview-150
    int maxSubArray(vector<int>& nums);
    //https://leetcode.com/problems/maximum-sum-circular-subarray/description/?envType=study-plan-v2&envId=top-interview-150
    int maxSubarraySumCircular(std::vector<int>& nums);
    //https://leetcode.com/problems/median-of-two-sorted-arrays/
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2);
    //https://leetcode.com/problems/merge-intervals/description/
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals);
    //https://leetcode.com/problems/merge-sorted-array/
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n);
    //leetcode.com/problems/flip-string-to-monotone-increasing/
    int min_flip_monotone_increasing( const std::string& input_string );
    int minimumJumps(std::vector<int>& forbidden, int a, int b, int x);
    //https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
    
    void create_tree_ptr(const std::vector<int>& vec_data, NodeNxt*& pRoot);
    NodeNxt* connectNxt(NodeNxt* root);
    std::vector<std::pair<int,int>> find_pair_with_sum( std::vector<int>& first_array, std::vector<int>& second_array );
    //https://leetcode.com/problems/partition-array-into-disjoint-intervals/
    int find_partition_array_into_disjoint_interval( std::vector< int >& input_data );
    //https://leetcode.com/problems/partition-list/
    List* partition(List* head, int x);
    //https://leetcode.com/problems/partition-list/
    List* partition_smaller(List* head, int x);
    //https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
   
    Node1* connect(Node1* root);
    //https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
    int removeDuplicatesSorted(std::vector<int>& nums);
    //https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
    int removeDuplicates(std::vector<int>& nums);
    //https://leetcode.com/problems/remove-element/description/
    int removeElement(vector<int>& nums, int val);
    //Definition for singly-linked list.
    List* removeNthFromEnd(List* head, int n); 
    //https://leetcode.com/problems/restore-ip-addresses/
    std::set<std::string> restoreIpAddresses(std::string s);
    int get_reverse_digit_of_integer( int n_value );
    //https://leetcode.com/problems/reverse-linked-list-ii/
    List* reverseBetween_position(List* head, int left, int right);
    //https://leetcode.com/problems/reverse-linked-list-ii/
    List* reverseBetween(List* head, int left, int right);
    List* reverseKGroup(List* head, int k);
    //https://leetcode.com/problems/rotate-array/description/
    void rotate(std::vector<int>& nums, int k);
    //https://leetcode.com/problems/rotate-list/
    List* rotateList(List* pHead, int k);
    //https://leetcode.com/problems/search-in-rotated-sorted-array/
    int search(std::vector<int>& nums, int target);
    //. 
   
    vector<int> shortest_reach(ShortestPathGraph& ref_graph, int start); 
    //https://leetcode.com/problems/split-linked-list-in-parts/
    vector<List*> splitListToParts(List* head, int k);
    int my_atoi( const std::string& str_value );
    List* swapPairs(List* head); 
    //https://practice.geeksforgeeks.org/problems/find-triplets-with-zero-sum/1
    bool find_triptet_with_zero_sum( const std::vector<int>& vec_input );
    std::vector<int> find_sets_with_last_occurance( std::vector< char> vec_occurance );
    //https://leetcode.com/problems/two-sum/
    std::vector<int> towsum(std::vector<int>& nums, int target);
    //https://practice.geeksforgeeks.org/problems/word-break/0
    bool check_word_break( const std::vector<std::string>& vec_input_string, const string& to_match );
    //https://leetcode.com/problems/add-two-numbers/
    List* addTwoNumbers(List* l1, List* l2);
    //https://leetcode.com/problems/avoid-flood-in-the-city/
    std::vector<int> avoid_flood_in_city(std::vector<int> rains);
    void flatten(TreeNode* root);
};