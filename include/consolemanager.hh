#ifndef CONSOLEMANAGER_HH
#define CONSOLEMANAGER_HH

#include "messagereceiver.hh"
#include "asio.hpp"
#include <thread>

namespace op2p {
  class ConsoleManager : public MessageReceiver {
    asio::io_service service_;
    asio::io_service::work work_;
    std::thread worker_;
    asio::signal_set signals_;

    void awaitStopAsync();

  public:
    ConsoleManager();
    virtual ~ConsoleManager();

    ConsoleManager(const ConsoleManager&) = delete;
    ConsoleManager& operator=(const ConsoleManager&) = delete;

    void run();
    virtual void receive(const std::shared_ptr<Message>&) override;
  };
}

#endif // !CONSOLEMANAGER_HH
