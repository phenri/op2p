#include "socketclient.hh"

using namespace op2p;

SocketClient::~SocketClient() {
  try {
    disconnect();
  }
  catch (...) {
    // Stop propagation
  }
}