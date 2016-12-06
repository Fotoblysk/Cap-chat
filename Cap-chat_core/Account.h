//
// Created by juzeg on 03.12.16.
//

#ifndef CAP_CHAT_ACCOUNT_H
#define CAP_CHAT_ACCOUNT_H

#include <iostream>

class Account {
public:
    static void newAccount(std::string name, std::string password);

    static std::string login();//TODO get input reading outside
};


#endif //CAP_CHAT_ACCOUNT_H
