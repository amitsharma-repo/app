#include "count_and_say.h"
#include <iostream>
#include<vector>
std::string countAndSay(int n)
{
    std::string str_count_and_say;
    std::vector<int> vec_result; 
    vec_result.push_back(1);
    for(int i =1; i< n; ++i)
    {
        int nNxtIdx =1;
        std::vector<int> nxt_vec;
        auto iter = vec_result.begin();
        while( iter + 1 != vec_result.end())
        {
            if(*iter != *(iter +1)) {
                nxt_vec.push_back(nNxtIdx);
                nxt_vec.push_back(*iter);
                nNxtIdx = 1;
            }
            else {
                nNxtIdx++;
            }
            ++iter;
        }
        nxt_vec.push_back(nNxtIdx);
        nxt_vec.push_back(*iter);
        vec_result = nxt_vec;
    }
    for(auto iter = vec_result.begin(); iter != vec_result.end(); ++iter)
    {
        char ch = '0' + *iter;
        str_count_and_say.push_back( ch );
    }
    return str_count_and_say;
}
