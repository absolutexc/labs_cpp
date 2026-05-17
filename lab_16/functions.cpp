#include "head.h"

void show_menu() {
    std::cout << "Главное меню.\n";
    std::cout << "1. TreeWork2.\n";
    std::cout << "2. TreeWork13.\n";
    std::cout << "3. TreeWork21.\n";
    std::cout << "0. Выход из программы\n";
    std::cout << std::endl;
    std::cout << "Выберите пункт меню: " << std::endl;
}

void clear_input() {
    std::cin.clear();
    std::cin.ignore(1000, '\n');
}

int get_not_neg() {
    int number;
    bool valid_input = false;

    do {
        if (std::cin >> number) {
            if (number >= 0) {
                valid_input = true;
            }
            else {
                std::cout << "Ошибка: введите положительное число.\n";
            }
        }
        else {
            std::cout << "Ошибка: введите корректное число.\n";
            clear_input();
        }
    } while (!valid_input);

    return number;
}

int get_positive() {
    int number;
    bool valid_input = false;

    do {
        if (std::cin >> number) {
            if (number > 0) {
                valid_input = true;
            }
            else {
                std::cout << "Ошибка: введите положительное число.\n";
            }
        }
        else {
            std::cout << "Ошибка: введите корректное число.\n";
            clear_input();
        }
    } while (!valid_input);

    return number;
}

bool is_empty(TreeNode* root) {
    return root == nullptr;
}

int get_height(TreeNode* root) {
    if (!root) return 0;
    return 1 + std::max(get_height(root->get_left()), get_height(root->get_right()));
}

int count_nodes(TreeNode* root) {
    if (!root) return 0;
    return 1 + count_nodes(root->get_left()) + count_nodes(root->get_right());
}