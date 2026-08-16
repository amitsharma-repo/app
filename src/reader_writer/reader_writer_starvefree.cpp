#include <reader_writer_starvefree.h>

void reader_writer_sf::read_lock()
{
    std::unique_lock<std::mutex> entry_lck(entry_mu);
    std::unique_lock<std::mutex> read_lck(reader_mu);
    ++nReadCnt;
    if (nReadCnt == 1)
    {
        rw_mu.lock();
    }
}

void reader_writer_sf::read_unlock()
{
    std::unique_lock<std::mutex> read_lck(reader_mu);
    --nReadCnt;
    if (nReadCnt == 0)
    {
        rw_mu.unlock();
    }
}

void reader_writer_sf::write_lock()
{
    entry_mu.lock();
    rw_mu.lock();
}

void reader_writer_sf::write_unlock()
{
    rw_mu.unlock();
    entry_mu.unlock();
}
