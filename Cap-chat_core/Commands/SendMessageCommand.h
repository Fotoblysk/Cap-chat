//
// Created by juzeg on 13.12.16.
//

#ifndef CAP_CHAT_SENDMESSAGE_H
#define CAP_CHAT_SENDMESSAGE_H

#include "iostream"
#include "ICommand.h"

class SendMessageCommand {
public:
    SendMessageCommand(std::string _text);

   void execute() override ;
private:
    std::string _text;


};


#endif //CAP_CHAT_SENDMESSAGE_H
