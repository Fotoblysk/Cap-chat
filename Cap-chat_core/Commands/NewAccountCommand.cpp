//
// Created by fotoblysk on 06.12.16.
//

#include <Models/Account.h>
#include "NewAccountCommand.h"

NewAccountCommand::NewAccountCommand(std::string name, std::string password) : _name(name), _password(password) {}

void NewAccountCommand::execute() {
    Account::newAccount(_name, _password);
}
