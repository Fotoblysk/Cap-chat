//
// Created by fotoblysk on 27.11.16.
//
//#include <stdlib.h>
#include <iostream>
#include "Command.h"
#include "Account.h"
#include "CapChat.h"
#include "CmdInputHandler.h"


CapChat::CapChat() {
    inputHandler = new CmdInputHandler; // StrategyPattern here, we can change to SFML input handling later
    // TODO change to std::unique_ptr (smart pointers) from c++11
}

void CapChat::run() {
    while (inputHandler->handleInput());
}

CapChat::~CapChat() {
    // we don't like memory leaks
    delete inputHandler;
}



