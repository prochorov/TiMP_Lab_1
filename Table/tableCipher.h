#ifndef TABLECIPHER_H
#define TABLECIPHER_H

#include <string>

class TableCipher {
private:
    int numCols;

public:
    TableCipher(const std::string& key);
    std::string encrypt(const std::string& openText);
    std::string decrypt(const std::string& cipherText);
};

#endif
