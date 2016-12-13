//
// Created by fotoblysk on 06.12.16.
//

#ifndef CAP_CHAT_NEWACCOUNTCOMMAND_H
#define CAP_CHAT_NEWACCOUNTCOMMAND_H

#include <string>
#include "ICommand.h"

class NewAccountCommand : public ICommand {
public:
    NewAccountCommand(std::string name, std::string password);

    void execute() override;

private:
    std::string _name, _password;
};


#endif //CAP_CHAT_NEWACCOUNTCOMMAND_H
