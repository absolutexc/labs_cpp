#include "head.h"

void TreeWork::print_root(Node* root) {
    std::cout << "Указатель на корень полученного дерева: " << root << std::endl;
}

void TreeWork::task_calctree3(ExpressionTree& tree) {
    std::cout << "CalcTree3\n";
    std::cout << "Выражение ЛПК\n";
    std::cout << "Операнды: 0-9, операции: + (-1) - (-2) * (-3) / (-4) % (-5)\n";

    create_tree_rpn(tree);

    std::cout << "До преобразования:\n";
    PrintTree::print_tree(tree.get_root());

    tree.transform_remove_multiplication();

    std::cout << "\nПосле удаления умножения:\n";
    PrintTree::print_tree(tree.get_root());

    std::cout << "\nРезультат вычисления:\n";
    int result = tree.evaluate();
    std::cout << result << std::endl;

    print_root(tree.get_root());
    std::cout << std::endl;
}

void TreeWork::task_calctree25(ExpressionTree& tree) {
    std::cout << "CalcTree25\n";
    std::cout << "Задача: заменить поддеревья без переменной x на их значения\n";
    std::cout << "Выражение ЛКП\n";
    std::cout << "Операнды: 1-30, операции: + - * / % ^\n";

    create_tree_infix(tree);

    std::cout << "\nДо преобразования:\n";
    PrintTree::print_sideways(tree.get_root(), 8);

    int x_value;
    std::cout << "\nВведите значение переменной x: ";
    x_value = get_not_neg();

    int result = tree.evaluate_with_x(x_value);

    std::cout << "Значение выражения при x = " << x_value << ": " << result << std::endl;

    // заменяем поддеревья без x
    tree.transform_replace_non_x_subtrees(x_value);

    PrintTree::print_to_file(tree.get_root(), x_value, result, "FN2.txt");

    std::cout << "\nПосле замены поддеревьев без x:\n";
    PrintTree::print_sideways(tree.get_root(), 8);

    std::cout << std::endl;
}

void task1(ExpressionTree& tree) {
    TreeWork::task_calctree3(tree);
}

void task2(ExpressionTree& tree) {
    TreeWork::task_calctree25(tree);
}