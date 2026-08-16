#include<serverSocket.h>

struct serverSocket::impl
{
private:
  Eventloop _eventLoop;
  SOCKET _socket;
};

bool serverSocket::Bind(int nPort)
{
  m_impl._socket = socket(AF_INET, SOCK_STREAM, 0);
  if (socket < 0)
  {
    getLogger.log(kSevError, "socket creation falied");
    return false;
  }
  struct socketaddr_in socketAddr;
  (void)memset(&socketAddress, 0, sizeof(socketAddress));
  if (bind(socket, (struct socketadr*)socketAddr, sizeof(socketAddr)))
  {
    getLogger.log(kSevError, "binding address failed");
    return false;
  }
  return true;

}

bool serverSocket::Listen()
{
  if (listen(m_impl._socket, SOMAXCONN))
  {
    getLogger.log(kSevError, "binding address failed");
    return false;
  } 
}

bool serverSocket::Accept(tcpClient& client)
{
  const int clientSocket = accept(socket, NULL, NULL);
  if (IS_INVALID_SOCKET(clientSocket)) 
  {
    return false;
  } 
  else
  {
    client.setSocketId(clientSocket);
    return true;
  }
}

void serverSocket::tcpClient::registerForEPoll(const int& epoll_fd)
{
  struct epoll_event ev;
  ev.events = EPOLLIN | EPOLLOUT | EPOLLERR | EPOLLET;
  ev.data.fd = socketId;
  epoll_ctl(epoll_fd, EPOLL_CTL_ADD, client_socket, &ev);
        //std::cout << "New client connected and added to epoll." << std::endl;
}

void serverSocket::tcpClient::setSocketNonBlocking()
{
   int flags = fcntl(socketId, F_GETFL, 0);
    if (flags == -1)
    {
        std::cerr << "Error getting socket flags!" << std::endl;
        return false;
    }

    flags |= O_NONBLOCK;
    if (fcntl(socketId, F_SETFL, flags) == -1)
    {
        std::cerr << "Error setting socket to non-blocking!" << std::endl;
        return false;
    }

    std::cout << "Socket set to non-blocking mode." << std::endl;
    return true;
}
