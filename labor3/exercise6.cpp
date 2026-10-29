//конвертер температур, который: Предлагает пользователю выбор: из °C в °F или из °F в °C Запрашивает температуру Выводит результат с форматированием


#include <iostream>
#include <iomanip> // библеотека для форматирование строк;
#include <windows.h>

int main () {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    std::cout<<"Конвертер температур\n";
    std::cout<<"1. Из °C в °F\n";
    std::cout<<"2. Из °F в °C\n";

    int choice;
    std::cout << "Ваш выбор (1/2): ";
    std::cin >> choice;

    std::cout << std::fixed << std::setprecision(1); // точность до второго знака

    if (choice == 1){
        double celsius;
        std::cout<<"Введите темпиратуру в °C: ";
        std::cin>>celsius;
        double fahrenheit =  celsius * 0.9/5+32;
        std::cout<<celsius<<"°C = "<<fahrenheit << " °F\n";
    } else if (choice==2){
        double fahrenheit;
        std::cout << "Введите температуру в  °F: ";
        std::cin >> fahrenheit;
        double celsius = (fahrenheit-32)*5.0/9.0;
        std::cout<<fahrenheit<< "°F = "<< celsius<<"°C\n";

    } else {
        std::cout<<"Некоректный выбор\n";
    }
    std::cin.get();
    return 0;

}
