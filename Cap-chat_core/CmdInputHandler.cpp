//
// Created by fotoblysk on 04.12.16.
// works only for single words

#include <iostream>
#include <Commands/ICommand.h>
#include <Commands/LoginCommand.h>
#include <Commands/NewAccountCommand.h>
#include <Commands/SendMessageCommand.h>
#include <Commands/NotCorrectCommand.h>
#include "CmdInputHandler.h"

ICommand *CmdInputHandler::handleInput() { // TODO use ICommand pattern here
    std::string command;
    if (chatState == ChatState::Interpreter) {
        std::cout << "Please insert command " << std::endl;
        std::cin >> command;    // look we don't really need to store string as a class var :), it can be a local var
        CmdView::clearScr();

        if (command == "kill") {
            return nullptr;   // exiting a program returning booleans for state is not so clear but i try to change small
            // ammount of code in single feature
        } else if (command == "new") {
            std::string name, password;
            std::cout << "How should i call you?   " << std::endl;
            std::cin >> name;
            std::cout << "file name is   :" << name << ".txt" << std::endl;
            std::cout << "Please insert your passoword" << std::endl;
            std::cin >> password;
            // this is not 100% separated input from program logic
            return new NewAccountCommand(name, password);
        }                          // we want to return functoin we want to execute (search for ICommand patern)
        else if (command == "login") {


            std::string name, password;
            std::cout << "What's your name" << std::endl;
            std::cin >> name;
            std::cout << "Please insert your passoword" << std::endl;
            std::cin >> password;


            return new LoginCommand(name, password);
        } else if (command == "chat") {
            std::string ip;
            std::cout << "Give me ip" << std::endl;
            std::cin >> ip;
            if (ip == "listen")
                ip = "";
            if (networkService.startConnection(ip)) {
                chatState = ChatState::Chat;
                std::cout << "Cap-chat start typing your msg" << std::endl;
                updateThread = std::thread([&]() {
                    updateChat(a);
                });
            }
            std::cout << std::endl;
            a = false;
        }
    } else if (chatState == ChatState::Chat) {
        std::string message;
        std::getline(std::cin, message);
        if (message  == "kill") {
            updateThread.detach();
            return nullptr;   // exiting a program returning booleans for state is not so clear but i try to change small
            // ammount of code in single feature
        }else if(message == "close"){
            chatState = ChatState::Interpreter;
            updateThread.detach();
        }
        std::cout << message << std::endl;
        return new SendMessageCommand(message, &networkService);
    }


    return new NotCorrectCommand;
}

CmdInputHandler::CmdInputHandler(CmdView *view, CapChatData *data) : _view(view), _data(data) {
    chatState = ChatState::Interpreter;
}

CmdInputHandler::~CmdInputHandler() {
    delete _view;
}

void CmdInputHandler::updateChat(std::atomic_bool &ifShouldEnd) {
    while (!ifShouldEnd)
        networkService.update();
}

