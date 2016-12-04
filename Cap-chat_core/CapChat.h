//
// Created by fotoblysk on 27.11.16.
//

#ifndef CAP_CHAT_CAPCHAT_H
#define CAP_CHAT_CAPCHAT_H


#include "InputHandler.h"

class CapChat {
public:
    CapChat();
    ~CapChat();
    void run();
    InputHandler * inputHandler;    // TODO change to std::unique_ptr (smart pointers) from c++11
};


#endif //CAP_CHAT_CAPCHAT_H
