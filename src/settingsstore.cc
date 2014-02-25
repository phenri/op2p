#include "settingsstore.hh"

using namespace op2p;

SettingsStore::SettingsStore()
  : dataFile_(),
    settings_(defaultSettings) {
}

void SettingsStore::load() {
  if (dataFile_.Load(fileName)) {
    populateSettings();
  } else {
    populateDataFile();
    dataFile_.SetFileName(fileName);
    dataFile_.Save();
  }
}

void SettingsStore::save(const Settings& newSettings) {
  settings_ = newSettings;
  dataFile_.Save();
}

Settings SettingsStore::settings() const {
  return settings_;
}

void SettingsStore::populateSettings() {
  Settings newSettings{
    dataFile_.GetValue("password"),
    dataFile_.GetValue("hostname"),
    dataFile_.GetValue("port"),
    dataFile_.GetValue("remote host")
  };
  settings_ = newSettings;
}

void SettingsStore::populateDataFile() {
  // TODO: Set comments.
  dataFile_.SetValue("password", settings_.password);
  dataFile_.SetValue("hostname", settings_.hostname);
  dataFile_.SetValue("port", settings_.port);
  dataFile_.SetValue("remote host", settings_.remoteHost);
}
