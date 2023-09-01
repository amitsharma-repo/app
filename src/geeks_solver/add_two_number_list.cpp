#include <iostream>
#include <add_two_number_list.h>
#include <util_struct.h>
List* addTwoNumbers(List* l1, List* l2) 
{
  List* pTraverse_1 = nullptr;
  List* pTraverse_2 = nullptr;
  /*write corner cases*/
  if (l1 == nullptr)
  {
    return l1;
  }
  if (l2 == nullptr)
  {
    return l2;
  }
  int nCarryOver = 0;
  int nAddedValue = 0;
  do
  {
    pTraverse_1 = pTraverse_1 == nullptr ? l1 : pTraverse_1->p_next_;
    pTraverse_2 = pTraverse_2 == nullptr ? l2 : pTraverse_2->p_next_;

    nAddedValue = pTraverse_1->n_value_ + pTraverse_2->n_value_ + nCarryOver;
    pTraverse_1->n_value_ = nAddedValue % 10;
    nCarryOver = nAddedValue / 10;

  }
  while (pTraverse_1->p_next_ != nullptr && pTraverse_2->p_next_ != nullptr);

  if (pTraverse_1->p_next_ == nullptr && pTraverse_2->p_next_ == nullptr)
  {
    if (nCarryOver > 0)
    {
      List* pNode = new List(nCarryOver);
      pNode->p_next_ = nullptr;
      pTraverse_1->p_next_ = pNode;
    }
    return l1;
  }
  if (pTraverse_1->p_next_ == nullptr)
  {
    pTraverse_1->p_next_ = pTraverse_2->p_next_;
  }
  
  do
  {
    pTraverse_1 = pTraverse_1->p_next_;
    nAddedValue = pTraverse_1->n_value_ + nCarryOver;
    pTraverse_1->n_value_ = nAddedValue % 10;
    nCarryOver = nAddedValue / 10;
  } while (nCarryOver > 0 && pTraverse_1->p_next_ != nullptr);

  if (nCarryOver > 0)
  {
    List* pNode = new List(nCarryOver);
    pNode->p_next_ = nullptr;
    pTraverse_1->p_next_ = pNode;
  }
  return l1;
}
