#ifndef MESSAGEBUS_HH
#define MESSAGEBUS_HH

#include "messagereceiver.hh"
#include <typeindex>
#include <unordered_map>
#include <deque>
#include <mutex>

namespace op2p {
  class MessageBus {
    typedef std::deque<MessageReceiver* const> DequeMessageReceiverPtr;
    
    static MessageBus instance_;

    std::unordered_map <std::type_index,
      DequeMessageReceiverPtr> receivers_;
    std::mutex receiversLock_;

  public:
    MessageBus();
    ~MessageBus();

    MessageBus(const MessageBus&) = delete;
    MessageBus& operator=(const MessageBus&) = delete;

    static MessageBus* instance();

    template <typename T>
    void subscribe(MessageReceiver* const);

    template <typename T>
    void unsubscribe(MessageReceiver* const);

    template <typename T>
    void publish(const std::shared_ptr<Message>&);
  };
}

#include "messagebus.inl-cc"

#endif // !MESSAGEBUS_HH
