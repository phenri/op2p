#ifndef XBOARDHANDLER_HH
#define XBOARDHANDLER_HH

#include "protocolhandler.hh"

namespace op2p {
  struct XBoardHandler : public ProtocolHandler {
    XBoardHandler();
    virtual ~XBoardHandler();
    virtual Protocol protocol() const;
  };
}

#endif // !XBOARDHANDLER_HH
