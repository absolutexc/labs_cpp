// #ifndef HEAD_H
// #define HEAD_H
//
// #include <iostream>
// #include <string>
// #include <vector>
// #include <algorithm>
// #include <map>
// #include <set>
// #include <queue>
// #include <cmath>
// #include <iomanip>
//
// // ЗАДАЧА 1: КОД ХЕММИНГА
// std::string hammingEncode(const std::string& data);
// std::pair<std::string, int> hammingDecode(const std::string& received);
// int findErrorPosition(const std::string& received);
// int getControlBitsCount(int dataBits);
// void printHammingProcess(const std::string& data);
//
// // Дополнительные функции для ввода
// std::string inputMessageFromConsole();
// std::string generateRandomMessage();
// std::string selectInputMethod();
// void printHammingProcess();
//
// // ========== ЗАДАЧА 2: КОД ХАФФМАНА ==========
// struct HuffmanNode {
//     char ch;
//     int freq;
//     HuffmanNode* left;
//     HuffmanNode* right;
//     HuffmanNode(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
//     HuffmanNode(int f, HuffmanNode* l, HuffmanNode* r) : ch(0), freq(f), left(l), right(r) {}
// };
//
// struct Compare {
//     bool operator()(HuffmanNode* a, HuffmanNode* b) {
//         return a->freq > b->freq;
//     }
// };
//
// void buildFrequencyTable(const std::string& text, std::map<char, int>& freq);
// HuffmanNode* buildHuffmanTree(const std::map<char, int>& freq);
// void buildCodes(HuffmanNode* root, std::string code, std::map<char, std::string>& codes);
// void printHuffmanCodes(const std::map<char, std::string>& codes);
// void printHuffmanTree(HuffmanNode* root, int indent = 0);
// void printHuffmanProcess(const std::string& text);
// int calculateUniformSize(const std::string& text, const std::map<char, int>& freq);
// int calculateHuffmanSize(const std::string& text, const std::map<char, std::string>& codes);
// void deleteHuffmanTree(HuffmanNode* root);
//
// // ========== ЗАДАЧА 3: ШИФР ВИЖЕНЕРА (Shifr4) ==========
// std::string vigenereEncrypt(const std::string& text, const std::string& key);
// std::string vigenereDecrypt(const std::string& text, const std::string& key);
// void printVigenereProcess(const std::string& text, const std::string& key, bool encrypt);
//
// #endif