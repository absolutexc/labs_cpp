#ifndef CPP_HEAD_H
#define CPP_HEAD_H

#include <iostream>
#include <vector>
#include <ctime>
#include <fstream>
#include <string>

void show_menu();
void clear_input();
int get_not_neg();
int get_positive();

class TreeNode {
public:
    TreeNode(int val);

    int get_data() const;

    TreeNode *get_left() const;

    TreeNode *get_right() const;

    void set_data(int val);
    void set_left(TreeNode* node);
    void set_right(TreeNode* node);

    bool is_leaf() const;
private:
    int data;
    TreeNode* left;
    TreeNode* right;
};

class PrintTree {
public:
    static void print_tree(TreeNode* root);
private:
    static void print_recursive(TreeNode* node,
                                int level,
                                std::string prefix, bool is_last);
};

class BinSearchTree {
public:
    BinSearchTree(); //конструктор
    ~BinSearchTree(); //деструктор
    void insert(int val);
    void input_cons();
    void input_random();
    void input_file();

    TreeNode* root;
private:
    TreeNode* insert_rec(TreeNode* node, int val);
    void clear_tree(TreeNode* node);
};

class TreeWork { // класс проверок
public:
    // TreeWork2
    static void lkp(TreeNode* root, std::vector<int>& result);
    static void print_result(const std::vector<int>& result);
    // TreeWork13
    static int count_leaves(TreeNode* root);
    static void print_result(int leaves_count);
    // TreeWork21
    static int count_nodes(TreeNode* root, int k);
    static void print_result(int nodes_count, int level);
};

void select_input_method(BinSearchTree& bst);
void task1(BinSearchTree& bst);
void task2(BinSearchTree& bst);
void task3(BinSearchTree& bst);

#endif