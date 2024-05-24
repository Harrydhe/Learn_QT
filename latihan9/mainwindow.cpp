#include "mainwindow.h""
#include <iostream>
#include <fstream>

void Encryption::encryptFile(const std::string& inputFile, const std::string& outputFile, const std::string& key) {
    std::ifstream inFile(inputFile, std::ios::binary);
    std::ofstream outFile(outputFile, std::ios::binary);

    if (!inFile || !outFile) {
        std::cerr << "Failed to open file." << std::endl;
        return;
    }

    int keyIndex = 0;
    char ch;
    while (inFile.get(ch)) {
        ch ^= key[keyIndex++ % key.size()];
        outFile.put(ch);
    }

    inFile.close();
    outFile.close();

    std::cout << "File encrypted successfully." << std::endl;
}

void Encryption::decryptFile(const std::string& inputFile, const std::string& outputFile, const std::string& key) {
    std::ifstream inFile(inputFile, std::ios::binary);
    std::ofstream outFile(outputFile, std::ios::binary);

    if (!inFile || !outFile) {
        std::cerr << "Failed to open file." << std::endl;
        return;
    }

    int keyIndex = 0;
    char ch;
    while (inFile.get(ch)) {
        ch ^= key[keyIndex++ % key.size()];
        outFile.put(ch);
    }

    inFile.close();
    outFile.close();

    std::cout << "File decrypted successfully." << std::endl;
}
