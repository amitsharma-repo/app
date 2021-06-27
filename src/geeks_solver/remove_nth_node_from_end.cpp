#pragma once
#include<remove_nth_node_from_end.h>
List* removeNthFromEnd(List* head, int n) {
       int nCounter = 0;
       List* pForward = head; 
       List* pPrev = head;
       while(pForward != nullptr &&  nCounter != n) {
          pForward = pForward->p_next_;   
           nCounter++;
       }
       if( nCounter != n )
       {
           return nullptr;
       }
        else if( pForward != nullptr)
        {
            while( pForward->p_next_ != nullptr) {
                pForward = pForward->p_next_;
                pPrev = pPrev->p_next_;
            }
            List* pNode = pPrev->p_next_;
            pPrev->p_next_ = pPrev->p_next_->p_next_;
            delete pNode;
        }
        else { // deleteing first node
            if(pPrev->p_next_ == nullptr) {// single node case
                delete pPrev;
                return nullptr;
            }
            List* pNode = pPrev;
            head = head->p_next_;
            delete pNode;
        }
        
        return head;
    }
