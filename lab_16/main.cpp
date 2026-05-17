#include "head.h"

int main() {
    BinSearchTree my_tree;
    int choice;

    do {
        show_menu();
        choice = get_not_neg();
        switch (choice) {
            case 1: task1(my_tree); break;
            case 2: task2(my_tree); break;
            case 3: task3(my_tree); break;
            case 0: std::cout << "Выход из программы.\n" ; break;
            default: {
                std::cout << "Неверный выбор. Выберите число от 0 до 3!." << std::endl;
                std::cout << std::endl;
                break;
            }
        }
    } while (choice != 0);

    return 0;
}