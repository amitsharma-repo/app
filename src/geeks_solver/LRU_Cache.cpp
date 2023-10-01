#include<iostream>
#include<LRU_Cache.h>

struct ListNode
{
  int n_value_;
  int key;
  ListNode* p_next_;
  ListNode(int key_, int value_):key(key_), n_value_(value_)
  {}
};

void debug_print( const ListNode* p_node )
{
  std::cout <<std::endl;
   std::cout << "node value " << std::endl;
   while( p_node != nullptr )
   {
      std::cout << p_node->key << "<-->"<< p_node->n_value_ << " ";
      p_node = p_node->p_next_;
   }
}

LRUCache::LRUCache(int capacity):  m_pCache(nullptr), m_pCurrentNode(nullptr), m_nCapacity(capacity), m_nSize(0)
{ }
    
void print_cache( std:: map<int, std::pair<ListNode*, ListNode*>>& map_Cache)
{
  std::cout << std::endl;
  std::cout << " cache map with size : " <<  map_Cache.size() << std::endl;
   for_each( map_Cache.begin(), map_Cache.end(), [&]( std::pair<int, std::pair<ListNode*, ListNode*>> it)
       {
          if(it.second.first != nullptr)
          {
             std::cout << it.first << " prev " << it.second.first->n_value_ << " node " << it.second.second->n_value_ << std::endl;
          }
          else
          {
             std::cout << it.first << " node " << it.second.second->n_value_ << std::endl;
          }
       });
   std::cout << "map end" << std::endl;
}

int LRUCache::get(int key)
{
   ListNode* pPrevNode, *pNode = nullptr;
   //find return prevNode of Node with n_value_ue
   auto iter = map_Cache.find(key);

   if (iter == map_Cache.end())
   {
       return -1;
   }
   else
   {

    pPrevNode = iter->second.first;
    pNode = iter->second.second;
    bool bDoNothing = false;

    if (pNode->p_next_ == nullptr)
    {
      bDoNothing = true;
    }
    else
    {
        if (pPrevNode == nullptr)
        {
          m_pCache = m_pCache->p_next_;
        }
        else
        {
           //remove it from its currnet position
           pPrevNode->p_next_ = pNode->p_next_;
        }
        map_Cache.find(pNode->p_next_->key)->second.first = pPrevNode;
    }

    if (!bDoNothing)
     {
        m_pCurrentNode->p_next_ = pNode;
        iter->second = std::make_pair(m_pCurrentNode, pNode);
        m_pCurrentNode = pNode;
        m_pCurrentNode->p_next_ = nullptr;
    }

   }
   return pNode->n_value_;
}

void LRUCache::put(int key, int value)
{
   int nCurentValue = m_pCurrentNode == nullptr ? -1 : m_pCurrentNode->n_value_;
   ListNode* pPrevNode, *pNode = nullptr;
   //find return prevNode of Node with n_value_ue
   auto iter = map_Cache.find(key);

   if (iter == map_Cache.end())
   {
       pNode = new ListNode(key, value);
       if (m_nCapacity == m_nSize)
       {

           if( m_pCache!= nullptr )
           {
               //do the eviction
               ListNode* pEvictNode = m_pCache;
               m_pCache = m_pCache->p_next_;
               map_Cache.erase(map_Cache.find(pEvictNode->key));
               delete pEvictNode;
               //remove for map cache also
                 if(m_pCache != nullptr)
                 {
                   map_Cache.find(m_pCache->key)->second.first = nullptr;
                 }
                 else
                 {
                    m_pCurrentNode = nullptr;
                 }
           }
           m_nSize = m_nSize -1;
       }
       m_nSize = m_nSize + 1;

       if (m_pCurrentNode)
       {
           m_pCurrentNode->p_next_ = pNode;
       }
       else
       {
           m_pCache = pNode;
       }
       map_Cache.insert(std::make_pair(key, std::make_pair(m_pCurrentNode, pNode)));
       m_pCurrentNode = pNode;
   }
   else
   {
       pPrevNode = iter->second.first;
       pNode = iter->second.second;
       pNode->n_value_ = value;
       bool bDoNothing = false;
       //if pNode is last node ( also scenario of only single node)
       if (pNode->p_next_ == nullptr)
       {
         bDoNothing = true;
       }
       else
       {
           if (pPrevNode == nullptr)
           {
             m_pCache = m_pCache->p_next_;
           }
           else
           {
              //remove it from its currnet position
              pPrevNode->p_next_ = pNode->p_next_;
           }
           map_Cache.find(pNode->p_next_->key)->second.first = pPrevNode;
       }

       if (!bDoNothing)
        {
           m_pCurrentNode->p_next_ = pNode;
           iter->second = std::make_pair(m_pCurrentNode, pNode);
           m_pCurrentNode = pNode;
           m_pCurrentNode->p_next_ = nullptr;
       }

   }
}

