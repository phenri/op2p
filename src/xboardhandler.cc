#include "xboardhandler.hh"

using namespace op2p;

XBoardHandler::XBoardHandler() {
}

XBoardHandler::~XBoardHandler() {
}

Protocol XBoardHandler::protocol() const {
  return Protocol::xboard;
}
