//
// Created by fotoblysk on 04.12.16.
//

#ifndef CAP_CHAT_INPUTHANDLER_H
#define CAP_CHAT_INPUTHANDLER_H


#include <Commands/ICommand.h>

class InputHandler {// interface
public:
    virtual ICommand * handleInput() = 0;
};


#endif //CAP_CHAT_INPUTHANDLER_H
