//
// Created by juzeg on 13.12.16.
//

#include "SendMessageCommand.h"
#include <Encryption.h>
#include <NetworkService.h>

SendMessageCommand::SendMessageCommand(std::string text, NetworkService *networkService) : _text(text), _networkService(
        networkService) {}

void SendMessageCommand::execute() {
    // std::string testing_string;
    // testing_string = Encryption::EncryptText(_text);
    // std::cout << "message coded     >"  <<testing_string << "<"<< std::endl; //will be changed to real sending function
    // std::cout << " uncoded    >" << Encryption::EncryptText(testing_string)<< "<" << std::endl;
    std::cout<<"sending "<<_text<<std::endl;
    _networkService->sendData((char *) _text.c_str());
}
