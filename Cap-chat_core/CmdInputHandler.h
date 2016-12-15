//
// Created by fotoblysk on 04.12.16.
//

#ifndef CAP_CHAT_CMDINPUTHANDLER_H
#define CAP_CHAT_CMDINPUTHANDLER_H


#include "InputHandler.h"
#include "CmdView.h"
#include "CapChatData.h"
#include "Commands/ICommand.h"

class CmdInputHandler : public InputHandler {
public:
    CmdInputHandler(CmdView* view, CapChatData* data);
    CapChatData* _data;
    virtual ~CmdInputHandler();
    ICommand * handleInput() override;
private:
    CmdView* _view;
};


#endif //CAP_CHAT_CMDINPUTHANDLER_H
