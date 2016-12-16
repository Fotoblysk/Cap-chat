//
// Created by juzeg on 07.12.16.
//

#include "Encryption.h"

class ring {
public:
    std::string input_sequence = " .,abcdefghijklmnoprstuwxyz*1234567890ABCDEFGHIJKLMNOPRSTUWXYZ";
    std::string output_sequence;

    void intialiser(std::string inpt, std::string &oupt)
    {
        int iterator = 0;
        while (iterator < inpt.length()) {

            oupt = oupt + " ";
            iterator = iterator + 1;
        }

        iterator = 0;

        while (iterator <= inpt.length()) {
            oupt[oupt.length() - iterator] = inpt[iterator - 1];



            iterator = iterator + 1;
        }



    }


    void offset(std::string &to_offset, int rate) {
        char first, following;
        int iterator = 0;
        while (rate >= 1) {
            first = to_offset[iterator];
            following = input_sequence[iterator + 1];

            while (to_offset.length() >= iterator) {
                if (iterator == to_offset.length() - 1) {
                    to_offset[0] = first;


                } else {
                    following = to_offset[iterator + 1];
                    input_sequence[iterator + 1] = first;
                    first = following;

                }

                iterator = iterator + 1;
            }


            iterator = 0;
            rate = rate - 1;

        }


        return;
    }
};

std::string swapper(std::string &text, ring &rotary) {


    std::size_t pos;

    int iterator = 0;


    while (iterator <= text.length()) {


        pos = rotary.input_sequence.find_first_of(text[iterator]);

        rotary.offset(rotary.input_sequence, 10);


        text[iterator] = rotary.output_sequence[pos];


        iterator = iterator + 1;
    }


    return text;
}


std::string Encryption::EncryptText(std::string text) {


    ring first;
first.intialiser(first.input_sequence, first.output_sequence);

swapper(text,first);

    return text ;


}
