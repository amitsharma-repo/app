#pragma once

#include <mutex>

class reader_writer
{
public:
    reader_writer() = default;
    void read_lock();
    void read_unlock();
    void write_lock();
    void write_unlock();

private:
    std::mutex reader_mu;
    std::mutex rw_mu;
    int nReadCnt = 0;
};
