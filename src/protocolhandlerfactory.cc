#include "protocolhandlerfactory.hh"
#include "ucihandler.hh"
#include "xboardhandler.hh"
#include <algorithm>
#include <locale>

using namespace op2p;

const ProtocolHandlerFactory::HandlerMap ProtocolHandlerFactory::protocols_{
  { "uci",    []{ return new UciHandler(); } },
  { "xboard", []{ return new XBoardHandler(); } }
};

ProtocolHandlerFactory ProtocolHandlerFactory::instance_;

ProtocolHandlerFactory::ProtocolHandlerFactory() {
}

ProtocolHandlerFactory::~ProtocolHandlerFactory() {
}

ProtocolHandlerFactory* ProtocolHandlerFactory::instance() {
  return &instance_;
}

std::shared_ptr<ProtocolHandler> ProtocolHandlerFactory::handler(std::string initStr) {
  // Trim whitespace
  initStr.erase(std::remove_if(initStr.begin(), initStr.end(),
    std::bind(std::isspace<char>, std::placeholders::_1, std::locale::classic())),
    initStr.end());

  // Convert to lowercase
  std::transform(initStr.begin(), initStr.end(), initStr.begin(),
    std::bind2nd(std::ptr_fun(&std::tolower<char>), std::locale::classic()));

  auto it = protocols_.find(initStr);
  auto pHandler = (it == protocols_.end()) ? nullptr : it->second();
  return std::shared_ptr<ProtocolHandler>(pHandler);
}