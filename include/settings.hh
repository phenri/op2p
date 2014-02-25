#ifndef SETTINGS_HH
#define SETTINGS_HH

#include <string>

namespace op2p {
  struct Settings {
    Settings::Settings()
      : password(""),
        hostname(""),
        port(""),
        remoteHost("") 
    {}
    Settings::Settings(const std::string& password,
                       const std::string& hostname,
                       const std::string& port,
                       const std::string& remoteHost)
      : password(password),
        hostname(hostname),
        port(port),
        remoteHost(remoteHost) 
    {}

    std::string password;
    std::string hostname;
    std::string port;
    std::string remoteHost;
  };
}

#endif // !SETTINGS_HH
