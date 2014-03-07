#ifndef PROTOCOLHANDLER_HH
#define PROTOCOLHANDLER_HH

#include <string>

namespace op2p {
  enum class Protocol {
    uci,
    xboard
  };

  struct ProtocolHandler {
    virtual ~ProtocolHandler() {}
    
    virtual Protocol protocol() const = 0;
    virtual void     exec(const std::string&);
  };
}

#endif // !PROTOCOLHANDLER_HH
