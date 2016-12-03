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
    while (command.comd != "kill") { // more clear than exit(0) try to not use it its antipattern


        std::cin >> command.comd;
        command.clear();

        if (command.comd == "new") { account.newAccount(); }
        if (command.comd == "kill") { std::cout << "shutting down" << std::endl; }
        if(command.comd == "login") {account.login();}

        }


    }



