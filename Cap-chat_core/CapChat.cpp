//
// Created by fotoblysk on 27.11.16.
//
#include <stdlib.h>
#include <iostream>
#include "CapChat.h"
#include "command.h"
#include "account.h"


CapChat::CapChat() {
    account::CCaccount user;
    command comm;
    std::cout << "Please insert command " << std::endl;
    while (true) {


        std::cin >> comm.comd;
        comm.clear();
        if (comm.comd == "kill") {
            exit(0);
        }
        if (comm.comd == "new") {



              user.newacc();
        }
        else
        {
            std::cout << "You entered unknown command please try again"<< std::endl;
        }


    }


}
