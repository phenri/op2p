#include "settingsstore.hh"

using namespace op2p;

const std::string SettingsStore::fileName_{ "op2p.ini" };

const Settings SettingsStore::defaultSettings_{
  "Twas brillig, and the slithy toves did gyre and gimble in the wabe",
  "localhost",
  "8000",
  ""
};

SettingsStore::SettingsStore()
  : dataFile_(),
    settings_(defaultSettings_) {
}

void SettingsStore::load() {
  if (dataFile_.Load(fileName_)) {
    populateSettings();
  } else {
    populateDataFile();
    dataFile_.SetFileName(fileName_);
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
