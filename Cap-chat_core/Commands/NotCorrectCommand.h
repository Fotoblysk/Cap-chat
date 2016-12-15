//
// Created by fotoblysk on 15.12.16.
//

#ifndef CAP_CHAT_NOTCORRECTCOMMAND_H
#define CAP_CHAT_NOTCORRECTCOMMAND_H


#include "ICommand.h"

class NotCorrectCommand: public ICommand {
public:
    void execute() override;
};


#endif //CAP_CHAT_NOTCORRECTCOMMAND_H
