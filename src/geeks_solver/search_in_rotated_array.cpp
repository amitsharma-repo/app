#include<iostream>
#include<search_in_rotated_array.h>
int binary_rotate_search( std::vector<int>& vec_nums, int n_start, int n_end, int target) {
    int n_return_idx;
    if( n_end == n_start || n_start > n_end)
        return -1;
    int n_middle_idx = n_start + ( n_end  - n_start )/ 2  ;
    if(vec_nums[n_middle_idx] == target)
        return n_middle_idx;
    bool b_first_half = true;
    if( vec_nums[n_middle_idx] < vec_nums[n_start]  ) { // pivot is at first half
           if( target <= vec_nums[n_end] && target >= vec_nums[n_middle_idx + 1]) // check in second half;
                b_first_half = false;
           else
               b_first_half = true;

      }
      else{ // pivot is at second half
        if( target <= vec_nums[n_middle_idx] && target >= vec_nums[n_start]) // check in first half;
                b_first_half = true;
           else
               b_first_half = false;
        }
    if(b_first_half) {
        n_return_idx = binary_rotate_search( vec_nums, n_start, n_middle_idx, target);
    }
    else {
        n_return_idx = binary_rotate_search( vec_nums, n_middle_idx + 1, n_end, target);
    }
    return n_return_idx;
}
int search(std::vector<int>& nums, int target) {
    int n_index = binary_rotate_search( nums, 0, nums.size() -1, target);
    return n_index;
}
