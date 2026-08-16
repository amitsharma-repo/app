#pragma once

#include <atomic>

class ReaderWriterLockFree
{
private:
    std::atomic<int> m_nReaderCnt{0};
    std::atomic<bool> m_bReaderActive{false};
    std::atomic<bool> m_bWriterActive{false};
    std::atomic<bool> m_bWriterEntry{false};

public:
    void ReaderLock();
    void ReaderUnlock();
    void WriterLock();
    void WriterUnlock();
};
