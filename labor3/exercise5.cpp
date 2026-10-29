// запрашивает три числа и выводит: Среднее арифметическое Минимальное значение Максимальное значение

#include <iostream>
#include <iomanip>
#include <algorithm> // позволяет работать с масивами и контейнерами
#include <windows.h>

int main () {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    double a, b ,c;
    std::cout <<"Ввидите первое число: ";
    std::cin >> a;
    std::cout <<"Ввидите второе число: ";
    std::cin >> b;
    std::cout <<"Ввидите третье число: ";
    std::cin >> c;


    double average = (a+b+c)/3.0;
    double minimum = std::min({a,b,c});
    double maximum = std::max({a,b,c});

    std::cout << std::fixed<<std::setprecision(2);  // точность до второго знака
    std::cout << "Среднее врифметическое: "<<average<<"\n";
    std::cout << "Минимум: " << minimum << "\n";
    std::cout << "Максимум: " << maximum << "\n";


    std::cin.get();
    return 0;

}
