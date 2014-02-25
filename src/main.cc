#include "consolemanager.hh"
#include <iostream>
#include <exception>

using namespace op2p;

int main() {
  try {
    ConsoleManager cm;
    cm.run();
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
}
