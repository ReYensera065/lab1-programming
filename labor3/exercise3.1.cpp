// Запрашивает количество секунд (целое число)  Преобразует его в формат часы:минуты:секунды

#include <iostream>
#include <iomanip> // библеотека для форматирование строк;
#include <windows.h>

int main(){
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    int totalSeconds;
    std::cout << "Введите количество секунд: ";
    std::cin >> totalSeconds;

    int hours = totalSeconds/3600;
    int minutes = (totalSeconds%3600)/60;
    int seconds = totalSeconds%60;

    std::cout << std:: setfill('0')<<std::setw(2)<<hours<<":"<<std::setw(2)<<minutes<<":"<<std::setw(2)<<seconds<<"\n";
    //setfill заполняет строчку недостоющими нулями;
    //stew задаёт ширину поля;
    std::cin.get();

return 0;
}
