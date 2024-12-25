#include "count_number_of_atoms.h"
#include <stack>
#include <map>
std::string countOfAtoms(std::string formula)
{
  std::map<char, int> 
  std::stack<char> stackChar;
  for (auto iter = formula.begin(); iter != formula.end(); ++iter)
  {
    char cFormula = *iter;
    switch (cFormula)
    {
      case '(':
      {
        stackChar.push('(');
        break;
      }
      case ')':
      {
        if (isdigit(*(iter + 1))
        {
            iter++;
            int nCnt = char_to_int(*iter);
            std::stack<char> stachChar_temp;
            while (stackChar.front() != '(')
            {
               char nextChar = stackChar.front();
               int nAtomCnt = nCnt;
               if (!isalpha(nextChar))
               {
                  stackChar.pop();
                  int nPrevCnt =  char_to_int(nextChar);
                  nextChar = stackChar.front();
                  nAtomCnt = nAtomCnt * nPrevCnt;
               }
               else
               {
                 
               }
               stackChar_temp.push(nAtomCnt);
            }
            stackChar.pop();
        }
        else
        {

        }

        break;
      }
      default:
      {
        if (isalpha(cFormula)) // its a character 
        {
          if (!stackChar.empty()) 
          {
            stackChar.push(cFormula);
          }
        }
        if () //its a character
      }
    }
  }
}
