#include "head.h"
#include "string_input.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream> // поток строк
#include <ctime>

// задача 1 (String51)

string String51(string& input) {
    vector<string> words; // создание пустого вектора
    stringstream ss(input); // создание потока строк
    string word;

    while (ss >> word) { // чтение из потока ss слово до пробела
        words.push_back(word);
    }

    int n = words.size();

    for (int i=0; i < n-1; i++) {
        for (int j=0; j < n-i-1; j++) {
            if (words[j] > words[j+1]) { // для строк - сравнение по алфавиту
                string temp = words[j];
                words[j] = words[j+1];
                words[j+1] = temp;
            }
        }
    }

    string result;

    for (int i = 0; i < words.size(); i++) {
        if (i > 0) {
            result += " ";
        }
        result += words[i];
    }

    return result;
}

// вызов функции задачи 1

void task1() {
    cout << "Задача 1: Сортировка русских слов (String51)" << endl;
    string input = input_choice(1);

    string result = String51(input);

    cout << "Результаты:" << endl;
    cout << "Исходная строка: " << input << endl;
    cout << endl;
    cout << "Отсортированная: " << result << endl;
}

// Входные данные String51
// АННА БОРИС  ВАСИЛИЙ   ГАЛИНА  ДМИТРИЙ ЕЛЕНА
// КОТ СОБАКА  ЛОШАДЬ   КОРОВА ОВЦА КОЗА   ПОРОСЕНОК
// ЯБЛОКО  ГРУША АПЕЛЬСИН БАНАНВИНОГРАД  АБРИКОС КИВИ МАНДАРИН

// задача 2 (Str14)

void Str14(string& ftp, string& login, string& password, string& address) {
    login.clear();
    password.clear();
    address.clear();

    if (ftp.find("ftp://") != 0) {
        cout << "Ошибка: строка должна начинаться с 'ftp://'\n";
        return;
    }

    size_t pos = 6; // беззнаковый тип для размеров
    size_t search_login = ftp.find(':', pos); // ищем двоеточие после позиции 6
    if (search_login == string::npos) { //значение "не найдено"
        cout << "Ошибка: не найден логин" << endl;
        return;
    }

    login = ftp.substr(pos, search_login - pos); //вырезание строки (начало, длина)

    pos = search_login + 1;
    size_t search_pass = ftp.rfind('@'); // последнее вхождение символа
    if (search_pass == string::npos) {
        cout << "Ошибка: не найден пароль или адрес сервера\n";
        return;
    }
    password = ftp.substr(pos, search_pass - pos);

    address = ftp.substr(search_pass + 1);
}

// вызов функции задачи 2

void task2() {
    cout << "Задача 2: FTP-строка (Str14)" << endl;
    cout << "Формат: ftp://логин:пароль@адрес-сервера" << endl;

    string input = input_choice(2);

    string login, password, address;
    Str14(input, login, password, address);

    cout << "Результат:" << endl;
    cout << "Логин: " << login << endl;
    cout << "Пароль: " << password << endl;
    cout << "Адрес сервера: " << address;
}

// Входные данные Str14
// ftp://admin:qwerty123@192.168.1.1
// ftp://test:testpass@ftp.server.com:21
// ftp://admin:P@ssw0rd!123@secure-server.com

// задача 3 (Str24)

string Str24_encrypt(string& input, unsigned char gamma) {
    string result = input;
    for (int i = 0; i < result.length(); i++) {
        result[i] = result[i] ^ gamma;  // XOR операция (или, но не оба одновременно)
    }
    return result;
}

string Str24_decrypt(string& input, unsigned char gamma) {
    return Str24_encrypt(input, gamma); // Свойство XOR: (A XOR B) XOR B = A
}

// вызов функции задачи 3

void task3() {
    cout << "Задача 3: Метод шифрации Наложение гаммы (Str24)" << endl;
    cout << "Формула: новый код = старый код XOR гамма" << endl;
    cout << "Гамма: целое число от 127 до 255" << endl;
    cout << endl;
    cout << "Ввод строки для шифрования" << endl;
    string input = input_choice(3);

    int gamma;
    cout << "Введите гамму (127-255): ";
    cin >> gamma;
    cin.ignore(1000, '\n');

    while (gamma < 127 || gamma > 255) {
        cout << "Ошибка: гамма должна быть в диапазоне 127-255" << endl;
        cout << "Введите гамму (127-255): ";
        cin >> gamma;
    }
    string encrypted = Str24_encrypt(input, gamma);

    string decrypted = Str24_decrypt(encrypted, gamma);

    cout << "Результаты: " << endl;
    cout << "Исходная строка: " << input << endl;
    cout << "Гамма: " << gamma << endl;
    cout << endl;

    cout << "Зашифрованная строка: " << endl;
    cout << encrypted << endl;

    cout << "Дешифрованная строка: " << decrypted << endl;
}

