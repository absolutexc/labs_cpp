#ifndef HEAD_H
#define HEAD_H

#include <string>

using namespace std;

// задача 1 (String51)
string String51(string& input);
void task1();

// задача 2 (Str14)
void Str14(string& ftp, string& login, string& password, string& address);
void task2();

// задача 3 (Str24)
string Str24_encrypt(string& input, unsigned char gamma);
string Str24_decrypt(string& input, unsigned char gamma);
void task3();

// задача 4 (Str43)
void Str43(string& input, char& symbol, int& cnt);
void task4();

// задача 5 (Str26)
bool is_binary(string& bin_stroke);
int Str26_to_dec(string& bin_stroke);
void task5();

// задача 6 (2)
string word_shuffle(string& word);
void task6();

// функция меню
void main_menu();

#endif