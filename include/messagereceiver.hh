#ifndef MESSAGERECEIVER_HH
#define MESSAGERECEIVER_HH

#include "message.hh"

namespace op2p {
  struct MessageReceiver {
    MessageReceiver() {}
    virtual ~MessageReceiver() {}
    
    virtual void receive(const std::shared_ptr<Message>&) = 0;
  };
}

#endif // !MESSAGERECEIVER_HH
