/**
 * Программа для работы с квадратным многочленом ax^2 + bx + c.
 *
 * Команды:
 *   B - вывести имя студента
 *   s - найти корни многочлена
 *   x - проверить, високосный ли год
 */

#include <iostream>
#include <cmath>

const char* STUDENT_NAME = "Allayarov Timur";

const double EPS = 1e-9;

// Проверка года на високосность (григорианский календарь)
bool VSyear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int main()
{
    double a, b, c;
    char cmd;

    std::cout << "Введите a, b, c: ";
    std::cin >> a >> b >> c;

    std::cout << "Введите команду (B/s/x): ";
    std::cin >> cmd;

    if (cmd == 'B')
    {
        std::cout << STUDENT_NAME << std::endl;
    }
    else if (cmd == 's')
    {
        if (std::abs(a) < EPS && std::abs(b) < EPS && std::abs(c) < EPS)
        {
            std::cout << "x - любое действительное число" << std::endl;
        }
        // a = b = 0, c != 0 — решений нет
        else if (std::abs(a) < EPS && std::abs(b) < EPS)
        {
            std::cout << "Корней нет" << std::endl;
        }
        else if (std::abs(a) < EPS)
        {
            std::cout << "x = " << -c / b << std::endl;
        }
        else
        {
            double d = b * b - 4 * a * c;

            if (d > EPS)
            {
                std::cout << "x1 = " << (-b + std::sqrt(d)) / (2 * a)
                          << ", x2 = " << (-b - std::sqrt(d)) / (2 * a) << std::endl;
            }
            else if (std::abs(d) < EPS)
            {
                std::cout << "x = " << -b / (2 * a) << std::endl;
            }
            else
            {
                std::cout << "Действительных корней нет" << std::endl;
            }
        }
    }
    else if (cmd == 'x')
    {
        int year;
        std::cout << "Введите год: ";
        std::cin >> year;

        if (VSyear(year))
            std::cout << year << " - високосный" << std::endl;
        else
            std::cout << year << " - не високосный" << std::endl;
    }
    else
    {
        std::cout << "Неизвестная команда" << std::endl;
    }

    return 0;
}
