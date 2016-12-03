//
// Created by fotoblysk on 27.11.16.
//
#include <stdlib.h>
#include <iostream>
#include "CapChat.h"
#include "Command.h"
#include "Account.h"


CapChat::CapChat() {

    Command Comm;
    std::cout << "Please insert command " << std::endl;
    while (true) {


        std::cin >> Comm.comd;
        Comm.clear();
        if (Comm.comd == "kill") {
            exit(0);
        }
        if (Comm.comd == "new") {


            Account.NewAccount();
        } else {
            std::cout << "You entered unknown command please try again" << std::endl;
        }


    }


}
