//
// Created by fotoblysk on 04.12.16.
//

#ifndef CAP_CHAT_CMDINPUTHANDLER_H
#define CAP_CHAT_CMDINPUTHANDLER_H


#include <map>
#include "InputHandler.h"
#include "Command.h"

class CmdInputHandler : public InputHandler {
public:
    Command* killCommand;
    Command* loginCommand;
    Command* killCommand;
private:
    bool handleInput() override;
};


#endif //CAP_CHAT_CMDINPUTHANDLER_H
