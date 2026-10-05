/** Задание 3
 * Аллаяров ЭФБО-07-26
 * Вариант 2: 7a-6(19-a)
 */

#include <iostream>


int main()
{
    double a = 0.0;

    std::cout << "Вычисление значения выражения: 7a - 6(19 - a)" << std::endl;
    std::cout << "Упрощенный вид: 13a - 114" << std::endl;
    std::cout << "Введите значение коэффициента a: ";
    std::cin >> a;

    double result = 13 * a - 114;
    
    std::cout << "Значение выражения при a = " << a
              << " равно: " << result << std::endl;

    return 0;
}
