#ifndef CPP_HEAD_H
#define CPP_HEAD_H

#include <iostream>
#include <string>
#include <list>
#include <random>
#include <fstream>
#include <algorithm>
#include <vector>

void menu();

// вспомогательные функции

int get_size();
void clear_input();
int get_positive();
int get_not_neg();
int safe_input_int();
int get_data_choice();
void print_list(const std::list<int>& list);
void print_vector(const std::vector<double>& vector);
bool is_even(const std::list<int>& list);

// заполнение списка

void request_fill(std::list<int> &list, bool need_positive = false);
void fill_list_console(std::list<int>& list, bool need_positive);
void fill_list_random(std::list<int>& list, int size);
void fill_list_file(std::list<int>& list, const std::string& filename, bool need_positive);

// функциональные объекты

// задание 1
struct IsNegative {
    bool operator()(int x) const {
        return x < 0;
    }
};

struct IsPositive {
    bool operator()(int x) const {
        return x > 0;
    }
};

// задание 2
struct IsNegativeReplace {
    bool operator()(int x) const {
        return x < 0;
    }
};

// задание 3
struct IsEven {
    bool operator()(int x) const {
        return x % 2 == 0;
    }
};

// задание 4
struct Average {
    double operator()(int a, int b) const {
        return (static_cast<double>(a) + static_cast<double>(b)) / 2.0;
    }
};

// задания

void task1();
void task2();
void task3();
void task4();

#endif