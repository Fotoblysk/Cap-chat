//
// Created by fotoblysk on 15.12.16.
//

#include <iostream>
#include <cstring>
#include "NetworkService.h"

NetworkService::NetworkService() {
    // listenerSocket.setBlocking(false);
    // tcpSocket.setBlocking(false);
    if (listenerSocket.isBlocking())
        std::cout << "listener blocking" << std::endl;
    if (tcpSocket.isBlocking())
        std::cout << "tcp blocking" << std::endl;
}

void NetworkService::update() {
    std::size_t received;
    char data[255];
    if (tcpSocketReciver.getLocalPort() != 0)
        if (tcpSocketReciver.receive(data, 255, received) == sf::Socket::Done) {
            std::cout << "got data" << std::endl;
            std::cout << data << std::endl;
        }
}

bool NetworkService::startConnection(std::string ip, unsigned int port, sf::Time timeout) {
    if (ip != "") {
        if (tcpSocket.connect(sf::IpAddress(ip), port, timeout) == sf::Socket::Done)
            if (tcpSocketReciver.connect(sf::IpAddress(ip), port + 1, timeout) == sf::Socket::Done) {
                std::cout << "Connected to" << ip << std::endl;
                return true;
            } else
                return false;
    } else {
        std::cout << "listening" << std::endl;
        if (listenerSocket.listen(port) == sf::Socket::Done)
            if (listenerSocket.accept(tcpSocketReciver) == sf::Socket::Done)
                if (listenerSocket2.listen(port+1) == sf::Socket::Done)
                    if (listenerSocket2.accept(tcpSocket) == sf::Socket::Done) {
                        std::cout << "Connected to" << tcpSocket.getRemoteAddress().toString() << std::endl;
                        return true;
                    } else
                        return false;
                else
                    return false;
    }
    return false;
}

bool NetworkService::sendData(char *sendData) {
    std::copy(sendData, sendData + std::strlen(sendData), _sendData);
    if (tcpSocket.send(_sendData, 255) == sf::Socket::Done) {
        std::cout << "sending" << std::endl;
        return true;
    }
    std::cout << "sender fail" << std::endl;
    return false;
}

