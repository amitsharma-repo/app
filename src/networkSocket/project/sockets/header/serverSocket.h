#include <iostream>

namespace socket
{
  class serverSocket
  {
  public:
    using OnClientAccept = std::function< void(const std::string&) >;
    using OnClosed = std::function< void() >;
  
    void Bind();
    bool Listen();
    class tcpClient
    {
    public:
      void sendMessage(string sMsg)
      {
        
      }
      void registerForEPoll(const int& epoll_fd);
      void setSocketNonBlocking();
      virtual void Start(
            ServerSocket::OnReceived onReceived,
            ServerSocket::OnClosed onClosed
      ) override {
            connection.Start(socket, onReceived, onClosed);
      }

     void setSocketId(const int& nSocketId)
     {
       socketId = nSocketId;
     }
    private:
       int socketId;
       Conection connection;
    };
    bool Accept(tcpClient& client);
  private:

    struct impl;
    std::shared_ptr<impl> m_impl;
    onReadyClient(shared_ptr<tcpClient>&& client);
  };
}
