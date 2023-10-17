#include <string>

class TableCipher {
public:
    TableCipher(int columns);
    std::string encrypt(const std::string& plaintext);
    std::string decrypt(const std::string& ciphertext);

private:
    int numColumns;
};

