#include <iostream>
#include "tableCipher.h"

int main() {
    std::string key;
    std::cout << "Enter the number of columns: ";
    std::cin >> key;

    TableCipher cipher(key);

    std::string text;
    std::cout << "Enter the text to encrypt: ";
    std::cin.ignore();
    std::getline(std::cin, text);

    std::string encrypted = cipher.encrypt(text);
    std::cout << "Encrypted text: " << encrypted << std::endl;

    std::string decrypted = cipher.decrypt(encrypted);
    std::cout << "Decrypted text: " << decrypted << std::endl;

    return 0;
}