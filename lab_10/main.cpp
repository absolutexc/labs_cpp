#include <iostream>
#include "head.h"

int main() {
    int choice;
    do {
        print_menu();

        while (true) {
            std::cin >> choice;

            if (std::cin.fail()) {
                std::cout << "Ошибка! Введите число." << std::endl;
                std::cout << std::endl;
                print_menu();
                std::cin.clear();
                std::cin.ignore(100, '\n');
            }
            else if (choice < 0 || choice > 4) {
                std::cout << "Ошибка! Введите число от 0 до 4." << std::endl;
            }
            else {
                break;
            }
        }

        switch (choice) {
            case 0: std::cout << "Выход из программы."; break;
            case 1: task_dynamic13(); break;
            case 2: task_dynamic14(); break;
            case 3: task_listwork11(); break;
            case 4: task_listwork24(); break;
            default:
                std::cout << "Выберите число от 0 до 4!" << std::endl;
        }
    } while (choice != 0);

    return 0;
}