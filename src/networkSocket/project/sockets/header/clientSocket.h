#include <iostrem>
namespace socket
{
  class clientSocket
  {
  public:
    using OnReceived = std::function< void(const std::string&) >;
    using OnClosed = std::function< void() >;
  
    void connect();
  private:
    struct impl;
    std::shared_ptr<impl> m_impl;
  };
}
