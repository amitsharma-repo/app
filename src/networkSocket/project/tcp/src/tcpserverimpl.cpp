#include<iostream>


bool shutDown = false;
void OnSigInt(int)
{
  shutDown = true;
}

void onClose()
{

}

void onRecieveMessage(const string& message)
{
  std::cout << message << std::endl;
  send(weakPtrClient);

}

void onClose()
{
  std::cout << "socket closed" << std::endl;
}

void onClientAccept(std::shared_ptr<client>&& rClient)
{
  auto insertClient = setClient.insert(rClient)
  if (insertClient.second == false)
  {
    return;
  }
  const auto iterClient = (insertClient.first);
  const auto newClient = *iterClient;
  std::weak_ptr<client> weakPtrClient(newClient);

  newClient->start( 
        /*onReceive*/[weakPtrClient](const string& message){
        onRecieveMessage(message);
      },
        /*on close*/[](){
        onClose();
      }
  );
}

void tcpServerImpl::setListnerHander(const ListnerHandler& handler)
{
}
void tcpServerImpl::setAcceptHandler(const AcceptHandler& handler)
{
}
void tcpServerImpl::setReceiveHandler(const ReceiveHandler& handler)
{
}
void tcpServerImpl::setCloseHandler(const CloseHandler& handler)
{
}

void tcpServerImpl::eventPoll()
{

}

void tcpServerImpl::ePollEventLoop()
{
  struct epoll_event events[MAX_EVENTS];

  while (true)
  {
    int event_count = epoll_wait(epoll_fd, events, MAX_EVENTS, -1);
    for (int i = 0; i < event_count; i++)
    {
      int fd = events[i].data.fd;
      auto client = clients.find(fd)->second;
      std::weak_ptr< Sockets::ServerSocket::tcpClient > clientWeak(client);

      if (events[i].events & EPOLLIN)
      {
        // Push to thread pool for receiving data
        threadPool.push([this, client](int thread_id)
          { 
            this->handleRecv(client); });
      }
      else if (events[i].events & EPOLLOUT)
      {
        // Push to thread pool for sending data
        threadPool.push([this, fd](int thread_id)
                              { this->handleSend(fd); });
      }
      else if (events[i].events & EPOLLERR)
      {
        // Handle errors
        threadPool.push([this, fd](int thread_id)
                              { this->handleError(fd); });
      }
    }
  }
}

bool tcpServerImpl::initialize(string sPort)
{
  if (bEventPool)
  {
    std::threadPool tThreadPool(tcpServerImpl::ePollEventLoop);
  }

  if (!m_serverSocket.Bind(sPort))
  {
    return false;
  }
  
  epoll_fd = epoll_create1(0);
  if (epoll_fd == -1)
  {
    std::cerr << "Epoll creation failed!" << std::endl;
    return false;
  }

  if (!m_serverSocket.Listen())
  {
    return false;
  }
}

void tcpServerImpl::onReadyClient(shared_ptr<socket::serverSocket::tcpClient>&& newClient)
{
  using socket::serverSocket::tcpClient;

  weak_ptr<tcpClient> clientWeak(client);
  newClient->Start(
      // onReceived
      [clientWeak](const std::string& message) {
        auto client = clientWeak.lock();
        if (!client) {
          return;
        }
        OnReceiveMessage(message);
      },
      // onClosed
      [clientWeak]{
        auto client = clientWeak.lock();
        if (!client) {
          return;
        }
        OnClosed(client);
      }
  );
}

void tcpServerImpl::start()
{
  while (true)
  {
    client tClient;
    if (!m_serverSocket.Accept(tClient))
    {
       std::cerr << "Accept failed! Error: " << strerror(errno) << std::endl;
       continue;
    }
    auto& client = setClient.insert(tClient);
    tClient.setSocketNonBlocking();
    if (bEventPool)
    {
      tClient.registerForEPoll(epoll_fd);
    }
    else
    {
      onReadyClient(client); 
    }
  }
}

int interuptMain()
{
  socket::serverSocket server;
  if (server.Bind(port))
  {
    return -1;
  }
  server.Listen(onClientAccept);
  while(!shutDown)
  {
    std::sleep_for(1000);
  }

  std::cout << "shutting down server" << std::endl;

}
int main()
{
   // Capture previous Interupt handle during <ctrl><C> event triggered
   const auto previousInterruptHandler = signal(SIGINT, OnSigInt);
   int nRetVal = interuptMain();
   signal(SIGINT, previousInterruptHandler);
   return nRetVal;
}
