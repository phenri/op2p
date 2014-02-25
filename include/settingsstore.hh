#ifndef SETTINGSSTORE_HH
#define SETTINGSSTORE_HH

#include "settings.hh"
#include "CDataFile.hpp"

namespace op2p {
  class SettingsStore {
    static const std::string fileName_;
    static const Settings    defaultSettings_;

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
