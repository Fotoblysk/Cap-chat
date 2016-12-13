//
// Created by fotoblysk on 27.11.16.
//
#include <memory>
#include "CmdView.h"
#include "CapChat.h"
#include "CmdInputHandler.h"


CapChat::CapChat() {
    inputHandler = new CmdInputHandler(new CmdView,
                                       new CapChatData); // StrategyPattern here, we can change to SFML input handling later
    // TODO change to std::unique_ptr (smart pointers) from c++11
}

void CapChat::run() {
    do {
        _currentCommand.reset(inputHandler->handleInput());
        if (_currentCommand)
            _currentCommand->execute();
    } while (_currentCommand);
}

CapChat::~CapChat() {
    // we don't like memory leaks
    delete inputHandler;
}



