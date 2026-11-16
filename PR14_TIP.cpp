// // Задание 1
// #include <iostream>
// #include <string>
// using namespace std;

// int main() {
//     string s;
//     getline(cin, s);      // читаем всю строку с пробелами

//     int k = 0;      // счётчик открытых скобок
//     bool ok = true;

//     for (int i = 0; i < s.length(); i++) {
//         if (s[i] == '(') {
//             k = k + 1;
//         } else if (s[i] == ')') {
//             k = k - 1;
//             if (k < 0) {
//                 ok = false;
//                 break;    // лишняя закрывающая — дальше можно не смотреть
//             }
//         }
//     }

//     if (ok == true && k == 0) {
//         cout << "yes";
//     } else {
//         cout << "no";
//     }

//     return 0;
// }

// Задание 2
#include <iostream>
#include <string>
#include <set>
#include <locale>
#include <cwctype>
#include <windows.h>

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    setlocale(LC_ALL, "Russian");

    wstring text;
    wstring word;
    set<wstring> words;

    wcout << L"Введите текст: ";
    getline(wcin, text);

    for (wchar_t c : text) {
        if (iswalpha(c)) {
            word += towlower(c);
        } else {
            if (!word.empty()) {
                words.insert(word);
                word.clear();
            }
        }
    }

    if (!word.empty()) {
        words.insert(word);
    }

    wcout << L"\nУникальные слова:\n";

    for (const auto& w : words) {
        wcout << w << endl;
    }

    wcout << L"\nВсего уникальных слов: "
        << words.size() << endl;

    return 0;
}