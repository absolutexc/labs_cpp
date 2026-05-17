#include "head.h"

TreeNode::TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}

int TreeNode::get_data() const {
  return data;
}

TreeNode *TreeNode::get_left() const {
  return left;
}

TreeNode *TreeNode::get_right() const {
  return right;
}

void TreeNode::set_data(int val) {
  data = val;
}

void TreeNode::set_left(TreeNode* node) {
  left = node;
}

void TreeNode::set_right(TreeNode* node) {
  right = node;
}

bool TreeNode::is_leaf() const {
  return (left == nullptr && right == nullptr);
}

void PrintTree::print_tree(TreeNode* root) {
  if (!root) {
    std::cout << "Дерево пустое" << std::endl;
    return;
  }
  std::cout << "Графическое представление дерева" << std::endl;
  print_recursive(root, 0, "", true);
}

void PrintTree::print_recursive(TreeNode* node,
                                int level,
                                std::string prefix,
                                bool is_last) {
  if (!node) return;

  std::cout << prefix;

  if (level > 0) {
    if (is_last) {
      std::cout << "└── ";
    } else {
      std::cout << "├── ";
    }
  }

  std::cout << "[" << node->get_data() << "]" << std::endl;

  std::string new_prefix = prefix;
  if (level > 0) {
    if (is_last) {
      new_prefix += "    ";
    } else {
      new_prefix += "│   ";
    }
  } else {
    new_prefix += "    ";
  }

  bool has_right = (node->get_right() != nullptr);

  if (node->get_left()) {
    print_recursive(node->get_left(), level + 1, new_prefix, !has_right);
  }

  if (node->get_right()) {
    print_recursive(node->get_right(), level + 1, new_prefix, true);
  }
}

BinSearchTree::BinSearchTree() : root(nullptr) {}

BinSearchTree::~BinSearchTree() {
  clear_tree(root);
}

void BinSearchTree::clear_tree(TreeNode* node) {
  if (!node) return;
  clear_tree(node->get_left());
  clear_tree(node->get_right());
  delete node;
}

void BinSearchTree::insert(int val) {
  root = insert_rec(root, val);
}

TreeNode* BinSearchTree::insert_rec(TreeNode* node, int val) {
  if (!node) return new TreeNode(val);

  if (val < node->get_data()) {
    node->set_left(insert_rec(node->get_left(), val));
  }
  else if (val > node->get_data()) {
    node->set_right(insert_rec(node->get_right(), val));
  }
  return node;
}

void BinSearchTree::input_cons() {
  int n;
  std::cout << "Введите количество элементов: ";
  n = get_positive();
  std::cout << "Введите числа: ";
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
    insert(x);
  }
}

void BinSearchTree::input_random() {
  std::srand(std::time(0));
  int n;
  std::cout << "Введите количество элементов: ";
  n = get_positive();

  int min_val, max_val;
  std::cout << "Введите диапазон случайных чисел (мин макс): ";
  std::cin >> min_val >> max_val;

  std::cout << "Сгенерированные числа: ";
  for (int i = 0; i < n; i++) {
    int x = min_val + std::rand() % (max_val - min_val + 1);
    std::cout << x << " ";
    insert(x);
  }
  std::cout << std::endl;
}

void BinSearchTree::input_file() {
  std::string filename;
  std::cout << "Введите имя файла: ";
  std::cout << std::endl;
  std::cin >> filename;

  std::ifstream file(filename);
  if (!file.is_open()) {
    std::cout << "Ошибка: не удалось открыть файл " << filename << std::endl;
    return;
  }

  int n;
  file >> n;

  if (n <= 0) {
    std::cout << "Ошибка: в файле некорректное количество элементов" << std::endl;
    file.close();
    return;
  }

  std::cout << "Числа из файла: ";
  for (int i = 0; i < n; i++) {
    int x;
    file >> x;
    std::cout << x << " ";
    insert(x);
  }
  std::cout << std::endl;

  file.close();
  std::cout << "Данные загружены из файла." << std::endl;
}