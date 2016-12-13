//
// Created by juzeg on 06.12.16.
//

#ifndef CAP_CHAT_LOGINCOMMAND_H
#define CAP_CHAT_LOGINCOMMAND_H

#include <string>
#include "ICommand.h"


class LoginCommand : public ICommand {
public:
    LoginCommand(std::string name, std::string password);

    void execute() override;

private:
    std::string _name, _password;
};


#endif //CAP_CHAT_LOGINCOMMAND_H
