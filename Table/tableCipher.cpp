#include "tableCipher.h"
#include <cmath>

TableCipher::TableCipher(const std::string& key) {
    numCols = std::stoi(key);
}

std::string TableCipher::encrypt(const std::string& openText) {
    if (numCols <= 0 || openText.empty()) {
        return openText;
    }

    const int numRows = static_cast<int>(std::ceil(static_cast<double>(openText.size()) / numCols));
    std::string encryptedText;
    encryptedText.reserve(openText.size());

    for (int col = 0; col < numCols; ++col) {
        for (int row = 0; row < numRows; ++row) {
            int index = row * numCols + col;
            if (index < openText.size()) {
                encryptedText.push_back(openText[index]);
            }
        }
    }

    return encryptedText;
}

std::string TableCipher::decrypt(const std::string& cipherText) {
    if (numCols <= 0 || cipherText.empty()) {
        return cipherText;
    }

    const int numRows = static_cast<int>(std::ceil(static_cast<double>(cipherText.size()) / numCols));
    std::string decryptedText;
    decryptedText.reserve(cipherText.size());

    for (int row = 0; row < numRows; ++row) {
        for (int col = 0; col < numCols; ++col) {
            int index = col * numRows + row;
            if (index < cipherText.size()) {
                decryptedText.push_back(cipherText[index]);
            }
        }
    }

    return decryptedText;
}
