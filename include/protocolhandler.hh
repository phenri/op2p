#ifndef PROTOCOLHANDLER_HH
#define PROTOCOLHANDLER_HH

namespace op2p {
  enum class Protocol {
    uci,
    xboard
  };

  struct ProtocolHandler {
    virtual ~ProtocolHandler() {}
    virtual Protocol protocol() const = 0;
  };
}

#endif // !PROTOCOLHANDLER_HH
