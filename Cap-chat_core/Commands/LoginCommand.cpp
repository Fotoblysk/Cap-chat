//
// Created by juzeg on 06.12.16.
//

#include "LoginCommand.h"

#include <Account.h>


LoginCommand::LoginCommand(std::string name, std::string password):_name(name),_password(password) {}

void LoginCommand::execute() {
    Account::login(_name,_password);
}
