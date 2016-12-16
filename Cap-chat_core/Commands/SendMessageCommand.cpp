//
// Created by juzeg on 13.12.16.
//

#include "SendMessageCommand.h"
#include <Services/Encryption.h>
#include <Services/NetworkService.h>

SendMessageCommand::SendMessageCommand(std::string text, NetworkService *networkService) : _text(text), _networkService(
        networkService) {}

void SendMessageCommand::execute() {
    // std::cout << "message coded     >"  <<testing_string << "<"<< std::endl; //will be changed to real sending function
    // std::cout << " uncoded    >" << Encryption::EncryptText(testing_string)<< "<" << std::endl;
    _networkService->sendData((char *) _text.c_str());
}

void SendMessageCommand::updateText(std::string newText) {
    _text=newText;
}
