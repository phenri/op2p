#ifndef SOCKETSERVER_HH
#define SOCKETSERVER_HH

#include "socketconnection.hh"
#include "messagereceiver.hh"

#include "settings.hh"
#include "asio.hpp"
#include <thread>
#include <mutex>

namespace op2p {
  class SocketServer : public MessageReceiver {
    asio::io_service& service_;
    asio::ip::tcp::acceptor acceptor_;
    Settings settings_;
    SocketConnection connection_;
    bool started_;

    void listen();
    void acceptAsync();

  public:
    explicit SocketServer(const Settings&, asio::io_service&);
    ~SocketServer();

    SocketServer(const SocketServer&) = delete;
    SocketServer& operator=(const SocketServer&) = delete;
    
    void start();
    void stop();
    virtual void receive(const std::shared_ptr<Message>&);
  };
}

#endif // !SOCKETSERVER_HH
