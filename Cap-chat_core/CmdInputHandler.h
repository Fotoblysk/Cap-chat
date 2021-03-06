//
// Created by fotoblysk on 04.12.16.
//

#ifndef CAP_CHAT_CMDINPUTHANDLER_H
#define CAP_CHAT_CMDINPUTHANDLER_H


#include <atomic>
#include <thread>
#include "InputHandler.h"
#include "CmdView.h"
#include "Models/CapChatData.h"
#include "Commands/ICommand.h"
#include "Services/NetworkService.h"

class CmdInputHandler : public InputHandler {
public:
    enum ChatState {
        Interpreter,
        Chat
    };
    ChatState chatState;

    CmdInputHandler(CmdView *view, CapChatData *data);

    NetworkService networkService;

    void updateChat(std::atomic_bool &ifShouldEnd);

    CapChatData *_data;

    virtual ~CmdInputHandler();

    ICommand *handleInput() override;

    std::atomic_bool a;
    std::thread updateThread;

private:
    CmdView *_view;
};


#endif //CAP_CHAT_CMDINPUTHANDLER_H
