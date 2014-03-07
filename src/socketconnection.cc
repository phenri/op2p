#include "socketconnection.hh"
#include "socketinputmessage.hh"
#include "socketconnectionclosedmessage.hh"
#include "consoleoutputmessage.hh"
#include "socketoutputmessage.hh"
#include "messagebus.hh"
#include <functional>
#include <istream>

using namespace op2p;
using asio::ip::tcp;

SocketConnection::SocketConnection(asio::io_service& svc, const std::string& pwd)
  : service_(svc),
    password_(pwd),
    lineBuffer_(),
    authenticated_(),
    pSocket_() {
}

SocketConnection::~SocketConnection() {
  try {
    close();
  } catch (...) {
    // Stop propagation
  }
}

void SocketConnection::open(std::unique_ptr<asio::ip::tcp::socket>& pSock) {
  if (pSocket_) return;
  pSocket_ = std::move(pSock);
  
  MessageBus::instance()->subscribe<SocketOutputMessage>(this);

  readLineAsync();
}

void SocketConnection::close() {
  if (!pSocket_) return;
  
  MessageBus::instance()->unsubscribe<SocketOutputMessage>(this);

  pSocket_->shutdown(tcp::socket::shutdown_both);
  pSocket_->close();
  pSocket_ = nullptr;

  authenticated_ = false;

  MessageBus::instance()->publish<SocketConnectionClosedMessage>(
    SocketConnectionClosedMessage::create());
}

void SocketConnection::readLineAsync() {
  asio::async_read_until(*pSocket_, lineBuffer_, '\n',
    std::bind(&SocketConnection::handleReadLine, this,
      std::placeholders::_1, std::placeholders::_2));
}

void SocketConnection::handleReadLine(const asio::error_code& error, std::size_t bytesRead) {
  if (error) {
    if (error == asio::error::eof) {
      close();
      return;
    }
    else {
      return; // TODO: Handle error appropriately
    }
  }

  std::istream is{ &lineBuffer_ };
  std::string line;
  std::getline(is, line);

  if (authenticated_) {
    MessageBus::instance()->publish<SocketInputMessage>(
      SocketInputMessage::create(line));

    readLineAsync();
  } else {
    // TODO: Parse line & compare passwords.
  }
}

void SocketConnection::writeAsync(const std::string& line) {
  if (!pSocket_) {
    return; // TODO: Handle error appropriately
  }

  asio::async_write(*pSocket_,
    asio::buffer(line, line.size()),
    std::bind(&SocketConnection::handleWrite, this,
      std::placeholders::_1));
}

void SocketConnection::handleWrite(const asio::error_code& error) {
  if (error) {
    // TODO: Handle error appropriately
  }
}

void SocketConnection::receive(const std::shared_ptr<Message>& pMessage) {
  service_.post([=] {
    writeAsync(pMessage->data() + '\n');
  });
}