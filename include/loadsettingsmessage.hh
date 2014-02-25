#ifndef LOADSETTINGSMESSAGE_HH
#define LOADSETTINGSMESSAGE_HH

#include "message.hh"
#include "settings.hh"

namespace op2p {
  class LoadSettingsMessage : public Message {
    const Settings& settings_;

  public:
    LoadSettingsMessage(const Settings& s)
    : Message(), settings_(s) {}

    Settings settings() const {
      return settings_;
    }
  };
}

#endif // !LOADSETTINGSMESSAGE_HH
