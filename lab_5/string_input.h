#ifndef STRING_INPUT_H
#define STRING_INPUT_H
#include <string>

using namespace std;

string console();
string file(const string& filename = "input_str.txt");
string random(int task_number);
string input_choice(int task_number);

#endif