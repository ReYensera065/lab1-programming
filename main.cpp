// #include <iostream>
// #include <string>
// int main() {
// // Вывод приветствия
// std::cout << "Hello, World!" << std::endl;
// // Вывод имени студента
// std::string name = "Иван Иванов";
// std::cout << "Студент: " << name << std::endl;
// // Вывод даты
// std::cout << "Дата: 2026-09-10" << std::endl;
// return 0;
// }

#include <iostream>
// Функция вычисления квадрата числа
auto square(int x) -> int { return x * x; }
int main() {
    // Униформ-инициализация
    auto number{7};
    // Вызов функции
    auto result = square(number);
    std::cout << "Число: " << number << std::endl;
    std::cout << "Квадрат: " << result << std::endl;
    return 0;
}
