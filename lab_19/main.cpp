// #include "head.h"
//
// void printCat() {
//     std::cout << "\n";
//     std::cout << "       /\\_/\\  " << std::endl;
//     std::cout << "      ( o.o ) " << std::endl;
//     std::cout << "       > ^ <  " << std::endl;
//     std::cout << "      мяу!    " << std::endl;
// }
//
// void printMenu() {
//     std::cout << "\n1. Код Хемминга" << std::endl;
//     // std::cout << "2. Код Хаффмана" << std::endl;
//     // std::cout << "3. Shifr4" << std::endl;
//     std::cout << "0. Выход" << std::endl;
//     std::cout << "Ваш выбор: \n";
// }
//
// int main() {
//     srand(static_cast<unsigned>(time(nullptr)));
//     // std::string huffmanText = "КУПИ КИПУ ПИК, КИПУ ПИК КУПИ";
//     // std::string vigenereText = "КУПИ КИПУ ПИК, КИПУ ПИК КУПИ";
//     // std::string vigenereKey = "КУПИ";
//
//     int choice;
//
//     do {
//         printMenu();
//         std::cin >> choice;
//
//         switch (choice) {
//             case 1:
//                 printHammingProcess();
//                 break;
//             // case 2:
//             //     printHuffmanProcess(huffmanText);
//             //     break;
//             // case 3:
//             //     printVigenereProcess(vigenereText, vigenereKey, true);
//             //     break;
//             case 0:
//                 std::cout << "\nВыход." << std::endl;
//                 break;
//             default:
//                 std::cout << "Ошибка! Неверный выбор. Попробуйте снова." << std::endl;
//                 break;
//         }
//     } while (choice != 0);
//
//     printCat();
//
//     return 0;
// }