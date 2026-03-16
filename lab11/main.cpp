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
            else {
                break;
            }
        }

        switch (choice) {
            case 0: std::cout << "Выход из программы."; break;
            case 1: task_listwork68(); break;
            case 2: task_listwork42(); break;
            case 3: task_listwork64(); break;
            case 4: task_listwork47(); break;
            case 5: task5(); break;
            default:
                std::cout << "Выберите число от 0 до 5!" << std::endl;
                std::cout << std::endl;
        }
    } while (choice != 0);

    return 0;
}