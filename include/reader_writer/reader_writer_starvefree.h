#include <mutex>
class reader_writer_sf
{
public:
    void read_lock();
    void read_unlock();
    void write_lock();
    void write_unlock();
private:
    std::mutex reader_mu; 
    std::mutex rw_mu;
    std::mutex entry_mu;
    int nReadCnt = 0;
};
