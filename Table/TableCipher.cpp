#include "TableCipher.h"

TableCipher::TableCipher(int columns) {
    numColumns = columns;
}

std::string TableCipher::encrypt(const std::string& plaintext) {
    int textLength = plaintext.length();
    int numRows = (textLength + numColumns - 1) / numColumns;

    // Создаем пустую таблицу
    char** table = new char*[numRows];
    for (int i = 0; i < numRows; i++) {
        table[i] = new char[numColumns];
    }

    int textIndex = 0;
    // Заполняем таблицу сначала символами из plaintext, затем пробелами
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numColumns; j++) {
            if (textIndex < textLength) {
                table[i][j] = plaintext[textIndex];
                textIndex++;
            } else {
                table[i][j] = ' '; // Заполняем пробелами, если текст закончился
            }
        }
    }

    std::string ciphertext;
    for (int j = 0; j < numColumns; j++) {
        for (int i = 0; i < numRows; i++) {
            ciphertext.push_back(table[i][j]);
        }
    }

    for (int i = 0; i < numRows; i++) {
        delete[] table[i];
    }
    delete[] table;

    return ciphertext;
}

std::string TableCipher::decrypt(const std::string& ciphertext) {
    int textLength = ciphertext.length();
    int numRows = (textLength + numColumns - 1) / numColumns;

    // Создаем пустую таблицу
    char** table = new char*[numRows];
    for (int i = 0; i < numRows; i++) {
        table[i] = new char[numColumns];
    }

    int textIndex = 0;
    for (int j = 0; j < numColumns; j++) {
        for (int i = 0; i < numRows; i++) {
            table[i][j] = ciphertext[textIndex];
            textIndex++;
        }
    }

    std::string plaintext;
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numColumns; j++) {
            if (table[i][j] != ' ') {
                plaintext.push_back(table[i][j]);
            }
        }
    }

    for (int i = 0; i < numRows; i++) {
        delete[] table[i];
    }
    delete[] table;

    return plaintext;
}

