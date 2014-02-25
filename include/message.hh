#ifndef MESSAGE_HH
#define MESSAGE_HH

#include <string>
#include <memory>

namespace op2p {
  class Message {
  protected:
    std::string data_;

    Message(const std::string& data = "") : data_(data) {}

  public:
    static std::shared_ptr<Message> create(const std::string& data = "") {
      return std::shared_ptr<Message>{ new Message{ data } };
    }

    virtual ~Message() {};
    
    virtual std::string data() const {
      return data_;
    }
  };
}

#endif // !MESSAGE_HH
