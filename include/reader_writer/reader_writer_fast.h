#pragma once

#include <mutex>

class reader_writer_fast
{
public:
    void read_lock();
    void read_unlock();
    void write_lock();
    void write_unlock();

private:
    std::mutex in_mutex;
    std::mutex out_mutex;
    std::mutex rw_mu;
    int nIntCount = 0;
    int nOutCount = 0;
    bool bWriterWait = false;
};
