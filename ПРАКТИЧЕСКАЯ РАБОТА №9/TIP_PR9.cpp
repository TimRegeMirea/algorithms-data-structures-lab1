// // Задание №1
// 1 способ
//
// #include <iostream>
// #include <fstream>
// #include <string>
// #include <cctype> // Для функции tolower
//
// using namespace std;
//
// int main() {
//     // Открываем файл для чтения
//     ifstream inputFile("input.txt");
//
//     // Проверяем, удалось ли открыть файл
//     if (!inputFile.is_open()) {
//         cerr << "Ошибка: не удалось открыть файл input.txt" << endl;
//         return 1;
//     }
//
//     // Открываем файл для записи
//     ofstream outputFile("output.txt");
//
//     // Читаем файл посимвольно
//     char c;
//     while (inputFile.get(c)) {
//         // Приводим символ к нижнему регистру для проверки
//         char lowerC = tolower(c);
//
//         // Проверяем, является ли символ одной из букв: u, s, e, r, a, g, m, n, t
//         // (буквы из фразы "user agreement")
//         if (lowerC == 'u' || lowerC == 's' || lowerC == 'e' ||
//             lowerC == 'r' || lowerC == 'a' || lowerC == 'g' ||
//             lowerC == 'm' || lowerC == 'n' || lowerC == 't') {
//             // Если символ совпал, пропускаем его (ничего не пишем в выходной файл)
//             continue;
//             }
//
//         // Если символ не совпал, записываем его в выходной файл
//         outputFile << c;
//     }
//
//     // Закрываем файлы
//     inputFile.close();
//     outputFile.close();
//
//     return 0;
// }
//
// 2 способ
//
// #include <iostream>
// #include <fstream>
// #include <string>
// #include <cctype>
//
// using namespace std;
//
// int main() {
//     ifstream fin("input.txt");
//     ofstream fout("output.txt");
//
//     if (!fin.is_open()) {
//         cout << "Файл не найден!" << endl;
//         return 0;
//     }
//
//     // Строка-шаблон: буквы, которые нужно удалить
//     // (все буквы из фразы "user agreement")
//     string forbidden = "useragreement";
//
//     char c;
//     // Читаем файл посимвольно
//     while (fin.get(c)) {
//         // Переводим символ в нижний регистр, чтобы 'U' и 'u' считались одинаково
//         char lowerC = tolower(c);
//
//         // Ищем этот символ в нашей строке-шаблоне
//         // Если find вернул npos — значит, символа там нет, можно писать
//         if (forbidden.find(lowerC) == string::npos) {
//             fout << c;
//         }
//         // Иначе (если нашли) — просто ничего не делаем, символ удаляется
//     }
//
//     fin.close();
//     fout.close();
//     return 0;
// }
// Задание №2
//
// #include <iostream>
// #include <fstream>
// #include <string>
//
// int main() {
//     std::ifstream in1("input1.txt");
//     std::ifstream in2("input2.txt");
//     std::ofstream out("output.txt");
//
//     if (!in1.is_open() || !in2.is_open() || !out.is_open()) {
//         std::cerr << "Не удалось открыть input1.txt / input2.txt / output.txt\n";
//         return 1;
//     }
//
//     std::string X, Y;
//     std::getline(in1, X);
//     std::getline(in2, Y);
//
//     // Ищем Y внутри X
//     if (X.find(Y) != std::string::npos)
//         out << "yes";
//     else
//         out << "no";
//
//     return 0;
// }

// Задание №3
//
// #include <iostream>
// #include <fstream>
// #include <string>
// #include <cctype>
// #include <algorithm>
//
// // Число из строки цифр -> двоичная строка (через деление столбиком)
// std::string bin(const std::string& s) {
//     std::string n = s, r;
//     while (n != "0") {
//         int c = 0;
//         std::string q;
//         for (char d : n) {
//             int cur = c * 10 + (d - '0');
//             q += char('0' + cur / 2);
//             c = cur % 2;
//         }
//         r += char('0' + c);
//         n = q.substr(q.find_first_not_of('0') == std::string::npos
//                      ? q.size() - 1 : q.find_first_not_of('0'));
//     }
//     if (r.empty()) r = "0";
//     std::reverse(r.begin(), r.end());
//     return r;
// }
//
// int main() {
//     std::ifstream in("input3.txt");
//     std::ofstream out("output.txt");
//     std::string line, res, num;
//     std::getline(in, line);
//
//     for (char c : line + " ") {
//         if (std::isdigit((unsigned char)c)) num += c;
//         else {
//             if (!num.empty()) { res += bin(num); num.clear(); }
//             if (c != ' ') res += c;
//         }
//     }
//     out << res;
// }