#include "string_input.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

string console() {
    cout << "Введите строку: ";
    string input;
    getline(cin, input);
    return input;
}

string file(const string& filename) {
    ifstream file(filename);
    string input;

    if (!file.is_open()) {
        cout << "Ошибка: не удалось открыть файл '" << filename << "'\n";
        return "";
    }

    getline(file, input);
    file.close();

    cout << "Прочитано из файла: " << input << "\n";
    cout << endl;
    return input;
}

string random(int task_number) {
    static bool seeded = false;

    if (!seeded) {
        srand(time(0));
        seeded = true;
    }

    vector<string> options;

    switch (task_number) {
        case 1: // для String51
            options = {
                "КОТ СОБАКА ЛОШАДЬ КОРОВА ОВЦА КОЗА",
                "ЯБЛОКО ГРУША АПЕЛЬСИН БАНАН ВИНОГРАД",
                "МОСКВА ПАРИЖ ЛОНДОН БЕРЛИН ТОКИО ПЕКИН",
                "ЯНВАРЬ ФЕВРАЛЬ МАРТ АПРЕЛЬ МАЙ ИЮНЬ",
                "ПОНЕДЕЛЬНИК ВТОРНИК СРЕДА ЧЕТВЕРГ ПЯТНИЦА"
            };
            break;

        case 2: // для Str14
            options = {
                "ftp://admin:qwerty123@192.168.1.1",
                "ftp://user:password@ftp.server.com",
                "ftp://test:test123@localhost:21",
                "ftp://anonymous:anonymous@ftp.gnu.org",
                "ftp://root:admin123@secure-server.net"
            };
            break;

        case 3: // для Str24
            options = {
                "Hello World! Programming in C++",
                "Secret message for encryption test",
                "input for XOR encryption",
                "The quick brown fox jumps over the lazy dog",
                "Строка, содержащая русские и английские символы"
            };
            break;

        case 4: // для Str43
            options = {
                "aaaa bbb cc d eeeee f",
                "    cpp     python   ",
                "mississippi river",
                "abracadabra is a magic word",
                "11223344556677889900"
            };
            break;

        case 5: // для Str26
            options = {
                "101010101055",
                "1111000011110000",
                "1001100110011001",
                "10101111010178",
                "1100110011001100"
            };
            break;

        case 6: // Задача 6
            options = {
                "program",
                "computer",
                "algorithm",
                "univer",
                "encode"
            };
            break;
    }

    int index = rand() % options.size();
    return options[index];
}

string input_choice(int task_number) {
    cout << "\nВыберите способ ввода строки:\n";
    cout << "1. Ввести с клавиатуры\n";
    cout << "2. Загрузить из файла (input_str.txt)\n";
    cout << "3. Сгенерировать случайную строку\n";
    cout << "Ваш выбор: ";

    int choice;
    cin >> choice;
    cin.ignore(1000, '\n');
    string input;

    switch (choice) {
        case 1:
            input = console();
            break;
        case 2:
            input = file();
            break;
        case 3:
            input = random(task_number);
            cout << "Сгенерированная строка: " << input << endl;
            cout << endl;
            break;
        default:
            cout << "Неверный выбор, используется ввод с клавиатуры\n";
            input = console();
            break;
    }

    if (input.empty()) {
        cout << "Строка пуста, используется ввод с клавиатуры\n";
        input = console();
    }

    return input;
}