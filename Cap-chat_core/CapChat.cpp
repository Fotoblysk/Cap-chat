//
// Created by fotoblysk on 27.11.16.
//
//#include <stdlib.h>
#include <iostream>
#include "Command.h"
#include "Account.h"
#include "CapChat.h"


CapChat::CapChat() {

    Command Comm;
    std::cout << "Please insert command " << std::endl;
    Account account;
    while (true) {


        std::cin >> Comm.comd;
        Comm.clear();
        if (Comm.comd == "kill") {
            exit(0);
        }
        if (Comm.comd == "new") {


            account.NewAccount();
        } else {
            std::cout << "You entered unknown command please try again" << std::endl;
        }


    }


}
