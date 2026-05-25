#include "head.h"

// Node

Node::Node(int val, Node* par) : data(val), left(nullptr), right(nullptr), parent(par) {}

Node::~Node() {}

int Node::get_data() const {
    return data;
}

Node* Node::get_left() const {
    return left;
}

Node* Node::get_right() const {
    return right;
}

Node* Node::get_parent() const {
    return parent;
}

void Node::set_data(int val) {
    data = val;
}

void Node::set_left(Node* node) {
    left = node;
}

void Node::set_right(Node* node) {
    right = node;
}

void Node::set_parent(Node* node) {
    parent = node;
}

bool Node::is_leaf() const {
    return (left == nullptr && right == nullptr);
}

// PrintTree

void PrintTree::print_tree(Node* root, const std::string& title) {
    if (!root) {
        std::cout << title << "Дерево пустое" << std::endl;
        return;
    }
    std::cout << title << std::endl;
    print_recursive(root, 0, "", true);
}

void PrintTree::print_recursive(Node* node, int level, std::string prefix, bool is_last) {
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

void PrintTree::print_list(Node* head, const std::string& title) {
    if (!head) {
        std::cout << title << "Список пуст" << std::endl;
        return;
    }
    std::cout << title << std::endl;

    Node* current = head;
    while (current) {
        std::cout << "- " << current->get_data() << " ";
        current = current->get_right();
    }
    std::cout << std::endl;
    std::cout << std::endl;
}

// bst

BinSearchTree::BinSearchTree() : root(nullptr) {}

BinSearchTree::~BinSearchTree() {
    clear_tree();
}

void BinSearchTree::clear_tree() {
    clear_rec(root);
    root = nullptr;
}

void BinSearchTree::clear_rec(Node* node) {
    if (!node) return;
    clear_rec(node->get_left());
    clear_rec(node->get_right());
    delete node;
}

void BinSearchTree::insert(int val) {
    root = insert_rec(root, val, nullptr);
}

Node* BinSearchTree::insert_rec(Node* node, int val, Node* parent) {
    if (!node) return new Node(val, parent);

    if (val < node->get_data()) {
        node->set_left(insert_rec(node->get_left(), val, node));
    }
    else if (val > node->get_data()) {
        node->set_right(insert_rec(node->get_right(), val, node));
    }
    return node;
}

void BinSearchTree::input_console() {
    clear_tree();

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
    clear_tree();
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
    clear_tree();

    std::string filename;
    std::cout << "Введите имя файла: ";
    std::cin >> filename;

    if (!Validator::file_exists(filename)) {
        std::cout << "Ошибка: файл не найден!" << std::endl;
        return;
    }

    std::ifstream file(filename);
    int n;
    file >> n;

    std::cout << "Числа из файла: ";
    for (int i = 0; i < n; i++) {
        int x;
        file >> x;
        std::cout << x << " ";
        insert(x);
    }
    std::cout << std::endl;
    file.close();
}

void BinSearchTree::inorder_convert(Node* node, Node*& prev, Node*& head) {
    if (!node) return;

    // левое поддерево
    inorder_convert(node->get_left(), prev, head);

    // текущий узел
    node->set_left(prev);

    if (prev) {
        prev->set_right(node);
    }
    else {
        head = node;
    }

    prev = node;

    // правое поддерево
    inorder_convert(node->get_right(), prev, head);
}

Node* BinSearchTree::convert_to_list() {
    if (!root) return nullptr;

    Node* prev = nullptr;
    Node* head = nullptr;

    inorder_convert(root, prev, head);

    if (prev) {
        prev->set_right(nullptr);
    }

    return head;
}

int BinSearchTree::get_list_length(Node* head) {
    int len = 0;
    Node* current = head;
    while (current) {
        len++;
        current = current->get_right();
    }
    return len;
}

Node* BinSearchTree::sorted_list_to_bst(Node*& head, int n) {
    if (n <= 0 || !head) return nullptr;

    Node* left = sorted_list_to_bst(head, n / 2);

    Node* root = head;
    root->set_left(left);

    head = head->get_right();

    root->set_right(sorted_list_to_bst(head, n - n / 2 - 1));

    return root;
}

void BinSearchTree::convert_from_list(Node* head) {
    if (!head) {
        root = nullptr;
        return;
    }

    int len = get_list_length(head);
    root = sorted_list_to_bst(head, len);
}

Node* BinSearchTree::find_node_rec(Node* node, int value) {
    if (!node) return nullptr;
    if (node->get_data() == value) return node;

    Node* left_result = find_node_rec(node->get_left(), value);
    if (left_result) return left_result;

    return find_node_rec(node->get_right(), value);
}

Node* BinSearchTree::find_node(int value) {
    return find_node_rec(root, value);
}

bool TreeFun7::is_leaf(Node* node) {
    return node && !node->get_left() && !node->get_right();
}

void TreeFun7::add_right(Node* node, std::vector<int>& result) {
    if (!node) return;
    if (is_leaf(node)) return;

    result.push_back(node->get_data());

    if (node->get_right()) {
        add_right(node->get_right(), result);
    } else if (node->get_left()) {
        add_right(node->get_left(), result);
    }
}

void TreeFun7::add_leaves_reverse(Node* node, std::vector<int>& result) {
    if (!node) return;

    if (is_leaf(node)) {
        result.push_back(node->get_data());
        return;
    }

    add_leaves_reverse(node->get_right(), result);
    add_leaves_reverse(node->get_left(), result);
}

void TreeFun7::add_left_reverse(Node* node, std::vector<int>& result) {
    if (!node) return;
    if (is_leaf(node)) return;

    if (node->get_left()) {
        add_left_reverse(node->get_left(), result);
    } else if (node->get_right()) {
        add_left_reverse(node->get_right(), result);
    }

    result.push_back(node->get_data());
}

std::vector<int> TreeFun7::clockwise(Node* root) {
    std::vector<int> result;
    if (!root) return result;

    result.push_back(root->get_data());

    if (is_leaf(root)) return result;

    add_right(root->get_right(), result);

    add_leaves_reverse(root, result);

    add_left_reverse(root->get_left(), result);

    return result;
}

void TreeFun7::print_bounds(const std::vector<int>& bounds) {
    for (size_t i = 0; i < bounds.size(); i++) {
        std::cout << bounds[i];
        if (i < bounds.size() - 1) {
            std::cout << " -> ";
        }
    }
    std::cout << std::endl;
}

// TreeFun11

std::vector<int> TreeFun11::get_fire_order(Node* root, int start_value) {
    std::vector<int> result;
    if (!root) return result;

    // очередь нужна для поиска в ширину
    std::queue<Node*> find_q;
    find_q.push(root);
    Node* start = nullptr;

    while (!find_q.empty()) {
        Node* node = find_q.front();
        find_q.pop();
        if (node->get_data() == start_value) {
            start = node;
            break;
        }
        if (node->get_left()) find_q.push(node->get_left());
        if (node->get_right()) find_q.push(node->get_right());
    }

    if (!start) return result;

    // поиск в ширину для распространения пожара
    std::queue<std::pair<Node*, int>> q;
    std::unordered_set<Node*> visited;

    q.push({start, 0});
    visited.insert(start);

    while (!q.empty()) {
        auto [node, time] = q.front();
        q.pop();

        result.push_back(node->get_data());

        // левый ребенок
        if (node->get_left() && !visited.count(node->get_left())) {
            visited.insert(node->get_left());
            q.push({node->get_left(), time + 1});
        }

        // правый ребенок
        if (node->get_right() && !visited.count(node->get_right())) {
            visited.insert(node->get_right());
            q.push({node->get_right(), time + 1});
        }

        // родитель
        if (node->get_parent() && !visited.count(node->get_parent())) {
            visited.insert(node->get_parent());
            q.push({node->get_parent(), time + 1});
        }
    }

    return result;
}

void TreeFun11::print_fire_order(const std::vector<int>& order) {
    std::cout << "Порядок возгорания узлов:\n";
    for (size_t i = 0; i < order.size(); i++) {
        std::cout << order[i];
        if (i < order.size() - 1) {
            std::cout << " -> ";
        }
    }
    std::cout << std::endl;
}

//validator

bool Validator::file_exists(const std::string& filename) {
    std::ifstream f(filename.c_str());
    return f.good();
}

bool Validator::validate_tree_file(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) return false;

    int n;
    file >> n;
    if (n <= 0) return false;

    for (int i = 0; i < n; i++) {
        int x;
        if (!(file >> x)) return false;
    }
    return true;
}