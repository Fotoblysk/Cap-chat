//
// Created by fotoblysk on 15.12.16.
//

#ifndef CAP_CHAT_NETWORKSERVICE_H
#define CAP_CHAT_NETWORKSERVICE_H

#include <SFML/Network.hpp>
class NetworkService {
public:
    NetworkService();
    bool sendData(char sendData[254]);
    void update();
    bool startConnection(std::string ip = "", unsigned int port = 6666, sf::Time timeout = sf::seconds(10.0));
private:

    sf::TcpSocket tcpSocket;
    sf::TcpSocket tcpSocketReciver;

    char _sendData[255];

    sf::TcpListener listenerSocket;
    sf::TcpListener listenerSocket2;
};


#endif //CAP_CHAT_NETWORKSERVICE_H
