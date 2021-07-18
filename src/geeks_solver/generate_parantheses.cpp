#include<generate_parantheses.h>
#include<iostream>
using type_container = std::vector<std::string>;
void recurse_parantheses(type_container& rVecParantheses, int nSize);
std::vector<std::string> generateParenthesis(int n)
{
    type_container result_parantheses;
    recurse_parantheses( result_parantheses, n);
    return result_parantheses;
}
void recurse_parantheses(type_container& rVecParantheses, int nSize)
{
    if(nSize ==1 ) {
        rVecParantheses.push_back("()");
        return;
    }
    recurse_parantheses( rVecParantheses, nSize-1);
    bool bSkip = true;
    size_t nVecSize = rVecParantheses.size();
    for(int i =0; i< nVecSize; ++i)
    {
        std::string strSubStr = "()";
        if( !bSkip ) 
            rVecParantheses.push_back( strSubStr + rVecParantheses[i]); 
        else 
            bSkip = false;
        std::string nxtStr = "(" + rVecParantheses[i] + ")";
        rVecParantheses.push_back(nxtStr);
        rVecParantheses[i] = rVecParantheses[i] + strSubStr ; 
    } 
//    std::cout << nSize << std::endl;
    for( auto str:rVecParantheses)
        std::cout << str << "  ";
 //   std::cout << std::endl;
}
