//
// Created by juzeg on 07.12.16.
//

#include "Encryption.h"

std::string Encryption::EncryptText(std::string text) {


      int  lenght,counter;
       lenght = 0;
       counter = 0;

    lenght = text.length();




    while (counter <= (lenght-1) )
    {
     text = text.insert(1+(5*counter), "dupa");

        counter++;
    }



    return text ;


}
