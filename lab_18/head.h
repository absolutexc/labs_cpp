#ifndef CPP_HEAD_H
#define CPP_HEAD_H

#include <iostream>
#include <vector>
#include <ctime>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include <stack>
#include <queue>
#include <unordered_set>

// функции ввода/вывода
void show_menu();
void clear_input();
int get_not_neg();
int get_positive();
bool is_empty(class Node* root);
int get_height(class Node* root);
int count_nodes(class Node* root);

class Node{
public:
    Node(int val, Node* par = nullptr);
    ~Node();

    int get_data() const;
    Node* get_left() const;
    Node* get_right() const;
    Node* get_parent() const;
    void set_data(int val);
    void set_left(Node* node);
    void set_right(Node* node);
    void set_parent(Node* node);
    bool is_leaf() const;

private:
    int data;
    Node* left;
    Node* right;
    Node* parent;
};

class PrintTree {
public:
    static void print_tree(Node* root, const std::string& title);
    static void print_list(Node* head, const std::string& title);
private:
    static void print_recursive(Node* node, int level, std::string prefix, bool is_last);
};

class BinSearchTree {
public:
    BinSearchTree();
    ~BinSearchTree();

    void clear_tree();
    void insert(int val);

    void input_console();
    void input_random();
    void input_file();

    Node* get_root() const { return root; }
    void set_root(Node* node) { root = node; }

    // TreeFun1
    Node* convert_to_list();

    // TreeFun7
    void convert_from_list(Node* head);

    // TreeFun11
    Node* find_node(int value);

private:
    Node* root;
    Node* insert_rec(Node* node, int val, Node* parent);
    void clear_rec(Node* node);
    void inorder_convert(Node* node, Node*& prev, Node*& head);
    int get_list_length(Node* head);
    Node* sorted_list_to_bst(Node*& head, int n);
    Node* find_node_rec(Node* node, int value);
};

class TreeFun7 {
public:
    static std::vector<int> clockwise(Node* root);
    static void print_bounds(const std::vector<int>& bounds);
private:
    static bool is_leaf(Node* node);
    static void add_right(Node* node, std::vector<int>& result);
    static void add_leaves_reverse(Node* node, std::vector<int>& result);
    static void add_left_reverse(Node* node, std::vector<int>& result);
};

class TreeFun11 {
public:
    static std::vector<int> get_fire_order(Node* root, int start_value);
    static void print_fire_order(const std::vector<int>& order);
};

class Validator {
public:
    static bool file_exists(const std::string& filename);
    static bool validate_tree_file(const std::string& filename);
};

class TreeWork {
public:
    static void task_treefun1(BinSearchTree& tree);
    static void task_treefun7(BinSearchTree& tree);
    static void task_treefun11(BinSearchTree& tree);
};

void create_tree(BinSearchTree& tree);

void task1(BinSearchTree& tree);
void task2(BinSearchTree& tree);
void task3(BinSearchTree& tree);

#endif