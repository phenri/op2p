#ifndef SOCKETCLIENT_HH
#define SOCKETCLIENT_HH

#include "settings.hh"
#include "messagereceiver.hh"
#include "socketconnection.hh"
#include "asio.hpp"

namespace op2p {
  class SocketClient : public MessageReceiver {
    asio::io_service& service_;
    Settings          settings_;
    SocketConnection  connection_;

  public:
    explicit SocketClient(const Settings&, asio::io_service&);
    virtual ~SocketClient();

    SocketClient(const SocketClient&) = delete;
    SocketClient& operator=(const SocketClient&) = delete;
  
    void         connect();
    void         disconnect();
    virtual void receive(const std::shared_ptr<Message>&) override;
  };
}

#endif // !SOCKETCLIENT_HH
