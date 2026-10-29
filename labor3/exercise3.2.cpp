//преобразование — из формата часы:минуты:секунды в общее количество секунд

#include <iostream> // вывод ввод
#include <windows.h> // библеотека для коректного отображения кирилицы в консоле



int main(){
    SetConsoleCP(65001); // ставит ввод в консоли на UTF8
    SetConsoleOutputCP(65001);
    int totalSeconds;
    int totalMinuts;
    int totalHours;

    std::cout << "Введите количество секунд: ";
    std::cin >> totalSeconds;

    std::cout << "Введите количество минут: ";
    std::cin >> totalMinuts;

    std::cout << "Введите количество часов: ";
    std::cin >> totalHours;

    int seconds = totalSeconds + totalMinuts*60 +totalHours*60*60;

    std::cout << "Значение в секундах:" << seconds << "\n";
    std::cin.get();

return 0;
}
