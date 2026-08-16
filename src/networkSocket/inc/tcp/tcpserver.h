#include <iostream>

class tcpServer
{
typedef funciton<void> ListnerHandler;
typedef funciton<void> AcceptHandler;
typedef funciton<void> ReceiveHandler;
typedef funciton<void> CloseHandler;

public:
  virtual void initialize(string sIpAddress, string sPort) = 0;
  virtual void start() = 0;
  virtual void setListnerHander(const ListnerHandler& handler) = 0;
  virtual void setAcceptHandler(const AcceptHandler& handler) = 0;
  virtual void setReceiveHandler(const ReceiveHandler& handler) = 0;
  virtual void setCloseHandler(const CloseHandler& handler) = 0;
};
