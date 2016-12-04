//
// Created by fotoblysk on 27.11.16.
//
//#include <stdlib.h>
#include <iostream>
#include "Command.h"
#include "Account.h"
#include "CapChat.h"


CapChat::CapChat() {

    Command command;
    std::cout << "Please insert command " << std::endl;
    Account account;
    while (command.cmd != "kill") { // more clear than exit(0) try to not use it its antipattern


        std::cin >> command.cmd;
        command.clearScr();

        if (command.cmd == "new") { account.newAccount(); }
        if (command.cmd == "kill") { std::cout << "shutting down" << std::endl; }
        if (command.cmd == "login") { account.login(); }

    }


}



