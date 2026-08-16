#include <reader_writer.h>

void reader_writer::read_lock()
{
    std::unique_lock<std::mutex> read_lck(reader_mu);
    ++nReadCnt;
    if (nReadCnt == 1)
    {
        rw_mu.lock();
    }
}

void reader_writer::read_unlock()
{
    std::unique_lock<std::mutex> read_lck(reader_mu);
    --nReadCnt;
    if (nReadCnt == 0)
    {
        rw_mu.unlock();
    }
}

void reader_writer::write_lock()
{
    rw_mu.lock();
}

void reader_writer::write_unlock()
{
    rw_mu.unlock();
}
