#include<find_first_and_last_position_of_element.h>
#include<iostream>>
int binary_search(const std::vector<int>& vec_input, int n_start, int n_end, int target)
{
     if(target == vec_input[n_start])
         return n_start;
     if( target == vec_input[n_end])
        return n_end;
     if(n_start == n_end)
         return -1;
     int n_mid_idx = n_start  + (n_end - n_start)/2;
     if( target == vec_input[n_mid_idx])
         return n_mid_idx;
     if(target < vec_input[n_mid_idx])
         return binary_search( vec_input, n_start, n_mid_idx, target);
     else
         return binary_search(vec_input, n_mid_idx+1, n_end, target);
 }
std::vector<int> searchRange(std::vector<int>& nums, int target) {
     std::vector<int> ret_vec = {-1,-1};
     if(nums.size() == 0)
         return ret_vec;
    if( nums.size() == 1 && nums[0] == target)
    {
        ret_vec[0]= ret_vec[1] = 0;
        return ret_vec;
    }
    int n_end = nums.size() -1;

    int return_idx;
    if(target < nums[0] || target > nums[n_end])
        return_idx =  -1;
    return_idx = binary_search( nums , 0, n_end, target);
    int n_start_idx = return_idx;
    while(n_start_idx-1 >= 0 && nums [n_start_idx -1] == target)
        n_start_idx--;
    ret_vec[0] = n_start_idx;
    while(return_idx+1 <= n_end && nums[return_idx +1] == target)
        return_idx++;
    ret_vec[1]= return_idx;
    return ret_vec;
}
