// Проверка, является ли число палиндромом (без использования строковых функций)
#include <iostream>
#include <windows.h>
#include <cmath>


int main(){
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    std::cout<< " Введите число: ";
    int nonrevers;
    std::cin >> nonrevers;

    nonrevers = std::abs(nonrevers);

    int chengebl = nonrevers;

    int k = 0;
    while (chengebl > 0){
        chengebl = chengebl /10;
        k += 1;
    }

    int k_status = 0;
    if (fmod(k,2) == 0){
        k_status = 1;
    } else {
        k_status = 0;
    }

    int first_part = 0;
    int second_part = 0;
    int chenge = nonrevers;

    // Если число меньше 10, то оно является палиндромом
    if ((nonrevers - 10 <0) && (nonrevers - 10 > -10)){
        std::cout<<"Число является палиндромом\n";
        std::cin.get();
        return 0;
    }

    if (k_status == 1){
    // Если число чётное

        for (int i = 0;k/2>i;i++){
        second_part = second_part * 10 + chenge % 10;;
        chenge = chenge / 10;

    }
        first_part = nonrevers /pow(10,k/2);

        {
            if (first_part == second_part){
                std::cout<<"Число является палиндромом\n";
                std::cin.get();
                return 0;
            } else {
                std::cout<<"Число не является палиндромом\n";
                std::cin.get();
                return 0;
            }
        }
    }else{

    // если число чётное
        for (int i = 0;k/2>i;i++){
        second_part = second_part * 10 + chenge % 10;;
        chenge = chenge / 10;

    }
            first_part = nonrevers / pow(10,k/2+1);
            std::cout<<first_part<<"\n";
            std::cout<<second_part<<"\n";

            {
            if (first_part == second_part){
                std::cout<<"Число является палиндромом\n";
                std::cin.get();
                return 0;
            } else {
                std::cout<<"Число не является палиндромом\n";
                std::cin.get();
                return 0;
            }
        }
    }

    std::cin.get();
    return 0;
}
