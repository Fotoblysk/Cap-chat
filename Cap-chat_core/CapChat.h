//
// Created by fotoblysk on 27.11.16.
//

#ifndef CAP_CHAT_CAPCHAT_H
#define CAP_CHAT_CAPCHAT_H


#include "InputHandler.h"
#include <memory>

class CapChat {
public:
    CapChat();

    ~CapChat();

    void run();

    std::unique_ptr<ICommand> _currentCommand;
    InputHandler *inputHandler;    // TODO change to std::unique_ptr (smart pointers) from c++11
};


#endif //CAP_CHAT_CAPCHAT_H
