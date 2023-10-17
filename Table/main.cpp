#include <iostream>
#include "TableCipher.h"

int main() {
    int columns;
    std::cout << "Enter the number of columns: ";
    std::cin >> columns;

    TableCipher cipher(columns);

    int choice;
    std::string text;

    while (true) {
        std::cout << "Choose an operation (1-Encrypt, 2-Decrypt, 0-Exit): ";
        std::cin >> choice;

        if (choice == 0) {
            break;
        } else if (choice == 1) {
            std::cout << "Enter the text: ";
            std::cin.ignore();
            std::getline(std::cin, text);
            std::string encrypted = cipher.encrypt(text);
            std::cout << "Encrypted text: " << encrypted << std::endl;
        } else if (choice == 2) {
            std::cout << "Enter the text: ";
            std::cin.ignore();
            std::getline(std::cin, text);
            std::string decrypted = cipher.decrypt(text);
            std::cout << "Decrypted text: " << decrypted << std::endl;
        }
    }

    return 0;
}
