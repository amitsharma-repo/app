#include <iostrem>
template <typename DataType, int nSize>
class QueueProducer_Consumer
{
public:
  QueueProducer_Consumer()
  {
    m_nReaderIdx = 0;
    m_nWriterIdx = 0;
  }
  void pushData(const DataType tData);
  void pushData(DataType&& tData);
  DataType& popData();
private:
  struct Element
  {
    DataType m_Data;
    std::atomic<bool> bValid = false;
  }
  std::array<Element, nSize> m_QeueueContainer;
  int m_nSize = nSize; 
  std::atomic<int> m_nReaderIdx;
  std::atomic<int> m_nWriterIdx;
  
};

