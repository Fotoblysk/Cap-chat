//
// Created by fotoblysk on 04.12.16.
//

#include <iostream>
#include <Commands/ICommand.h>
#include "CmdInputHandler.h"
#include "Account.h"
#include "Command.h"

ICommand* CmdInputHandler::handleInput() { // TODO use ICommand pattern here
    std::string command;
    std::cout << "Please insert command " << std::endl;
    Account account;
    std::cin >> command;    // look we don't really need to store string as a class var :), it can be a local var
    Command::clearScr();

    if (command == "kill")
        return false;   // exiting a program returning booleans for state is not so clear but i try to change small
                        // ammount of code in single feature


    else if (command == "new") {
        account.newAccount();   // this is not 100% separated input from program logic
        return true;           // we need po get this logic to our main loop
    }                          // we want to return functoin we want to execute (search for ICommand patern)
    else if (command == "login") {
        account.login();
        return true;
    }
}

