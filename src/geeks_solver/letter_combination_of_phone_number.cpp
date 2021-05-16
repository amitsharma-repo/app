#include<sstream>
#include<vector>
#include<letter_combination_of_phone_number.h>
static std::vector<std::string> listPhonicNumber= {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

//std::vector<std::string> recurse_nxt_digit(int nDigit_Idx,const std::string& rStrDigit);
std::vector<std::string> letter_combination_of_phone_number(const std::string& rStrDigit)
{
   int nDigit_idx = 0;
   return recurse_nxt_digit( nDigit_idx, rStrDigit);
}

std::vector<std::string> recurse_nxt_digit(int nDigit_Idx,const std::string& rStrDigit)
{
    std::vector<std::string> vecStrList;
    if( rStrDigit == "")
        return vecStrList;
    char chDigit= rStrDigit[nDigit_Idx];

    int n_digit =chDigit - '0';// convert ch_digit to n_digit;
    std::string strPhonic= listPhonicNumber[n_digit];
    if( nDigit_Idx == rStrDigit.size() -1)
    {
        for( int i= 0; i<strPhonic.size(); ++i)
           vecStrList.push_back( std::string(1, strPhonic[i] )); 
        return vecStrList;
    }
    std::vector<std::string> vec_retList;
    vecStrList= recurse_nxt_digit( nDigit_Idx+ 1, rStrDigit);     
    for( int i= 0; i<strPhonic.size(); ++i)
    {
        for ( auto it = vecStrList.begin(); it != vecStrList.end(); ++it)
        {
            vec_retList.push_back(strPhonic[i] + *it);
        }
    }
    return vec_retList;
}
