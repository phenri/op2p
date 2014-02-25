#include "consolemanager.hh"
#include "messagebus.hh"
#include "settingsstore.hh"
#include "socketserver.hh"
#include "consoleoutputmessage.hh"
#include "socketoutputmessage.hh"
#include <signal.h>
#include <iostream>
#include <string>
#include <cstdlib>

using namespace op2p;

ConsoleManager::ConsoleManager()
  : service_(), 
    work_(service_), 
    signals_(service_), 
    worker_([=] { service_.run(); }) {
}

ConsoleManager::~ConsoleManager() {
}

void ConsoleManager::receive(const std::shared_ptr<Message>& pMessage) {
  service_.post([=] {
    std::cout << pMessage->data() << std::endl;
  });
}

void ConsoleManager::run() {
  awaitStopAsync();

  MessageBus::instance()->subscribe<ConsoleOutputMessage>(this);

  SettingsStore ss;
  ss.load();

  auto settings = ss.settings();
  SocketServer server{ settings, service_ };

  if (settings.remoteHost == "") {
    // No remote host, start the server.
    server.start();
  }

  std::string line;
  while (std::getline(std::cin, line)) {
    MessageBus::instance()->publish<SocketOutputMessage>(
      SocketOutputMessage::create(line));
  }
}

void ConsoleManager::awaitStopAsync() {
  signals_.add(SIGINT);
  signals_.add(SIGTERM);
#if defined(SIGQUIT)
  signals_.add(SIGQUIT);
#endif

  signals_.async_wait(
    [](std::error_code, int) {
      std::exit(EXIT_SUCCESS);
    });
}
