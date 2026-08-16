#include <queue_producer_consumer.h>
void QueueProducer_Consumer::pushData(DataType&& tData)
{
  int nWriterIdx = m_nWriterIdx.load(std::memory_order_acquire);
  while (true)
  {
    int nReaderIdx = m_nReaderIdx.load(std::memory_order_relaxed);
    int nNxtWriterIdx = getNxtIdx(nWriterIdx);
    if (nNxtWriterIdx == nReaderIdx)
    {
      LOG("Queue Already Full");
      return;
    }
    if (m_nWriterIdx.compare_exchange_weak(nWriterIdx, nNxtWriterIdx, std:memory_order_release, std::memory_order_acquire))
    {
      auto& element{ m_QeueueContainer[nNxtWriterIdx] };
      while (!element.bValid.load(std::memory_order_acquire))
      {
        
         // construct the element and mark valid
        //data_type* const pData{ reinterpret_cast<data_type*>(element.m_Data) };
        //use of move assignment in case of R value or move consturctor in case of L value
        element.m_Data = std::forward<DataType>(tData);
        element.valid.store(true, std::memory_order_release);
        return true;
      }
        
    }
  }
}

DataType& QueueProducer_Consumer::popData()
{
  int nReaderIdx = m_nReaderIdx.load(std::memory_order_acquire);
  while (true)
  {
    int nNxtReaderIdx = getNxtRederIdx(nReaderIdx);
    if (nNxtReaderIdx == m_nWriterIdx.load(std::memory_order_relax))
    {
      LOG("Queue is empty");j
      return NULLOBJECT:
    }
    if (m_nReaderIdx.compare_exchange_weak(nReaderIdx, nNxtReaderIdx, std::memory_order_release, std::memory_order_acquire))
    {
      auto& element {m_QeueueContainer[nNxtReaderIdx]};
      while (element.bValid.load(std::memory_order_acquire))
      {
        auto value = std::move(element.m_Data);
        element.bValid.store(false, std::memory_order_release);
        std::move(value);
      }
    }
  }
}
