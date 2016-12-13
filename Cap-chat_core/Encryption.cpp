//
// Created by juzeg on 07.12.16.
//

#include "Encryption.h"

std::string Encryption::EncryptText(std::string text) {
    const std::string krypt_ring[5] = {"EKMFLGDQVZNTOWYHXUSPAIBRCJ",
                                            "AJDKSIRUXBLHWTMCQGZNPYFVOE",
                                            "BDFHJLCPRTXVZNYEIWGAKMUSQO",
                                            "ESOVPZJAYQUIRHXLNFTGKDCMWB",
                                            "VZBRGITYUPSDNHLXAWMJQOFECK"};
    const std::string transition = "RFWKA";
    const std::string reverse_bell = "YRUHQSLDPXNGOKMIEBFZCWVJAT";
    int ring[3], i, j, k, n, c;
    bool turn;
    std::string code, coded_string, connector;



    std::cin >> n;

    for (i = 2; i >= 0; i--) {
        ring[i] = (n % 10) - 1;
        n /= 10;
    }

    std::cin >> code;
    for (i = 0; i < code.length(); i++) code[i] = toupper(code[i]);

    std::cin >> coded_string;
    for (i = 0; i < coded_string.length(); i++) coded_string[i] = toupper(coded_string[i]);

    connector = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (i = 0; i < coded_string.length() - 1; i += 2) {
        connector[coded_string[i] - 65] = coded_string[i + 1];
        connector[coded_string[i + 1] - 65] = coded_string[i];
    }

    std::cin.ignore(256, '\n');
    getline(std::cin, coded_string);
    for (i = 0; i < coded_string.length(); i++) coded_string[i] = toupper(coded_string[i]);

    for (i = 0; i < coded_string.length(); i++) {

        for (turn = true, j = 2; turn && (j >= 0); j--) {
            turn = (code[j] == transition[ring[j]]);
            code[j] = 65 + (code[j] - 64) % 26;
        }

        c = coded_string[i];
        c = connector[c - 65];

    }

    for (j = 2; j >= 0; j--) {
        k = code[j] - 65;
        c = krypt_ring[ring[j]][(c - 65 + k) % 26];
        c = 65 + (c - 39 - k) % 26;
    }

    c = reverse_bell[c - 65];


    for (j = 0; j < 3; j++) {
        k = code[j] - 65;
        c = 65 + (c - 65 + k) % 26;
        for (n = 0; krypt_ring[ring[j]][n] != c; n++);
        c = 65 + (26 + n - k) % 26;
    }

    c = connector[c - 65];


    coded_string[i] = c;


    return coded_string;


}
