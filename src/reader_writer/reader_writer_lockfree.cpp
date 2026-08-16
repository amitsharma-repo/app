#include <reader_writer_lockfree.h>

#include <thread>

void ReaderWriterLockFree::ReaderLock()
{
    while (true)
    {
        int curr_reader_cnt = m_nReaderCnt.load(std::memory_order_acquire);
        m_bReaderActive.store(true, std::memory_order_release);
        if (!m_bWriterEntry.load(std::memory_order_acquire) &&
            m_nReaderCnt.compare_exchange_weak(curr_reader_cnt,
                                               curr_reader_cnt + 1,
                                               std::memory_order_acquire,
                                               std::memory_order_release))
        {
            m_bReaderActive.store(false, std::memory_order_release);
            break;
        }
        m_bReaderActive.store(false, std::memory_order_release);
        std::this_thread::yield();
    }
}

void ReaderWriterLockFree::ReaderUnlock()
{
    m_nReaderCnt.fetch_sub(1, std::memory_order_release);
}

void ReaderWriterLockFree::WriterLock()
{
    bool expected = false;
    while (true)
    {
        if (m_bWriterActive.compare_exchange_weak(expected,
                                                  true,
                                                  std::memory_order_acquire,
                                                  std::memory_order_release) &&
            !m_bReaderActive.load(std::memory_order_acquire))
        {
            m_bWriterEntry.store(true, std::memory_order_release);
            while (m_nReaderCnt.load(std::memory_order_acquire) > 0)
            {
                std::this_thread::yield();
            }
            break;
        }
        expected = false;
        std::this_thread::yield();
    }
}

void ReaderWriterLockFree::WriterUnlock()
{
    m_bWriterEntry.store(false, std::memory_order_release);
    m_bWriterActive.store(false, std::memory_order_release);
}
