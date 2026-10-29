//Запрашивает строку у пользователя Выводит её длину Выводит строку в верхнем и нижнем регистре Выводит первый и последний символ Подсчитывает количество пробелов

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <windows.h>


int main () {

    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    std::string text;
    std::cout <<"Введите строку: ";
    std::getline(std::cin,text);
    std::cout<<"Длина:"<< text.length()<<"\n";


    std::string upper =text;
    std::transform(upper.begin(), upper.end(), upper.begin(), [](unsigned char c) {return std::toupper(c);});
    std::cout<<"Верхний регистр: "<<upper<<"\n";

    std::string lower = text;
    std::transform(lower.begin(), lower.end(), lower.begin(), [](unsigned char c) { return std::tolower(c);});
    std::cout<<"Нижний регистр: "<< lower <<"\n";

    std::cout<<"Первый символ:"<< text.front()<<"\n";
    std::cout<<"Последний символ:"<< text.back()<<"\n";

    int spaces = std::count(text.begin(),text.end(),' ');
    std::cout <<"Количество пробелов:"<<spaces << "\n";
    std::cin.get();
    return 0;
}
