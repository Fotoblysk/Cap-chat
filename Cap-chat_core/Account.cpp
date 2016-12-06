//
// Created by juzeg on 03.12.16.
//

#include "Account.h"
#include <fstream>


void Account::newAccount() {


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
    accountfile.close();

}

std::string Account::login() {
    std::string name;
    std::string readName;
    std::string readPassword;
    std::string password;
    std::string filename;

    std::cout << "Please type in your name " << std::endl;
    std::cin >> name;
    std::cout << "\n Plaease type in your passoword \n ";
    std::cin >> password;

    std::fstream accountfile;

    filename = name + ".txt";
    accountfile.open(filename.c_str(), std::ios::in);

    if (accountfile.good()) {
        getline(accountfile, readName);
        getline(accountfile, readPassword);
        if ((readName == name) && (readPassword == password)) {
            std::cout << "logged succesfully!" << std::endl;
            return name;
        }
    } else { std::cout << "no such user on this computer " << std::endl; }
    accountfile.close();
    return "";

}