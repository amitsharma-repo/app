#include<search_in_rotated_array.h>
int search(vector<int>& nums, int target) {
        int nMidIndex = nums.siz() / 2;
        int n_index = binary_rotate_search( nums, 0, nMidIndex);
        return n_index;
    }
    int binary_rotate_search( vector<int>& vec_nums, int n_start, int n_end) {
        int n_return_idx;
        if( n_end == n_start)
            return -1;
        int n_middle_idx = ( n_end  - n_start )/ 2
        if(vec_nums[n_middle_idx] == target)
            return n_middle_idx;
        bool b_first_half = false;
        if(target > vec_nums[n_start] && (target < vec_nums[n_end] || )
            b_first_half = true;

        else { // first have

        }
        if(vec_nums[n_start] > vec_nums[n_middle]) {
            if( vec_nums[] < vec_nums[n_middle] ) {
            return binary_rotate_search( vec_nums, n_start, n_middle, target)
        }
        else {
            return binary_rotate_search( vec_nums, n_middle_idx + 1, n_end, target);
        }
    }
