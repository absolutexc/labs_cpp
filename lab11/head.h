#ifndef CPP_HEAD_H
#define CPP_HEAD_H

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

void print_menu();

// Функции ввода данных ------------------------------------

std::vector<int> input_from_keyboard();
std::vector<int> generate_random(int count);
std::vector<int> read_from_file(const std::string& filename);
int select_input_method();
std::vector<int> get_data_method();

// Структура Node

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value = 0);
};

// Для задачи 1 -----------------------------------------------

class CyclicList {
private:
    Node* head_;
    int size_;

public:
    CyclicList();
    CyclicList(const CyclicList& other);
    ~CyclicList();

    Node* get_head() const { return head_; }
    int get_size() const { return size_; }
    bool is_empty() const;

    void push_back(int value);
    void push_front(int value);
    void pop_back();
    void pop_front();
    void remove(Node* node);
    void clear();
    void print() const;
    std::vector<int> find_max_increasing() const;
};

// Для задачи 2 --------------------------------------------

class DoublyCyclicList {
private:
    Node* head_;
    int size_;

public:
    DoublyCyclicList();
    DoublyCyclicList(const DoublyCyclicList& other);
    ~DoublyCyclicList();

    Node* get_head() const { return head_; }
    int get_size() const { return size_; }
    bool is_empty() const;

    void push_back(int value);
    void push_front(int value);
    void pop_back();
    void pop_front();
    void remove(Node* node);
    void clear();

    Node* process_task_42();

    void print() const;
};

// Для задачи 3 --------------------------------------------

class DoublyList {
private:
    Node* head_;
    Node* tail_;
    int size_;

public:
    DoublyList();
    DoublyList(const DoublyList& other);
    ~DoublyList();

    Node* get_head() const { return head_; }
    Node* get_tail() const { return tail_; }
    int get_size() const { return size_; }
    bool is_empty() const;

    void push_back(int value);
    void push_front(int value);
    void pop_back();
    void pop_front();
    void remove(Node* node);
    void clear();

    void process_task_64(const std::string& filename);

    void print() const;
};

// Для задачи 4 --------------------------------------------

struct TListB {
    Node* barrier;
    Node* current;

    TListB();
    TListB(const TListB& other);
    ~TListB();

    bool is_empty() const;
    void clear();
};

class BarrierLast {
public:
    static void lb_insert_last(TListB& L, int D);
    static void print(const TListB& L);
};

// Функции заданий -----------------------------------------

void task_listwork68();
void task_listwork42();
void task_listwork64();
void task_listwork47();
void task5();

#endif