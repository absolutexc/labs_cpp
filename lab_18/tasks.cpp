#include "head.h"

void TreeWork::task_treefun1(BinSearchTree& tree) {
    std::cout << "Задача 1. TreeFun1\n";

    create_tree(tree);

    PrintTree::print_tree(tree.get_root(), "\nИсходное дерево:\n");

    Node* list_head = tree.convert_to_list();

    PrintTree::print_list(list_head, "\nПолученный двусвязный список:\n");
}

void task1(BinSearchTree& tree) {
    TreeWork::task_treefun1(tree);
}

void TreeWork::task_treefun7(BinSearchTree& tree) {
    std::cout << "Задача 2. TreeFun7\n";

    create_tree(tree);

    PrintTree::print_tree(tree.get_root(), "\nИсходное дерево:\n");

    std::vector<int> boundary = TreeFun7::clockwise(tree.get_root());

    std::cout << "\nОбход кромки кроны:\n";
    TreeFun7::print_bounds(boundary);
}

void task2(BinSearchTree& tree) {
    TreeWork::task_treefun7(tree);
}

void TreeWork::task_treefun11(BinSearchTree& tree) {
    std::cout << "Задача 3. TreeFun11\n";

    create_tree(tree);

    PrintTree::print_tree(tree.get_root(), "\nИсходное дерево:\n");

    int start_value;
    std::cout << "\nВведите значение узла, с которого начинается пожар: ";
    start_value = get_positive();

    std::vector<int> fire_order = TreeFun11::get_fire_order(tree.get_root(), start_value);

    if (fire_order.empty()) {
        std::cout << "Узел со значением " << start_value << " не найден в дереве!\n";
    }
    else {
        TreeFun11::print_fire_order(fire_order);
    }
}

void task3(BinSearchTree& tree) {
    TreeWork::task_treefun11(tree);
}