#ifndef SOCKETCONNECTION_HH
#define SOCKETCONNECTION_HH

#include "messagereceiver.hh"
#include "asio.hpp"
#include <string>
#include <mutex>
#include <memory>

namespace op2p {
  class SocketConnection : public MessageReceiver {
    static const size_t maxLineLength = 1024;

    bool authenticated_;
    asio::io_service& service_;
    std::unique_ptr<asio::ip::tcp::socket> pSocket_;
    std::string password_;
    asio::streambuf lineBuffer_;

    void readLineAsync();
    void handleReadLine(const asio::error_code&, std::size_t);
    void writeAsync(const std::string&);
    void handleWrite(const asio::error_code&);

  public:
    explicit SocketConnection(asio::io_service&, const std::string&);
    virtual ~SocketConnection();

    void         open(std::unique_ptr<asio::ip::tcp::socket>&);
    void         close();
    virtual void receive(const std::shared_ptr<Message>&) override;
  };
}

#endif // !SOCKETCONNECTION_HH
