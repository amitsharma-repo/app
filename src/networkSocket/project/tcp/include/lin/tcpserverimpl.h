#include <inc/tcp/tcpserver.h>
#include <iostream>

class tcpServerimpl: public tcpServer
{

public:

  void initialize(string sIpAddress, string sPort);
  void start();
  void setListnerHander(const ListnerHandler& handler);
  void setAcceptHandler(const AcceptHandler& handler);

  void setReceiveHandler(const ReceiveHandler& handler);
  void setCloseHandler(const CloseHandler& handler);

private:
  unordered_map<int, shared_ptr<socket::serverSocket::tcpClient>> setClient;
  int epoll_fd;
};
