//
// Created by juzeg on 03.12.16.
//

#include "Account.h"
#include <fstream>
#include <iostream>

void Account.NewAccount() {



    std::string filename;
    std::string name;
    std::string password;

    std::cout << "How should i call you?   " << std::endl;
    std::cin >> name;
    filename = name + ".txt";


    std::cout << "file name is   :" << filename << std::endl;

    std::ofstream accountfile;

    accountfile.open(filename.c_str());

    if (accountfile.good()) {
        std::cout << "file created!" << std::endl;

        accountfile << name;
        accountfile << "\n";
        std::cout << "Please insert your passoword" << std::endl;
        std::cin >> password;
        accountfile << password;
    } else std::cout << "file creation fail" << std::endl;







}