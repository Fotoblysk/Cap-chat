//
// Created by juzeg on 30.11.16.
//

#ifndef CAP_CHAT_ACCOUNT_H
#define CAP_CHAT_ACCOUNT_H

#include <fstream>

class CCaccount {
public:
    void newacc() {

        std::string filename;
        std::string name;
        std::string password;

        std::cout << "How should i call you?   " << std::endl;
        std::cin >> name;
        filename = name + ".txt";


        std::cout << "file name is   :" << filename << std::endl;

        std::ofstream accountfile;

        accountfile.open(filename.c_str());

        if (accountfile.good() == true) {
            std::cout << "file created!" << std::endl;

            accountfile << name ;
            accountfile << "\n";
            std::cout << "Please insert your passoword" << std::endl ;
            std::cin >> password;
            accountfile << password ;
        } else std::cout << "file creation fail" << std::endl;


    }


};

#endif //CAP_CHAT_ACCOUNT_H
