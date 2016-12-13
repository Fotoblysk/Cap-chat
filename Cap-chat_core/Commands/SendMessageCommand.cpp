//
// Created by juzeg on 13.12.16.
//

#include "SendMessageCommand.h"
#include <Encryption.h>

SendMessageCommand::SendMessageCommand(std::string text) : _text(text) {}

void SendMessageCommand::execute() {

    std::cout << Encryption::EncryptText(_text); //will be changed to real sending function


}
