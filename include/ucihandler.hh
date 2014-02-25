#ifndef UCIHANDLER_HH
#define UCIHANDLER_HH

#include "protocolhandler.hh"

namespace op2p {
  struct UciHandler : public ProtocolHandler {
    UciHandler();
    virtual ~UciHandler();
    virtual Protocol protocol() const;
  };
}

#endif // !UCIHANDLER_HH
