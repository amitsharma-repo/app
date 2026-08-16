#include <reader_writer_fast.h>

void reader_writer_fast::read_lock()
{
    std::unique_lock<std::mutex> in_lock(in_mutex);
    ++nIntCount;
}

void reader_writer_fast::read_unlock()
{
    std::unique_lock<std::mutex> out_lock(out_mutex);
    ++nOutCount;
}

void reader_writer_fast::write_lock()
{
    std::unique_lock<std::mutex> in_lck(in_mutex);
    out_mutex.lock();
    if (!bWriterWait && nIntCount == nOutCount)
    {
        out_mutex.unlock();
        rw_mu.lock();
    }
    else
    {
        out_mutex.unlock();
        bWriterWait = true;
        rw_mu.lock();
        bWriterWait = false;
    }
}

void reader_writer_fast::write_unlock()
{
    rw_mu.unlock();
}
