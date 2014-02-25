#ifndef SOCKETINPUTMESSAGE_HH
#define SOCKETINPUTMESSAGE_HH

#include "message.hh"

namespace op2p {
  struct SocketInputMessage : public Message {
    SocketInputMessage(const std::string& m)
      : Message(m) {}
  };
}

#endif // !SOCKETINPUTMESSAGE_HH
