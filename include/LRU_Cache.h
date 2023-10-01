#include <map>
struct ListNode;
class LRUCache {
public:
  LRUCache(int capacity);
  int get(int key);
  void put(int key, int value);
  private:
    //ceating a map of key <=> pair(ListNode*, ListNode*);
    std::map<int, std::pair<ListNode*, ListNode*>> map_Cache;
    ListNode* m_pCache;
    ListNode* m_pCurrentNode;
    int m_nCapacity;
    int m_nSize;
};
