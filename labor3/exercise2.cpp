// запрашивает два числа и выводит:  Сумму, разность, произведение Результат целочисленного деления  Остаток от деления Возведение первого числа в степень второго

#include <iostream>
#include <iomanip>
#include <cmath> // библеотека добавляет математические функции
#include <windows.h> // библеотека для коректного отображения кирилицы в консоле

int main(){
    SetConsoleCP(65001); // ставит ввод в консоли на UTF8
    SetConsoleOutputCP(65001); // ставит вывод в консоли на UTF8

    double a,b;
    std::cout << "Введите первое число:";
    std::cin >> a;
    std::cout<<"Введите второе число:";
    std::cin>>b;
    std::cout<<std::fixed<<std::setprecision(2); // точность до второго знака
    std::cout<<"Сумма:"<<a+b<<"\n";
    std::cout<<"Разность:"<<a-b<<"\n";
    std::cout<<"Произведение:"<<a*b<<"\n";
    std::cout<<"Деление:"<<a/b<<"\n";
    std::cout<<"Целочисленное деление:"<<static_cast<int>(a)/static_cast<int>(b)<<"\n";//static_cast принудительно переводет переменную в int
    std::cout<<"Остаток:"<<std::fmod(a,b)<<"\n"; // взятие остатка
    std::cout<<"Степень:"<<std::pow(a,b)<<"\n"; // возведение в степень
    std::cin.get();
return 0;

}
