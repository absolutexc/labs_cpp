#ifndef CPP_HEAD_H
#define CPP_HEAD_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <fstream>
#include <random>
#include <map>

void menu();

void clear_input();
int get_not_neg();
int get_positive();

// заполнение векторов
std::vector<int> fill_console();
std::vector<int> fill_random();
std::vector<int> fill_file();

// заполнение строк векторов для 2
std::vector<std::string> fill_string_console();
std::vector<std::string> fill_string_file();

// заполнение векторов V1...VN
std::vector<std::vector<int>> fill_vectors(int N, int v0_size);

void task1();
void task2();
void task3();

#endif