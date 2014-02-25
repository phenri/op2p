#ifndef PROTOCOLHANDLERFACTORY_HH
#define PROTOCOLHANDLERFACTORY_HH

#include "protocolhandler.hh"
#include <string>
#include <unordered_map>
#include <functional>
#include <memory>

namespace op2p {
  class ProtocolHandlerFactory {
    typedef std::unordered_map<std::string, 
      std::function<ProtocolHandler*()>> HandlerMap;

    static const HandlerMap protocols_;
    static ProtocolHandlerFactory instance_;

  public:
    ProtocolHandlerFactory();
    ~ProtocolHandlerFactory();

    ProtocolHandlerFactory(const ProtocolHandlerFactory&) = delete;
    ProtocolHandlerFactory& operator=(const ProtocolHandlerFactory&) = delete;

    static ProtocolHandlerFactory* instance();

    std::shared_ptr<ProtocolHandler> handler(std::string);
  };
}

#endif // !PROTOCOLHANDLERFACTORY_HH
