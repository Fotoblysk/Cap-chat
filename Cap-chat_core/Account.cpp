//
// Created by juzeg on 03.12.16.
//

#include "Account.h"
#include <fstream>


void Account::newAccount(std::string name, std::string password) {
    std::string filename;

    filename = name + ".txt";

    std::ofstream accountfile;

    accountfile.open(filename.c_str());
    if (accountfile.good()) {
        std::cout << "file created!" << std::endl;
        accountfile << name;
        accountfile << "\n";
        accountfile << password;
    } else std::cout << "file creation fail" << std::endl;
    accountfile.close();
}

std::string Account::login(std::string name, std::string password) {
    std::string readName;
    std::string readPassword;
    std::string filename;



    std::fstream accountfile;

    filename = name + ".txt";
    accountfile.open(filename.c_str(), std::ios::in);

    if (accountfile.good()) {
        getline(accountfile, readName);
        getline(accountfile, readPassword);
        if ((readName == name) && (readPassword == password)) {
            std::cout << "logged succesfully!" << std::endl;
            return name;
        }else {std::cout << "logging data is incorrect " << std::endl;}
    } else { std::cout << "no such user on this computer " << std::endl; }
    accountfile.close();
    return "";

}