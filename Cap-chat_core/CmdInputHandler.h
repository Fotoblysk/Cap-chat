//
// Created by fotoblysk on 04.12.16.
//

#ifndef CAP_CHAT_CMDINPUTHANDLER_H
#define CAP_CHAT_CMDINPUTHANDLER_H


#include <map>
#include "InputHandler.h"
#include "CmdView.h"
#include "Account.h"
#include "CapChatData.h"
#include "Commands/ICommand.h"

class CmdInputHandler : public InputHandler {
public:
    CmdInputHandler(CmdView* view, CapChatData* data);
    CapChatData* _data;
    virtual ~CmdInputHandler();

    ICommand* killCommand;  //TODO we can use std::map to map Commands to strings
    ICommand* loginCommand;
    ICommand* newAccountCommand;
    CmdView* _view;
private:
    ICommand * handleInput() override;
};


#endif //CAP_CHAT_CMDINPUTHANDLER_H
