// #include <iostream>
// #include <fstream>
// #include <vector>
// #include <iomanip>
// #include <algorithm>
// #include "head.h"
//
// struct Artifact {
//     int c; // вес
//     int d; // объем
//     int index;
// };
//
// void BackRec9() {
//     cout << "BackRec9" << endl;
//     cout << endl;
//
//     ifstream input("backrec9_input.txt");
//     if (!input) {
//         cout << "Ошибка открытия файла backrec9_input.txt" << endl;
//         cout << "Создайте файл backrec9_input.txt с данными." << endl;
//         cout << "Формат файла:" << endl;
//         cout << "N B" << endl;
//         cout << "Вес каждого артефакта" << endl;
//         cout << "Объем каждого артефакта" << endl;
//         return;
//     }
//
//     int N, B;
//     input >> N >> B;
//
//     vector<Artifact> artifacts(N);
//
//     for (int i = 0; i < N; i++) {
//         input >> artifacts[i].c;
//         artifacts[i].index = i + 1;
//     }
//
//     for (int i = 0; i < N; i++) {
//         input >> artifacts[i].d;
//     }
//
//     input.close();
//
//     vector<vector<int>> dp(N + 1, vector<int>(B + 1, INT_MIN));
//     vector<vector<bool>> taken(N + 1, vector<bool>(B + 1, false));
//     vector<vector<int>> count(N + 1, vector<int>(B + 1, 0));
//
//     dp[0][0] = 0;
//
//     for (int i = 1; i <= N; i++) {
//         for (int w = 0; w <= B; w++) {
//             dp[i][w] = dp[i-1][w];
//             count[i][w] = count[i-1][w];
//             taken[i][w] = false;
//
//             int prev_w = w - artifacts[i-1].c;
//             if (prev_w >= 0 && dp[i-1][prev_w] != INT_MIN) {
//                 int new_value = w;
//                 int new_count = count[i-1][prev_w] + 1;
//
//                 if (w <= B) {
//                     bool better = false;
//                     if (abs(w - B) < abs(dp[i][w] - B)) {
//                         better = true;
//                     } else if (abs(w - B) == abs(dp[i][w] - B)) {
//                         if (new_count > count[i][w]) {
//                             better = true;
//                         }
//                     }
//
//                     if (better) {
//                         dp[i][w] = new_value;
//                         count[i][w] = new_count;
//                         taken[i][w] = true;
//                     }
//                 }
//             }
//         }
//     }
//
//     // лучший результат
//     int best_weight = 0;
//     int best_count = 0;
//
//     for (int w = 0; w <= B; w++) {
//         if (dp[N][w] != INT_MIN) {
//             if (abs(w - B) < abs(best_weight - B)) {
//                 best_weight = w;
//                 best_count = count[N][w];
//             } else if (abs(w - B) == abs(best_weight - B)) {
//                 if (count[N][w] > best_count) {
//                     best_weight = w;
//                     best_count = count[N][w];
//                 }
//             }
//         }
//     }
//
//     // выбранные артефакты
//     vector<int> selected;
//     int current_weight = best_weight;
//
//     for (int i = N; i > 0; i--) {
//         if (taken[i][current_weight]) {
//             selected.push_back(artifacts[i-1].index);
//             current_weight -= artifacts[i-1].c;
//         }
//     }
//
//     reverse(selected.begin(), selected.end());
//
//     // объем
//     int total_volume = 0;
//     for (int idx : selected) {
//         total_volume += artifacts[idx-1].d;
//     }
//
//     // cout << "Выбранные артефакты (номера): ";
//     // for (int idx : selected) {
//     //     cout << idx << " ";
//     // }
//     // cout << "\n";
//
//     // cout << endl;
//     // cout << "Суммарный вес: " << best_weight << " кг\n";
//     // cout << endl;
//     // cout << "Суммарный объем: " << total_volume << " куб.см\n";
//     // cout << endl;
//     // cout << "Количество артефактов: " << selected.size() << "\n";
//     // cout << endl;
//
//     ofstream output("backrec9_output.txt");
//     output << "Выбранные артефакты: ";
//     for (int idx : selected) {
//         output << idx << " ";
//     }
//     output << "\n";
//     output << "Суммарный вес: " << best_weight << "\n";
//     output << "Суммарный объем: " << total_volume << "\n";
//     output.close();
//
//     cout << "Результат сохранен в backrec9_output.txt\n";
//     cout << endl;
// }
//
// void HomeDyn3() {
//     cout << "HomeDyn3\n";
//     cout << endl;
//
//     ifstream input("homedyn3_input.txt");
//     if (!input) {
//         cout << "Ошибка открытия файла homedyn3_input.txt\n";
//         cout << "Создайте файл homedyn3_input.txt с данными.\n";
//         cout << "Формат файла:\n";
//         cout << "N\n";
//         cout << "Значения ячеек квадратной доски\n";
//         return;
//     }
//
//     int N;
//     input >> N;
//
//     vector<vector<int>> board(N, vector<int>(N));
//
//     for (int i = 0; i < N; i++) {
//         for (int j = 0; j < N; j++) {
//             input >> board[i][j];
//         }
//     }
//     input.close();
//
//     vector<vector<int>> dp(N, vector<int>(N, 0));
//     vector<vector<char>> path(N, vector<char>(N, ' '));
//
//     // стартовая позиция
//     dp[N-1][N-1] = board[N-1][N-1];
//
//     // строка снизу
//     for (int j = N-2; j >= 0; j--) {
//         dp[N-1][j] = dp[N-1][j+1] + board[N-1][j];
//         path[N-1][j] = 'L';
//     }
//
//     // столбец справа
//     for (int i = N-2; i >= 0; i--) {
//         dp[i][N-1] = dp[i+1][N-1] + board[i][N-1];
//         path[i][N-1] = 'U';
//     }
//
//     // остальные клетки
//     for (int i = N-2; i >= 0; i--) {
//         for (int j = N-2; j >= 0; j--) {
//             if (dp[i+1][j] > dp[i][j+1]) {
//                 dp[i][j] = dp[i+1][j] + board[i][j];
//                 path[i][j] = 'U';
//             } else {
//                 dp[i][j] = dp[i][j+1] + board[i][j];
//                 path[i][j] = 'L';
//             }
//         }
//     }
//
//     string result_path = "";
//     int i = 0, j = 0;
//
//     while (!(i == N-1 && j == N-1)) {
//         if (path[i][j] == 'U') {
//             result_path += 'U';
//             i++;
//         }
//         else {
//             result_path += 'L';
//             j++;
//         }
//     }
//
//     reverse(result_path.begin(), result_path.end());
//
//     // cout << "Максимальная сумма: " << dp[0][0] << "\n";
//     // cout << "Путь: " << result_path << "\n";
//
//     ofstream output("homedyn3_output.txt");
//     output << dp[0][0] << "\n";
//     output << result_path << "\n";
//     output.close();
//
//     cout << "Результат сохранен в homedyn3_output.txt\n";
//     cout << endl;
// }
//
// void HomeDyn13() {
//     // cout << "HomeDyn13\n";
//     // cout << endl;
//
//     // ifstream input("homedyn13_input.txt");
//     // if (!input) {
//     //     cout << "Ошибка открытия файла homedyn13_input.txt\n";
//     //     cout << "Создайте файл homedyn13_input.txt с данными.\n";
//     //     cout << "Формат файла: K N\n";
//     //     return;
//     // }
//
//     int K, N;
//     // cout << "Введите число K" << endl;
//     // cin >> K;
//     // cout << "Введите число N" << endl;
//     // cin >> N;
//     // input >> K >> N;
//     // input.close();
//
//     // if (K < 2 || K > 10) {
//     //     cout << "K должно быть в диапазоне [2, 10]\n";
//     //     cout << endl;
//     //     HomeDyn13();
//     // }
//     // if (N < 1 || N >= 20) {
//     //     cout << "N должно быть в диапазоне (1, 20)\n";
//     //     cout << endl;
//     //     HomeDyn13();
//     // }
//     // if (K + N >= 26) {
//     //     cout << "K + N должно быть < 26\n";
//     //     cout << endl;
//     //     HomeDyn13();
//     // }
//
//     bool validInput = false;
//     while (!validInput) {
//         cout << "Введите основание системы счисления K (2 ≤ K ≤ 10): ";
//         cin >> K;
//
//         if (cin.fail()) {
//             cin.clear();
//             cout << "Ошибка: необходимо ввести целое число!\n\n";
//         }
//         else {
//             cout << "Введите количество разрядов N (1 < N < 20): ";
//             cin >> N;
//
//             if (cin.fail()) {
//                 cin.clear();
//                 cout << "Ошибка: необходимо ввести целое число!\n\n";
//             }
//             else {
//                 if (K < 2) {
//                     cout << "Ошибка: K должно быть ≥ 2!\n";
//                     cout << endl;
//                 }
//                 else if (K > 10) {
//                     cout << "Ошибка: K должно быть ≤ 10!\n";
//                     cout << endl;
//                 }
//                 else if (N <= 1) {
//                     cout << "Ошибка: N должно быть > 1!\n";
//                     cout << endl;
//                 }
//                 else if (N >= 20) {
//                     cout << "Ошибка: N должно быть < 20!\n";
//                     cout << endl;
//                 }
//                 else if (K + N >= 26) {
//                     cout << "Ошибка: K + N должно быть < 26!\n";
//                     cout << endl;
//                 }
//                 else {
//                     validInput = true;
//                 }
//             }
//         }
//     }
//
//     vector<vector<double>> dp(N + 1, vector<double>(2, 0));
//
//     dp[1][0] = K - 1;
//     dp[1][1] = 1;
//
//     for (int i = 2; i <= N; i++) {
//         dp[i][0] = (dp[i-1][0] + dp[i-1][1]) * (K - 1);
//         dp[i][1] = dp[i-1][0];
//     }
//
//     double total = dp[N][0] + dp[N][1];
//
//     // cout << "Основание системы счисления K: " << K << "\n";
//     // cout << "Количество разрядов N: " << N << "\n";
//     cout << "Количество " << N << "-разрядных чисел в системе счисления с основанием " << K << "\n";
//     cout << "без двух подряд идущих нулей: ";
//     cout << fixed << setprecision(0) << total << "\n";
//
//     // ofstream output("homedyn13_output.txt");
//     // output << fixed << setprecision(0) << total << "\n";
//     // output.close();
//
//     // cout << "Результат сохранен в homedyn13_output.txt\n";
//     cout << endl;
// }