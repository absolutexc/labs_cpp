#ifndef CPP_HEAD_H
#define CPP_HEAD_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

void print_menu();

// Функции ввода данных ------------------------------------

std::vector<int> input_from_keyboard();
std::vector<int> generate_random(int count);
std::vector<int> read_from_file(const std::string& filename);
int select_input_method();
std::vector<int> get_data_method();

// Для задачи 1 -----------------------------------------------

struct TNode {
    int Data;
    TNode* Next;
};

class TStack { // класс для стека
private:
    TNode* top_;  // указатель на вершину

public:
    // конструкторы
    TStack();                     // по умолчанию
    TStack(const TStack& other);  // копирования
    ~TStack();                    // деструктор

    // операции
    void push(int value);
    int pop();                     // удалить и вернуть значение элемента
    int peek() const;
    bool is_empty() const;
    int get_size() const;
    void clear();

    // для вывода информации
    void print() const;            // вывести все элементы
    TNode* get_top() const { return top_; }  // получить указатель на вершину
};

// Для задачи 2 -------------------------------------------

class TQueue { // класс для очереди
private:
    TNode* head;
    TNode* tail;

public:
    // Конструкторы
    TQueue();                     // по умолчанию
    TQueue(const TQueue& other);  // копирования
    ~TQueue();                    // деструктор

    // операции
    void enqueue(int value);       // добавить элемент в конец
    int dequeue();                 // удалить элемент из начала
    int first() const;             // посмотреть первый элемент
    int last() const;              // посмотреть последний элемент
    bool is_empty() const;
    int get_size() const;
    void clear();

    // вывод информации
    void print() const;
    TNode* get_head() const { return head; }
    TNode* get_tail() const { return tail; }
};

// Для задачи 3,4 -------------------------------------------

class TList { // класс для списка
private:
    TNode* head;

public:
    // Конструкторы
    TList();                     // по умолчанию
    TList(const TList& other);   // копирования
    ~TList();                    // деструктор

    // операции
    void insert_at_end(int value);
    void insert_at_beginning(int value);
    void print() const;
    void clear();
    int get_size() const;

    // Методы задания 3
    TNode* find_first_multiple_of(int divisor) const;

    // Методы задания 4
    void insert_after_every_fourth(int value);
    TNode* get_last() const;
    TNode* get_head() const { return head; }
};

// Функции заданий -----------------------------------------

void task_dynamic13();
void task_dynamic14();
void task_listwork11();
void task_listwork24();

#endif