#include "head.h"

void show_menu() {
    std::cout << "1. TreeFun1\n";
    std::cout << "2. TreeFun7\n";
    std::cout << "3. TreeFun11\n";
    std::cout << "0. Выход из программы\n";
    std::cout << "\nВыберите пункт меню:\n";
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
            } else {
                std::cout << "Ошибка: введите неотрицательное число.\n";
            }
        } else {
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
            } else {
                std::cout << "Ошибка: введите положительное число.\n";
            }
        } else {
            std::cout << "Ошибка: введите корректное число.\n";
            clear_input();
        }
    } while (!valid_input);

    return number;
}

bool is_empty(Node* root) {
    return root == nullptr;
}

int get_height(Node* root) {
    if (!root) return 0;
    return 1 + std::max(get_height(root->get_left()), get_height(root->get_right()));
}

int count_nodes(Node* root) {
    if (!root) return 0;
    return 1 + count_nodes(root->get_left()) + count_nodes(root->get_right());
}

void create_tree(BinSearchTree& tree) {
    int choice;
    std::cout << "\nВвод данных\n";
    std::cout << "1. Ввод с клавиатуры\n";
    std::cout << "2. Случайный ввод\n";
    std::cout << "3. Ввод из файла\n";
    std::cout << "Выберите способ: ";
    choice = get_positive();

    switch(choice) {
        case 1:
            tree.input_console();
            break;
        case 2:
            tree.input_random();
            break;
        case 3:
            tree.input_file();
            break;
        default:
            std::cout << "Неверный выбор! Используется ввод с клавиатуры.\n";
            tree.input_console();
    }
}