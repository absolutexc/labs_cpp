#include "head.h"

void create_tree(BinSearchTree& bst) {
  int choice;
  std::cout << "\nВвод данных\n";
  std::cout << "1. Ввод с клавиатуры\n";
  std::cout << "2. Случайный ввод\n";
  std::cout << "3. Ввод из файла\n";
  std::cout << "Выберите способ: ";
  std::cout << std::endl;
  choice = get_positive();

  switch(choice) {
    case 1:
      bst.input_cons();
      break;
    case 2:
      bst.input_random();
      break;
    case 3:
      bst.input_file();
      break;
    default:
      std::cout << "Неверный выбор! Используется ввод с клавиатуры.\n";
      bst.input_cons();
  }
}

void TreeWork::lkp(TreeNode* root, std::vector<int>& result) {
  if (!root) return;
  lkp(root->get_left(), result); // левое
  result.push_back(root->get_data()); // корень
  lkp(root->get_right(), result); // правое
}

void TreeWork::print_result(const std::vector<int>& result) {
  std::cout << "\nTreeWork2 - Вывод в возрастающем порядке:" << std::endl;
  std::cout << "Результат: ";
  for (int val : result) {
    std::cout << val << " ";
  }
  std::cout << std::endl;
}

void task1(BinSearchTree& bst) {
  std::cout << "Задача TreeWork2." << std::endl;

  bst = BinSearchTree();

  create_tree(bst);

  PrintTree::print_tree(bst.root);

  std::vector<int> result;
  TreeWork::lkp(bst.root, result);

  TreeWork::print_result(result);
  std::cout << std::endl;
}

int TreeWork::count_leaves(TreeNode* root) {
  if (!root) return 0;

  if (!root->get_left() && !root->get_right()) return 1;

  return count_leaves(root->get_left()) + count_leaves(root->get_right());
}

void TreeWork::print_result(int leaves_count) {
  std::cout << "Количество листьев: " << leaves_count << std::endl;
}

void task2(BinSearchTree& bst) {
  std::cout << "\nЗадача TreeWork13." << std::endl;

  bst = BinSearchTree();

  create_tree(bst);

  PrintTree::print_tree(bst.root);

  int leaves_count = TreeWork::count_leaves(bst.root);

  TreeWork::print_result(leaves_count);
  std::cout << std::endl;
}

int TreeWork::count_nodes(TreeNode* root, int k) {
  if (!root) return 0;
  if (k == 0) return 1;

  // Рекурсивно считаем на уровне k-1 в левом и правом поддеревьях
  return count_nodes(root->get_left(), k - 1) +
         count_nodes(root->get_right(), k - 1);
}

void TreeWork::print_result(int nodes_count, int level) {
  std::cout << "Количество вершин на уровне " << level << '=' << nodes_count << std::endl;
}

void task3(BinSearchTree& bst) {
  std::cout << "Задача 3. TreeWork21" << std::endl;

  bst = BinSearchTree();

  create_tree(bst);

  PrintTree::print_tree(bst.root);

  std::cout << "Введите уровень K (корень - уровень 0): ";
  int k = get_not_neg();

  int nodes_count = TreeWork::count_nodes(bst.root, k);

  TreeWork::print_result(nodes_count, k);
  std::cout << std::endl;
}