// Входные данные Str24
// Hello, World
// gamma encrypt
// university

// задача 4 (Str43)

void Str43(string& input, char& symbol, int& cnt) {
    symbol = '\0'; // нулевой символ ("не найден")
    cnt = 0;

    if (input.empty()) return;

    // массив для подсчета (только для печатаемых символов)
    const int size = 256;  // Достаточно для ASCII
    int freq[size] = {0};

    // подсчет частот
    for (int i = 0; i < input.length(); i++) {
        char c = input[i];
        if (c >= 0 && c < size) {
            freq[c]++;
        }
    }

    // нахождение максимальной частоты
    int max_freq = 0;
    for (int i = 0; i < size; i++) {
        if (freq[i] > max_freq) {
            max_freq = freq[i];
        }
    }

    // нахождение первого символа с максимальной частотой
    if (max_freq > 0) {
        for (int i = 0; i < input.length(); i++) {
            char c = input[i];
            if (c >= 0 && c < size && freq[c] == max_freq) {
                symbol = c;
                cnt = max_freq;
                return;
            }
        }
    }
}

// вызов функции задачи 4

void task4() {
    cout << "Задача 4: Самый частый символ (Str43)" << endl;
    string input = input_choice(4);

    if (input.empty()) {
        cout << "Строка пуста!\n" << endl;
        return;
    }

    char symbol;
    int cnt;

    Str43(input, symbol, cnt);

    cout << "Результат:\n";
    cout << "Строка: \"" << input << "\"\n";
    cout << "Самый частый символ: '";

    if (symbol == ' ') {
        cout << "пробел";
    }
    else {
        cout << symbol;
    }

    cout << "'\n";
    cout << "Количество: " << cnt;
}

// задача 5 (Str26)

bool is_binary(string& bin_stroke) {
    if (bin_stroke.empty()) {
        return false;
    }

    for (int i = 0; i < bin_stroke.length(); i++) {
        char c = bin_stroke[i];
        if (c != '0' && c != '1') {
            return false;
        }
    }

    return true;
}

int Str26_to_dec(string& bin_stroke) {
    int dec = 0;
    int degree = 1;

    for (int i = bin_stroke.length() - 1; i >= 0; i--) {
        if (bin_stroke[i] == '1') {
            dec += degree;
        }
        degree *= 2;
    }

    return dec;
}

// вызов функции задачи 5

void task5() {
    cout << "Задача 5: Правильность ввода двоичного (перевод в 10 сс) числа (Str26)" << endl;

    string bin_stroke;
    bool valid_input = false;

    do {
        bin_stroke = input_choice(5);

        if (is_binary(bin_stroke)) {
            valid_input = true;
        }

        else {
            cout << "Результат: false" << endl;
            cout << "Причина: в двоичной сс могут содержаться только цифры 0 и 1.\n\n";
        }

    } while (!valid_input);

    int dec = Str26_to_dec(bin_stroke);

    cout << "Результат:" << endl;
    cout << "Двоичное число: " << bin_stroke << endl;
    cout << "Перевод в десятичное: " << dec << endl;
}

// задача 6 (2)

string word_shuffle(string& word) {
    string result = word;
    int length = word.length();

    if (length <= 1) {
        return result;
    }

    for (int i = 0; i < length; i++) {
        int rand_pos = rand() % length;

        char temp = result[i];
        result[i] = result[rand_pos];
        result[rand_pos] = temp;
    }

    return result;
}

// вызов функции задачи 6

void task6() {
    cout << "Задача 6: Перестановка букв в слове" << endl;
    string word = input_choice(6);

    string original = word;
    int shuffles = 0;

    cout << "Перестановка букв в слове:" << word << " (исходное)" << endl;
    srand(time(0));

    do {
        word = word_shuffle(word);
        cout << word << endl;
        shuffles++;

    } while (word != original);

    cout << "Кол-во попыток: " << shuffles;
}

// функция меню
void main_menu() {
    cout << "\n\n Меню выбора задачи" << endl;
    cout << endl;
    cout << "1. String51 - Сортировка русских слов" << endl;
    cout << "2. Str14 - FTP-строка" << endl;
    cout << "3. Str24 - Шифрование наложением гаммы" << endl;
    cout << "4. Str43 - Самый частый символ" << endl;
    cout << "5. Str26 - Правильность ввода двоичного числа" << endl;
    cout << "6. Задача 6.2 - Перестановка букв слова" << endl;
    cout << "7. Выход из программы." << endl;
    cout << endl;
    cout << "Ваш выбор (1-7): ";
}