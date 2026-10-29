//Запрашивает у пользователя целое число, дробное число и строку и выводит тип каждого значения и само значение

#include <iostream>
#include <string>
#include <typeinfo>
#include <windows.h>

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    int integer;
    double decimal;
    std::string text;

    std::cout << "Введите целое число: ";
    std::cin >> integer;

    std::cout << "Введите дробное число: ";
    std::cin >> decimal;

    std::cin.ignore();

    std::cout << "Введите строку: ";
    std::getline(std::cin,text);

    std::cout << "Значени: " << integer << ", тип: "<< typeid(integer).name()<<"\n";

    std::cout << "Значени: " << decimal << ", тип: "<< typeid(decimal).name()<<"\n";

    std::cout << "Значени: " << text << ", тип: "<< typeid(text).name()<<"\n";
    std::cin.get();

return 0;

}
