//
// Created by juzeg on 13.12.16.
//

#include "SendMessageCommand.h"
#include <Encryption.h>

SendMessageCommand::SendMessageCommand(std::string text) : _text(text) {}

void SendMessageCommand::execute() {
std::string testing_string;
    testing_string = Encryption::EncryptText(_text);
    std::cout << "message coded     >"  <<testing_string << "<"<< std::endl; //will be changed to real sending function
   std::cout << " uncoded    >" << Encryption::EncryptText(testing_string)<< "<" << std::endl;

}
