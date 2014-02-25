#include "socketserver.hh"
#include "messagebus.hh"
#include "socketconnectionclosedmessage.hh"

using namespace op2p;
using asio::ip::tcp;

SocketServer::SocketServer(const Settings& settings, asio::io_service& svc)
  : service_(svc),
    settings_(settings),
    acceptor_(service_),
    connection_(service_, settings_.password),
    started_() {
}

SocketServer::~SocketServer() {
  try {
    stop();
  } catch (...) {
    // Stop propagation
  }
}

void SocketServer::listen() {
  tcp::resolver r(service_);
  tcp::endpoint ep = *r.resolve({ settings_.hostname, settings_.port });
  
  acceptor_.open(ep.protocol());
  acceptor_.bind(ep);
  acceptor_.listen();
}

void SocketServer::start() {
  if (started_) return;

  MessageBus::instance()->subscribe<SocketConnectionClosedMessage>(this);

  listen();
  acceptAsync();

  started_ = true;
}

void SocketServer::stop() {
  if (!started_) return;

  MessageBus::instance()->unsubscribe<SocketConnectionClosedMessage>(this);

  service_.stop();
  acceptor_.close();
  connection_.close();

  started_ = false;
}

void SocketServer::acceptAsync() {
  auto pSock = new tcp::socket{ service_ };
  acceptor_.async_accept(*pSock,
    [this, pSock](const asio::error_code& error) {
      if (error) {
        acceptAsync();
      } else {
        connection_.open(std::unique_ptr<tcp::socket>{ pSock });
      }
    });
}

void SocketServer::receive(const std::shared_ptr<Message>& pMessage) {
  service_.post([=] {
    acceptAsync();
  });
}
