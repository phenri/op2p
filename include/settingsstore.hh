#ifndef SETTINGSSTORE_HH
#define SETTINGSSTORE_HH

#include "settings.hh"
#include "CDataFile.hpp"

namespace op2p {
  class SettingsStore {
    // static constexpr char* fileName { "op2p.ini" };
    const char* fileName { "op2p.ini" };
    const Settings defaultSettings {
      "Twas brillig, and the slithy toves did gyre and gimble in the wabe",
      "localhost",
      "8000",
      ""
    };
    cdf::CDataFile dataFile_;
    Settings       settings_;

    void populateDataFile();
    void populateSettings();

  public:
    SettingsStore(const SettingsStore&) = delete;
    SettingsStore& operator=(const SettingsStore&) = delete;
    SettingsStore();

    void     load();
    void     save(const Settings&);
    Settings settings() const;
  };
}

#endif // !SETTINGSSTORE_HH
