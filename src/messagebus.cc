#include "messagebus.hh"

using namespace op2p;

MessageBus MessageBus::instance_;

MessageBus::MessageBus()
  : receivers_(),
    receiversLock_() {
}

MessageBus::~MessageBus() {
}

MessageBus* MessageBus::instance() {
  return &instance_;
}
