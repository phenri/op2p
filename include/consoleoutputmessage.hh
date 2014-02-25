#ifndef CONSOLEOUTPUTMESSAGE_HH
#define CONSOLEOUTPUTMESSAGE_HH

#include "message.hh"

namespace op2p {
  struct ConsoleOutputMessage : public Message {
    ConsoleOutputMessage(const std::string& m)
      : Message(m) {}
  };
}

#endif // !CONSOLEOUTPUTMESSAGE_HH
