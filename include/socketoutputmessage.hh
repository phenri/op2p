#ifndef SOCKETOUTPUTMESSAGE_HH
#define SOCKETOUTPUTMESSAGE_HH

#include "message.hh"

namespace op2p {
  struct SocketOutputMessage : public Message {
    SocketOutputMessage(const std::string& m)
      : Message(m) {}
  };
}

#endif // !SOCKETOUTPUTMESSAGE_HH
