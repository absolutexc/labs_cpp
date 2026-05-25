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

// функции ввода/вывода
void show_menu();
void clear_input();
int get_not_neg();
int get_positive();
bool is_empty(class Node* root);
int get_height(class Node* root);
int count_nodes(class Node* root);

class Node {
public:
    Node(int val);
    ~Node();

    int get_value() const;
    Node* get_left() const;
    Node* get_right() const;
    void set_value(int val);
    void set_left(Node* node);
    void set_right(Node* node);

    bool is_operator() const;
    bool is_operand() const;
    bool is_variable_x() const;

private:
    int value;
    Node* left;
    Node* right;
};

class PrintTree {
public:
    static void print_tree(Node* root);
    static void print_sideways(Node* root, int width);
    static void print_to_file(Node* root, int x_value, int result, const std::string& filename);
private:
    static void print_recursive(Node* node, int level, std::string prefix, bool is_last);
    static void print_sideways_recursive(Node* node, int level, int width, std::vector<std::string>& output);
    static std::string infix_to_string(Node* node);
    static std::string prefix_to_string(Node* node);
    static std::string postfix_to_string(Node* node);
};

class ExpressionTree {
public:
    ExpressionTree();
    ~ExpressionTree();

    void clear_tree();

    void input_console();
    void input_random();
    void input_file();
    void input_console_infix();

    // CalcTree3
    void build_from_rpn(const std::string& expr);
    void transform_remove_multiplication();
    int evaluate();
    bool has_error() const { return error_flag; }
    void clear_error() { error_flag = false; }

    // CalcTree25
    void build_from_infix(const std::string& expr);
    void transform_replace_non_x_subtrees(int x_value);
    int evaluate_with_x(int x_value);
    int get_priority(char op);
    Node* copy_tree(Node* node);

    Node* get_root() const { return root; }

private:
    Node* root;
    bool error_flag;  // флаг ошибки

    // вспомогательные методы
    int get_operator_code(char op);
    char get_operator_char(int code);
    int evaluate_node(Node* node);
    Node* remove_multiplication(Node* node);
    int evaluate_with_x_recursive(Node* node, int x_value);

    // для инфиксной
    int get_precedence(char op);
    bool is_right_associative(char op);
    std::vector<std::string> infix_to_rpn(const std::string& infix);
    Node* build_from_rpn_tokens(const std::vector<std::string>& tokens);
    bool has_variable_x(Node* node);
    Node* evaluate_subtree(Node* node, int x_value);

    // случайное выражение
    std::string generate_random_rpn(int depth);
    char get_random_operator();
    int get_random_operand();
};

class Validator {
public:
    static bool file_exists(const std::string& filename);
    static bool validate_rpn(const std::string& filename);
    static bool validate_infix(const std::string& filename);
    static bool validate_rpn_string(const std::string& expr);
    static bool validate_infix_string(const std::string& expr);
    static bool check_division_by_zero(const std::string& expr, bool is_rpn);
};

class TreeWork {
public:
    // CalcTree3
    static void task_calctree3(ExpressionTree& tree);
    static void print_root(Node* root);
    // CalcTree25
    static void task_calctree25(ExpressionTree& tree);
};

// выбор способа ввода
void create_tree_rpn(ExpressionTree& tree);
void create_tree_infix(ExpressionTree& tree);

// задачи
void task1(ExpressionTree& tree);  // CalcTree3
void task2(ExpressionTree& tree);  // CalcTree25

#endif