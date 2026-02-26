// #include "head.h"
//
// void printMenu() {
//     cout << "Выберите задачу:" << endl;
//     cout << "1. File6." << endl;
//     cout << "2. File39." << endl;
//     cout << "3. File48." << endl;
//     cout << "4. Recur24." << endl;
//     cout << "0. Выход из программы." << endl;
//     cout << endl;
//     cout << "Выберите задание:" << endl;
// }
//
// void createFile(string& filename) {
//     ofstream file(filename, ios::binary);
//     if (!file) {
//         cout << "Ошибка создания файла " << filename << endl;
//         return;
//     }
//
//     int n;
//
//     while (true) {
//         cout << "Сколько чисел хотите записать в файл? " << endl;
//         cin >> n;
//
//         if (cin.fail()) {
//             cin.clear();
//             cin.ignore(10000, '\n');
//             cout << "Ошибка! Введите целое число." << endl;
//         }
//         else if (n <= 0) {
//             cout << "Количество чисел должно быть положительным! Попробуйте снова." << endl;
//         }
//         else {
//             break;
//         }
//     }
//
//     cout << "Введите " << n << " неотрицательных целых чисел:" << endl;
//
//     int count = 0;
//     while (count < n) {
//         int num;
//         cout << "Число " << (count + 1) << ": ";
//         cin >> num;
//
//         if (cin.fail()) {
//             cin.clear();
//             cin.ignore(10000, '\n');
//             cout << "Ошибка! Введите целое число." << endl;
//         }
//         else if (num < 0) {
//             cout << "Число должно быть неотрицательным! Попробуйте снова." << endl;
//         }
//         else {
//             file.write((char*)&num, sizeof(num));
//             count++;
//         }
//     }
//
//     file.close();
//     cout << "Файл " << filename << " успешно создан и заполнен" << endl;
// }
//
// void readFile(string& filename) {
//     ifstream file(filename, ios::binary);
//     if (!file) {
//         cout << "Ошибка открытия файла " << filename << "!" << endl;
//         return;
//     }
//
//     cout << "Содержимое файла " << filename << ":" << endl;
//
//     int num;
//     int count = 0;
//     while (file.read((char*)&num, sizeof(num))) {
//         cout << num << " ";
//         count++;
//     }
//
//     if (count == 0) {
//         cout << "Файл пуст";
//     }
//     cout << "\nВсего чисел: " << count << endl;
//
//     file.close();
// }
//
// void File6() {
//     string filename;
//     int k;
//
//     cout << "Задача File6" << endl;
//     cout << "Введите имя файла: " << endl;
//     cin >> filename;
//
//     createFile(filename);
//
//     cout << endl;
//     readFile(filename);
//
//     cout << endl;
//
//     while (true) {
//         cout << "Введите номер элемента k (нумерация с 1): ";
//         cin >> k;
//
//         if (cin.fail()) {
//             cin.clear();
//             cin.ignore(10000, '\n');
//             cout << "Ошибка! Введите целое число." << endl;
//         }
//         else if (k < 1) {
//             cout << "Номер элемента должен быть >= 1!" << endl;
//         }
//         else {
//             break;
//         }
//     }
//
//     ifstream file(filename, ios::binary);
//     if (!file) {
//         cout << "Ошибка открытия файла!" << endl;
//         return;
//     }
//
//     int value;
//     file.seekg((k - 1) * sizeof(int), ios::beg);
//
//     file.read((char *)&value, sizeof(value));
//
//     if (file) {
//         cout << "Ответ: " << value << endl;
//     }
//     else {
//         cout << "Ответ: -1" << endl;
//     }
//
//     file.close();
//     cout << endl;
// }
//
// void File39() {
//     string filename;
//
//     cout << endl;
//     cout << "Задача File39" << endl;
//     cout << "Введите имя файла: ";
//     cin >> filename;
//
//     createFile(filename);
//
//     cout << endl;
//     cout << "Исходный файл:" << endl;
//     readFile(filename);
//
//     ifstream inputFile(filename, ios::binary);
//     if (!inputFile) {
//         cout << "Ошибка открытия файла!" << endl;
//         return;
//     }
//
//     string tempFilename = "temporary_" + filename;
//     ofstream tempFile(tempFilename, ios::binary);
//     if (!tempFile) {
//         cout << "Ошибка создания временного файла!" << endl;
//         inputFile.close();
//         return;
//     }
//
//     int num;
//
//     while (inputFile.read((char*)&num, sizeof(num))) {
//         tempFile.write((char*)&num, sizeof(num));
//
//         if (num >= 5 && num <= 10) {
//             tempFile.write((char*)&num, sizeof(num));
//         }
//     }
//
//     inputFile.close();
//     tempFile.close();
//
//     remove(filename.c_str());
//     rename(tempFilename.c_str(), filename.c_str());
//
//     cout << endl;
//     cout << "Файл после дублирования чисел из диапазона 5-10:" << endl;
//     readFile(filename);
//     cout << endl;
// }
//
// void File48() {
//     string filenameA, filenameB, filenameC, filenameD;
//     bool filesValid = false;
//
//     cout << "Задача File48" << endl;
//
//     cout << "Введите имя файла SA: ";
//     cin >> filenameA;
//     cout << "Введите имя файла SB: ";
//     cin >> filenameB;
//     cout << "Введите имя файла SC: ";
//     cin >> filenameC;
//     cout << "Введите имя результирующего файла SD: ";
//     cin >> filenameD;
//
//     do {
//         cout << endl;
//         cout << "Заполнение первого файла SA" << endl;
//         createFile(filenameA);
//
//         cout << endl;
//         cout << "Заполнение второго файла SB" << endl;
//         createFile(filenameB);
//
//         cout << endl;
//         cout << "Заполнение третьего файла SC" << endl;
//         createFile(filenameC);
//
//         cout << endl;
//         cout << "Содержимое исходных файлов" << endl;
//         readFile(filenameA);
//         readFile(filenameB);
//         readFile(filenameC);
//
//         ifstream fileA(filenameA, ios::binary);
//         ifstream fileB(filenameB, ios::binary);
//         ifstream fileC(filenameC, ios::binary);
//
//         if (!fileA || !fileB || !fileC) {
//             cout << "Ошибка открытия исходных файлов!" << endl;
//             return;
//         }
//
//         fileA.seekg(0, ios::end);
//         fileB.seekg(0, ios::end);
//         fileC.seekg(0, ios::end);
//
//         int sizeA = fileA.tellg() / sizeof(int);
//         int sizeB = fileB.tellg() / sizeof(int);
//         int sizeC = fileC.tellg() / sizeof(int);
//
//         if (sizeA != sizeB || sizeB != sizeC) {
//             cout << endl;
//             cout << "Ошибка! Файлы имеют разный размер:" << endl;
//             cout << filenameA << ": " << sizeA << " элемента(-ов)" << endl;
//             cout << filenameB << ": " << sizeB << " элемента(-ов)" << endl;
//             cout << filenameC << ": " << sizeC << " элемента(-ов)" << endl;
//             cout << "Повторите заполнение файлов." << endl;
//
//             fileA.close();
//             fileB.close();
//             fileC.close();
//
//             filesValid = false;
//         }
//         else {
//             filesValid = true;
//
//             fileA.seekg(0, ios::beg);
//             fileB.seekg(0, ios::beg);
//             fileC.seekg(0, ios::beg);
//
//             ofstream fileD(filenameD, ios::binary);
//             if (!fileD) {
//                 cout << "Ошибка создания файла " << filenameD << "!" << endl;
//                 return;
//             }
//
//             int numA, numB, numC;
//             int totalElements = sizeA * 3;
//
//             for (int i = 0; i < sizeA; i++) {
//                 fileA.read((char*)&numA, sizeof(int));
//                 fileB.read((char*)&numB, sizeof(int));
//                 fileC.read((char*)&numC, sizeof(int));
//
//                 fileD.write((char*)&numA, sizeof(int));
//                 fileD.write((char*)&numB, sizeof(int));
//                 fileD.write((char*)&numC, sizeof(int));
//             }
//
//             fileA.close();
//             fileB.close();
//             fileC.close();
//             fileD.close();
//
//             cout << endl;
//             cout << "Результирующий файл SD" << endl;
//             cout << "Создан файл " << filenameD << " с элементами:" << endl;
//             readFile(filenameD);
//
//             cout << endl;
//             cout << "Всего элементов в результирующем файле: " << totalElements << endl;
//             cout << endl;
//         }
//     } while (!filesValid);
// }
//
// bool Expression(const string& s, int& pos) {
//     if (pos >= s.length()) return false;
//
//     char c = s[pos];
//
//     if (c == 'T') {
//         pos++;
//         return true;
//     }
//
//     if (c == 'F') {
//         pos++;
//         return false;
//     }
//
//     // обработка And
//     if (s.substr(pos, 3) == "And") {
//         pos += 3;
//         return AndStart(s, pos);
//     }
//
//     // обработка Or
//     if (s.substr(pos, 2) == "Or") {
//         pos += 2;
//         return OrStart(s, pos);
//     }
//
//     // обработка Not
//     if (s.substr(pos, 3) == "Not") {
//         pos += 3;
//         return Not(s, pos);
//     }
//
//     return false;
// }
//
// // And(<параметры>)
// bool AndEnd(const string& s, int& pos, bool currentRes) {
//     if (s[pos] == ')') {
//         pos++;
//         return currentRes;
//     }
//     if (s[pos] == ',') {
//         pos++;
//         bool next = Expression(s, pos);
//         return AndEnd(s, pos, currentRes && next);
//     }
//     return false;
// }
//
// bool AndStart(const string& s, int& pos) {
//     if (s[pos] != '(') {
//         return false;
//     }
//     pos++;
//
//     bool first = Expression(s, pos);
//     return AndEnd(s, pos, first);
// }
//
// // Or(<параметры>)
// bool OrEnd(const string& s, int& pos, bool currentRes) {
//     if (s[pos] == ')') {
//         pos++;
//         return currentRes;
//     }
//     if (s[pos] == ',') {
//         pos++;
//         bool next = Expression(s, pos);
//         return OrEnd(s, pos, currentRes || next);
//     }
//     return false;
// }
//
// bool OrStart(const string& s, int& pos) {
//     if (s[pos] != '(') return false;
//     pos++;
//
//     bool first = Expression(s, pos);
//     return OrEnd(s, pos, first);
// }
//
// // Not(<выражение>)
// bool Not(const string& s, int& pos) {
//     if (s[pos] != '(') {
//         return false;
//     }
//     pos++;
//
//     bool result = Expression(s, pos);
//
//     if (s[pos] == ')') {
//         pos++;
//         return !result;
//     }
//
//     return false;
// }
//
// // And(T,F) ; Or(T,F) ; Not(T) ; And(Or(T,F),And(T,T)) ; Or(And(T,F),Not(F))
// void Recur24() {
//     string expression;
//
//     cout << "Задача Recur24" << endl;
//     cout << "Форма записи:" << endl;
//     cout << "  T - True" << endl;
//     cout << "  F - False" << endl;
//     cout << "  And (параметры) - И" << endl;
//     cout << "  Or (параметры) - ИЛИ" << endl;
//     cout << "  Not (выражение) - НЕ" << endl;
//     cout << endl;
//     cout << "Введите выражение: ";
//
//     cin >> expression;
//
//     int pos = 0;
//     bool result = Expression(expression, pos);
//
//     if (pos < expression.length()) {
//         cout << "Ошибка: после выражения остались символы: " << expression.substr(pos) << endl;
//     }
//     else {
//         cout << "Ответ: " << (result ? "True" : "False") << endl;
//     }
//     cout << endl;
// }