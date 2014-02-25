#ifndef SOCKETCONNECTIONCLOSEDMESSAGE_HH
#define SOCKETCONNECTIONCLOSEDMESSAGE_HH

#include "message.hh"

namespace op2p {
  struct SocketConnectionClosedMessage : public Message {
    SocketConnectionClosedMessage()
      : Message() {}
  };
}

#endif // !SOCKETCONNECTIONCLOSEDMESSAGE_HH
