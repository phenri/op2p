#include "ucihandler.hh"

using namespace op2p;

UciHandler::UciHandler() {
}

UciHandler::~UciHandler() {
}

Protocol UciHandler::protocol() const {
  return Protocol::uci;
}
