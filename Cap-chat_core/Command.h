//
// Created by juzeg on 03.12.16.
//

#ifndef CAP_CHAT_COMMAND_H
#define CAP_CHAT_COMMAND_H

#include <iostream>
#include <string>

class Command {
public:
    std::string cmd = ""; // we dont need storing currennt command string here

    void clearScr(); // we can use smart ICommand pattern here :)


};


#endif //CAP_CHAT_COMMAND_H
