//
// Created by juzeg on 13.12.16.
//

#ifndef CAP_CHAT_SENDMESSAGE_H
#define CAP_CHAT_SENDMESSAGE_H

#include <string>
#include <Services/NetworkService.h>
#include "ICommand.h"

class SendMessageCommand : public ICommand {
public:
    SendMessageCommand(std::string text, NetworkService *networkService);
    void updateText(std::string newText);
    void execute() override;

private:
    std::string _text;
    NetworkService *_networkService;


};


#endif //CAP_CHAT_SENDMESSAGE_H
