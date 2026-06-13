// #include "head.h"
//
// // ЗАДАЧА 1: КОД ХЕММИНГА
// int getControlBitsCount(int dataBits) {
//     int r = 0;
//     while (std::pow(2, r) < dataBits + r + 1) {
//         r++;
//     }
//     return r;
// }
//
// std::string hammingEncode(const std::string& data) {
//     int m = data.length();
//     int r = getControlBitsCount(m);
//     int total = m + r;
//
//     std::vector<int> bits(total + 1, 0);
//
//     int dataIndex = 0;
//     for (int i = 1; i <= total; i++) {
//         if ((i & (i - 1)) == 0) {
//             bits[i] = 0;
//         } else {
//             bits[i] = data[dataIndex++] - '0';
//         }
//     }
//
//     for (int i = 1; i <= total; i++) {
//         if ((i & (i - 1)) == 0) {
//             int parity = 0;
//             for (int j = i + 1; j <= total; j++) {
//                 if (j & i) {
//                     parity ^= bits[j];
//                 }
//             }
//             bits[i] = parity;
//         }
//     }
//
//     std::string result;
//     for (int i = 1; i <= total; i++) {
//         result += bits[i] + '0';
//     }
//     return result;
// }
//
// int findErrorPosition(const std::string& received) {
//     int n = received.length();
//     int errorPos = 0;
//
//     for (int i = 1; i <= n; i++) {
//         if ((i & (i - 1)) == 0) {
//             int parity = 0;
//             for (int j = i; j <= n; j++) {
//                 if (j & i) {
//                     parity ^= (received[j-1] - '0');
//                 }
//             }
//             if (parity != 0) {
//                 errorPos += i;
//             }
//         }
//     }
//     return errorPos;
// }
//
// std::pair<std::string, int> hammingDecode(const std::string& received) {
//     int errorPos = findErrorPosition(received);
//     std::string corrected = received;
//
//     if (errorPos != 0 && errorPos <= (int)received.length()) {
//         corrected[errorPos - 1] = (corrected[errorPos - 1] == '0') ? '1' : '0';
//     }
//
//     std::string data;
//     for (int i = 1; i <= (int)corrected.length(); i++) {
//         if ((i & (i - 1)) != 0) {
//             data += corrected[i - 1];
//         }
//     }
//
//     return {data, errorPos};
// }
//
// std::string inputMessageFromConsole() {
//     std::string message;
//     std::cout << "Введите двоичное сообщение (только 0 и 1): ";
//     std::cin >> message;
//
//     // Проверка, что ввод состоит только из 0 и 1
//     bool valid = true;
//     for (char c : message) {
//         if (c != '0' && c != '1') {
//             valid = false;
//             break;
//         }
//     }
//
//     while (!valid || message.empty()) {
//         std::cout << "Ошибка! Введите только 0 и 1: ";
//         std::cin >> message;
//         valid = true;
//         for (char c : message) {
//             if (c != '0' && c != '1') {
//                 valid = false;
//                 break;
//             }
//         }
//     }
//
//     return message;
// }
//
// std::string generateRandomMessage() {
//     int length;
//     std::string input;
//     bool valid = false;
//
//     std::cout << "Введите длину сообщения (от 1 до 30): ";
//
//     while (!valid) {
//         std::cin >> input;
//
//         // Проверка, что ввод состоит только из цифр
//         bool isNumber = true;
//         for (char c : input) {
//             if (c < '0' || c > '9') {
//                 isNumber = false;
//                 break;
//             }
//         }
//
//         if (isNumber) {
//             length = std::stoi(input);
//             if (length >= 1 && length <= 30) {
//                 valid = true;
//             } else {
//                 std::cout << "Ошибка! Длина должна быть от 1 до 30. Повторите ввод: ";
//             }
//         } else {
//             std::cout << "Ошибка! Введите целое число от 1 до 30: ";
//         }
//     }
//
//     std::string message;
//     for (int i = 0; i < length; i++) {
//         message += (rand() % 2) + '0';
//     }
//
//     std::cout << "Сгенерированное сообщение: " << message << std::endl;
//     return message;
// }
//
// std::string selectInputMethod() {
//     int choice;
//     std::string input;
//     bool valid = false;
//
//     std::cout << "\nВыберите способ ввода исходного сообщения:" << std::endl;
//     std::cout << "1. Консоль" << std::endl;
//     std::cout << "2. Рандомно" << std::endl;
//     std::cout << "Ваш выбор: ";
//
//     while (!valid) {
//         std::cin >> input;
//
//         if (input.length() == 1 && (input[0] == '1' || input[0] == '2')) {
//             choice = input[0] - '0';
//             valid = true;
//         } else {
//             std::cout << "Ошибка! Введите 1 или 2: ";
//         }
//     }
//
//     if (choice == 1) {
//         return inputMessageFromConsole();
//     } else {
//         return generateRandomMessage();
//     }
// }
//
// void printHammingProcess() {
//
//     std::string data = selectInputMethod();
//
//     std::cout << "\nИсходное сообщение: " << data << std::endl;
//     std::cout << "Длина сообщения: " << data.length() << " бит" << std::endl;
//
//     int m = data.length();
//     int r = getControlBitsCount(m);
//     int total = m + r;
//
//     std::cout << "Количество контрольных битов: " << r << std::endl;
//     std::cout << "Общая длина кода: " << total << " бит" << std::endl;
//     std::cout << "Контрольные биты на позициях: ";
//     for (int i = 1; i <= total; i++) {
//         if ((i & (i - 1)) == 0) {
//             std::cout << i << " ";
//         }
//     }
//     std::cout << std::endl;
//
//     // Таблица позиций
//     std::cout << "\nПозиции битов в коде Хемминга:" << std::endl;
//     std::cout << "Поз: ";
//     for (int i = 1; i <= total; i++) {
//         std::cout << std::setw(3) << i;
//     }
//     std::cout << std::endl;
//     std::cout << "Тип: ";
//     for (int i = 1; i <= total; i++) {
//         if ((i & (i - 1)) == 0) {
//             std::cout << std::setw(3) << "C";
//         } else {
//             std::cout << std::setw(3) << "D";
//         }
//     }
//     std::cout << std::endl;
//
//     // Вывод размещения данных
//     std::cout << "Дан: ";
//     int dataIdx = 0;
//     for (int i = 1; i <= total; i++) {
//         if ((i & (i - 1)) == 0) {
//             std::cout << std::setw(3) << "?";
//         } else {
//             std::cout << std::setw(3) << data[dataIdx++];
//         }
//     }
//     std::cout << std::endl;
//
//     std::string encoded = hammingEncode(data);
//     std::cout << "\nЗакодированное сообщение: " << encoded << std::endl;
//
//     // Расчёт контрольных битов
//     std::cout << "\nРасчет контрольных битов:" << std::endl;
//     std::vector<int> bits(total + 1, 0);
//     dataIdx = 0;
//     for (int i = 1; i <= total; i++) {
//         if ((i & (i - 1)) == 0) {
//             bits[i] = 0;
//         }
//         else {
//             bits[i] = data[dataIdx++] - '0';
//         }
//     }
//
//     for (int i = 1; i <= total; i++) {
//         if ((i & (i - 1)) == 0) {
//             int parity = 0;
//             std::cout << "C" << i << " (поз." << i << "): проверяет биты ";
//             for (int j = i + 1; j <= total; j++) {
//                 if (j & i) {
//                     std::cout << j << " ";
//                     parity ^= bits[j];
//                 }
//             }
//             bits[i] = parity;
//             std::cout << "-> сумма по модулю 2 = " << parity << std::endl;
//         }
//     }
//
//     std::cout << "\nИтоговое закодированное сообщение: " << encoded << std::endl;
//
//     std::cout << "\nОбнаружение и исправление ошибки" << std::endl;
//     std::cout << "Закодированное сообщение: " << encoded << std::endl;
//
//     int errorBit;
//     std::cout << "\nВведите позицию ошибочного бита (от 1 до " << total << "): ";
//     std::cin >> errorBit;
//
//     while (errorBit < 1 || errorBit > total) {
//         std::cout << "Ошибка! Позиция должна быть от 1 до " << total << ". Повторите ввод: ";
//         std::cin >> errorBit;
//     }
//
//     std::string withError = encoded;
//     withError[errorBit - 1] = (withError[errorBit - 1] == '0') ? '1' : '0';
//
//     std::cout << "\nВнесена ошибка в позицию " << errorBit << std::endl;
//     std::cout << "Был бит: " << encoded[errorBit - 1] << ", стал: " << withError[errorBit - 1] << std::endl;
//     std::cout << "Сообщение с ошибкой: " << withError << std::endl;
//
//     // Поиск ошибки по синдромам
//     std::cout << "\nВычисление синдромов:" << std::endl;
//     int errorPos = 0;
//     for (int i = 1; i <= total; i++) {
//         if ((i & (i - 1)) == 0) {
//             int parity = 0;
//             std::cout << "Синдром S" << i << " (проверка C" << i << "): биты ";
//             for (int j = i; j <= total; j++) {
//                 if (j & i) {
//                     std::cout << j << " ";
//                     parity ^= (withError[j-1] - '0');
//                 }
//             }
//             std::cout << "-> сумма = " << parity;
//             if (parity != 0) {
//                 std::cout << " (НЕ НОЛЬ, ошибка в позиции " << i << ")";
//                 errorPos += i;
//             } else {
//                 std::cout << " (НОЛЬ, правильно)";
//             }
//             std::cout << std::endl;
//         }
//     }
//
//     std::cout << "\nСиндром (позиция ошибки в десятичном виде): " << errorPos << std::endl;
//
//     if (errorPos == 0) {
//         std::cout << "Ошибок не обнаружено!" << std::endl;
//     } else if (errorPos > total) {
//         std::cout << "Ошибка в контрольном бите? Позиция " << errorPos << " выходит за пределы." << std::endl;
//     } else {
//         std::cout << "Ошибка обнаружена в позиции " << errorPos << std::endl;
//
//         // исправление ошибки
//         std::string corrected = withError;
//         corrected[errorPos-1] = (corrected[errorPos-1] == '0') ? '1' : '0';
//         std::cout << "Исправленное сообщение: " << corrected << std::endl;
//
//         // Декодирование
//         std::string decoded;
//         for (int i = 1; i <= (int)corrected.length(); i++) {
//             if ((i & (i - 1)) != 0) {
//                 decoded += corrected[i-1];
//             }
//         }
//         std::cout << "Декодированные данные: " << decoded << std::endl;
//
//         // Проверка с исходными данными
//         if (decoded == data) {
//             std::cout << "\nДекодирование выполнено. Данные совпадают с исходными." << std::endl;
//         }
//         else {
//             std::cout << "\nДекодированные данные не совпадают с исходными." << std::endl;
//             std::cout << "  Исходные: " << data << std::endl;
//             std::cout << "  Получено: " << decoded << std::endl;
//         }
//     }
// }
//
// // ========== ЗАДАЧА 2: КОД ХАФФМАНА ==========
// void buildFrequencyTable(const std::string& text, std::map<char, int>& freq) {
//     for (char c : text) {
//         freq[c]++;
//     }
// }
//
// HuffmanNode* buildHuffmanTree(const std::map<char, int>& freq) {
//     std::priority_queue<HuffmanNode*, std::vector<HuffmanNode*>, Compare> pq;
//
//     for (auto& p : freq) {
//         pq.push(new HuffmanNode(p.first, p.second));
//     }
//
//     while (pq.size() > 1) {
//         HuffmanNode* left = pq.top(); pq.pop();
//         HuffmanNode* right = pq.top(); pq.pop();
//         HuffmanNode* parent = new HuffmanNode(left->freq + right->freq, left, right);
//         pq.push(parent);
//     }
//
//     return pq.empty() ? nullptr : pq.top();
// }
//
// void buildCodes(HuffmanNode* root, std::string code, std::map<char, std::string>& codes) {
//     if (!root) return;
//
//     if (root->ch != 0) {
//         codes[root->ch] = code;
//     }
//
//     buildCodes(root->left, code + "0", codes);
//     buildCodes(root->right, code + "1", codes);
// }
//
// void printHuffmanCodes(const std::map<char, std::string>& codes) {
//     std::cout << "\nКоды символов:" << std::endl;
//     std::cout << "-----------------------------------------" << std::endl;
//     for (auto& p : codes) {
//         if (p.first == ' ') {
//             std::cout << "Символ: ' '  -> Код: " << p.second << std::endl;
//         } else if (p.first == ',') {
//             std::cout << "Символ: ','  -> Код: " << p.second << std::endl;
//         } else {
//             std::cout << "Символ: " << p.first << "   -> Код: " << p.second << std::endl;
//         }
//     }
// }
//
// void printHuffmanTree(HuffmanNode* root, int indent) {
//     if (!root) return;
//
//     if (root->ch != 0) {
//         if (root->ch == ' ') {
//             std::cout << std::string(indent, ' ') << "|--- ' ' (" << root->freq << ")" << std::endl;
//         } else if (root->ch == ',') {
//             std::cout << std::string(indent, ' ') << "|--- ',' (" << root->freq << ")" << std::endl;
//         } else {
//             std::cout << std::string(indent, ' ') << "|--- " << root->ch << " (" << root->freq << ")" << std::endl;
//         }
//     } else {
//         std::cout << std::string(indent, ' ') << "|--- * (" << root->freq << ")" << std::endl;
//         printHuffmanTree(root->left, indent + 4);
//         printHuffmanTree(root->right, indent + 4);
//     }
// }
//
// int calculateUniformSize(const std::string& text, const std::map<char, int>& freq) {
//     int uniqueChars = freq.size();
//     int bitsPerChar = std::ceil(std::log2(uniqueChars));
//     return text.length() * bitsPerChar;
// }
//
// int calculateHuffmanSize(const std::string& text, const std::map<char, std::string>& codes) {
//     int total = 0;
//     for (char c : text) {
//         total += codes.at(c).length();
//     }
//     return total;
// }
//
// void deleteHuffmanTree(HuffmanNode* root) {
//     if (!root) return;
//     deleteHuffmanTree(root->left);
//     deleteHuffmanTree(root->right);
//     delete root;
// }
//
// void printHuffmanProcess(const std::string& text) {
//     std::cout << "\n========== ЗАДАЧА 2: КОД ХАФФМАНА ==========" << std::endl;
//     std::cout << "Исходный текст: " << text << std::endl;
//
//     std::map<char, int> freq;
//     buildFrequencyTable(text, freq);
//
//     std::cout << "\n--- ЧАСТОТА СИМВОЛОВ ---" << std::endl;
//     for (auto& p : freq) {
//         if (p.first == ' ') {
//             std::cout << "' ' : " << p.second << std::endl;
//         } else if (p.first == ',') {
//             std::cout << "',' : " << p.second << std::endl;
//         } else {
//             std::cout << p.first << " : " << p.second << std::endl;
//         }
//     }
//
//     HuffmanNode* root = buildHuffmanTree(freq);
//     std::map<char, std::string> codes;
//     buildCodes(root, "", codes);
//
//     printHuffmanCodes(codes);
//
//     std::cout << "\n--- ДЕРЕВО ХАФФМАНА ---" << std::endl;
//     printHuffmanTree(root, 0);
//
//     std::cout << "\n--- ЗАКОДИРОВАННОЕ СООБЩЕНИЕ ---" << std::endl;
//     std::cout << "Текст в кодах Хаффмана:" << std::endl;
//     for (char c : text) {
//         std::cout << codes[c];
//     }
//     std::cout << std::endl;
//
//     int uniformSize = calculateUniformSize(text, freq);
//     int huffmanSize = calculateHuffmanSize(text, codes);
//
//     std::cout << "\n--- СРАВНЕНИЕ РАЗМЕРОВ ---" << std::endl;
//     std::cout << "Длина текста: " << text.length() << " символов" << std::endl;
//     std::cout << "Количество уникальных символов: " << freq.size() << std::endl;
//     std::cout << "Равномерное кодирование: " << uniformSize << " бит" << std::endl;
//     std::cout << "Кодирование Хаффмана: " << huffmanSize << " бит" << std::endl;
//     std::cout << "Экономия: " << uniformSize - huffmanSize << " бит ("
//               << std::fixed << std::setprecision(1) << (100.0 - (huffmanSize * 100.0 / uniformSize)) << "%)" << std::endl;
//
//     deleteHuffmanTree(root);
// }
//
// // ========== ЗАДАЧА 3: ШИФР ВИЖЕНЕРА (Shifr4) ==========
// std::string vigenereEncrypt(const std::string& text, const std::string& key) {
//     std::string result;
//     int keyLen = key.length();
//     int keyIndex = 0;
//
//     for (char c : text) {
//         if ((c >= 'А' && c <= 'Я') || (c >= 'а' && c <= 'я')) {
//             char base = (c >= 'А' && c <= 'Я') ? 'А' : 'а';
//             char keyChar = key[keyIndex % keyLen];
//             char keyBase = (keyChar >= 'А' && keyChar <= 'Я') ? 'А' : 'а';
//             int shift = (keyChar - keyBase);
//
//             int pos = (c - base + shift) % 33;
//             char encrypted = base + pos;
//             result += encrypted;
//             keyIndex++;
//         } else {
//             result += c;
//         }
//     }
//     return result;
// }
//
// std::string vigenereDecrypt(const std::string& text, const std::string& key) {
//     std::string result;
//     int keyLen = key.length();
//     int keyIndex = 0;
//
//     for (char c : text) {
//         if ((c >= 'А' && c <= 'Я') || (c >= 'а' && c <= 'я')) {
//             char base = (c >= 'А' && c <= 'Я') ? 'А' : 'а';
//             char keyChar = key[keyIndex % keyLen];
//             char keyBase = (keyChar >= 'А' && keyChar <= 'Я') ? 'А' : 'а';
//             int shift = (keyChar - keyBase);
//
//             int pos = (c - base - shift + 33) % 33;
//             char decrypted = base + pos;
//             result += decrypted;
//             keyIndex++;
//         } else {
//             result += c;
//         }
//     }
//     return result;
// }
//
// void printVigenereProcess(const std::string& text, const std::string& key, bool encrypt) {
//     std::cout << "\n========== ЗАДАЧА 3: ШИФР ВИЖЕНЕРА (Shifr4) ==========" << std::endl;
//     std::cout << "Исходный текст: " << text << std::endl;
//     std::cout << "Ключ: " << key << std::endl;
//
//     std::string result;
//     if (encrypt) {
//         result = vigenereEncrypt(text, key);
//         std::cout << "\n--- ШИФРОВАНИЕ ---" << std::endl;
//         std::cout << "Зашифрованный текст: " << result << std::endl;
//
//         std::string decrypted = vigenereDecrypt(result, key);
//         std::cout << "Расшифрованный текст: " << decrypted << std::endl;
//     } else {
//         result = vigenereDecrypt(text, key);
//         std::cout << "\n--- ДЕШИФРОВАНИЕ ---" << std::endl;
//         std::cout << "Расшифрованный текст: " << result << std::endl;
//     }
// }