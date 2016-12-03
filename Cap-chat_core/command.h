//
// Created by juzeg on 30.11.16.
//

#ifndef CAP_CHAT_COMMAND_H
#define CAP_CHAT_COMMAND_H

#include <iostream>


class command {
public:
    std::string comd = "" ;
void clear()
{
    int i ;
    for( i = 1; i <= 40; i++ )
    {
        std::cout << "\n";
    }

}


};


#endif //CAP_CHAT_COMMAND_H
