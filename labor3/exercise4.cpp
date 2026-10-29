#include <iostream>   // Подключение библиотеки ввода-вывода (cin, cout, getline)
#include <string>     // Подключение класса std::string для работы со строками
#include <algorithm>  // Подключение алгоритмов STL (std::count для подсчёта пробелов)

#ifdef _WIN32         // Если компиляция идёт под Windows
#include <windows.h>  // Подключение WinAPI (SetConsoleCP, SetConsoleOutputCP)
#endif

// ---------- Вспомогательные функции для UTF-8 ----------

// Функция определяет длину UTF-8 символа по первому байту
static int utf8CharLen(unsigned char c) {
    if (c < 0x80) return 1;           // Если старший бит 0 — ASCII-символ, 1 байт
    if ((c & 0xE0) == 0xC0) return 2; // Если старшие биты 110 — 2-байтовый символ (кириллица)
    if ((c & 0xF0) == 0xE0) return 3; // Если старшие биты 1110 — 3-байтовый символ
    return 4;                         // Иначе — 4-байтовый символ (эмодзи, редкие иероглифы)
}

// Функция переводит строку UTF-8 в верхний регистр
std::string toUpperUTF8(const std::string& s) {
    std::string result;
    result.reserve(s.size()); // Резервируем память под размер исходной строки

    for (size_t i = 0; i < s.size(); ) { // Цикл по байтам
        unsigned char c = s[i];

        // Проверяем, что это первый байт кириллицы
        if ((c == 0xD0 || c == 0xD1) && i + 1 < s.size()) {
            unsigned char next = s[i + 1]; // Берём второй байт символа

            if (c == 0xD0 && next >= 0xB0 && next <= 0xBF) {
                // Если это строчная а-п (D0 B0..BF) -> заглавная А-П
                result += (char)0xD0;
                result += (char)(next - 0x20);
            }
            else if (c == 0xD1 && next == 0x91) {
                // Если это строчная ё (D1 91) -> заглавная Ё (D0 81)
                result += (char)0xD0;
                result += (char)0x81;
            }
            else if (c == 0xD1 && next >= 0x80 && next <= 0x8F) {
                // Если это строчная р-я (D1 80..8F) -> заглавная Р-Я
                result += (char)0xD0;
                result += (char)(next + 0x20);
            }
            else {
                // Любой другой 2-байтовый символ копируем без изменений
                result += s[i];
                result += s[i + 1];
            }
            i += 2; // Сдвигаем i на 2 байта
        }
        else {
            // Ветка для ASCII-символов (1 байт)
            if (c >= 'a' && c <= 'z')
                result += (char)(c - 32); // Преобразуем латиницу в заглавную
            else
                result += (char)c;        // Цифры, пробелы и знаки копируем как есть
            i++; // Сдвигаем i на 1 байт
        }
    }
    return result;
}

// Функция переводит строку UTF-8 в нижний регистр
std::string toLowerUTF8(const std::string& s) {
    std::string result;
    result.reserve(s.size());

    for (size_t i = 0; i < s.size(); ) {
        unsigned char c = s[i];

        // Проверяем, что это первый байт кириллицы
        if ((c == 0xD0 || c == 0xD1) && i + 1 < s.size()) {
            unsigned char next = s[i + 1];

            if (c == 0xD0 && next >= 0x90 && next <= 0x9F) {
                // Если это заглавная А-П (D0 90..9F) -> строчная а-п
                result += (char)0xD0;
                result += (char)(next + 0x20);
            }
            else if (c == 0xD0 && next == 0x81) {
                // Если это заглавная Ё (D0 81) -> строчная ё (D1 91)
                result += (char)0xD1;
                result += (char)0x91;
            }
            else if (c == 0xD0 && next >= 0xA0 && next <= 0xAF) {
                // Если это заглавная Р-Я (D0 A0..AF) -> строчная р-я
                result += (char)0xD1;
                result += (char)(next - 0x20);
            }
            else {
                // Любой другой 2-байтовый символ
                result += s[i];
                result += s[i + 1];
            }
            i += 2;
        }
        else {
            // Ветка для ASCII-символов (1 байт)
            if (c >= 'A' && c <= 'Z')
                result += (char)(c + 32); // Преобразуем латиницу в строчную
            else
                result += (char)c;
            i++;
        }
    }
    return result;
}

// Функция считает количество символов (не байт) в UTF-8
int countCharsUTF8(const std::string& s) {
    int count = 0;
    for (size_t i = 0; i < s.size(); ) {
        unsigned char c = s[i];
        int len = utf8CharLen(c);
        if (i + len > s.size()) break; // Защита от обрезанных символов
        i += len;
        count++;
    }
    return count;
}

// Функция возвращает первый символ UTF-8 как строку
std::string firstUTF8Char(const std::string& s) {
    if (s.empty()) return "";
    int len = utf8CharLen((unsigned char)s[0]);
    if ((size_t)len > s.size()) len = (int)s.size();
    return s.substr(0, len);
}

// Функция возвращает последний символ UTF-8 как строку
std::string lastUTF8Char(const std::string& s) {
    if (s.empty()) return "";
    int start = (int)s.size() - 1;
    // Пока байт является байтом продолжения (10xxxxxx), отступаем назад
    while (start > 0 && ((unsigned char)s[start] & 0xC0) == 0x80) {
        start--;
    }
    return s.substr(start);
}

// ---------- main ----------

int main() {
#ifdef _WIN32
    // Настройка консоли Windows на работу с UTF-8
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
#endif

    std::string text;
    std::cout << "Введите строку: ";
    std::getline(std::cin, text);

    // Отладочная информация
    std::cout << "[DEBUG] Введено: \"" << text << "\"\n"
              << "Байт: " << text.size() << ", Символов: " << countCharsUTF8(text) << "\n";

    std::cout << "\n--- Длина строки ---\n";
    std::cout << "Длина: " << countCharsUTF8(text) << " символов\n";

    std::cout << "\n--- Регистры ---\n";
    std::cout << "Верхний регистр: " << toUpperUTF8(text) << "\n";
    std::cout << "Нижний регистр: " << toLowerUTF8(text) << "\n";

    std::cout << "\n--- Первый и последний символ ---\n";
    if (!text.empty()) {
        std::cout << "Первый символ: " << firstUTF8Char(text) << "\n";
        std::cout << "Последний символ: " << lastUTF8Char(text) << "\n";
    } else {
        std::cout << "Строка пустая\n";
    }

    std::cout << "\n--- Пробелы ---\n";
    int spaces = (int)std::count(text.begin(), text.end(), ' ');
    std::cout << "Количество пробелов: " << spaces << "\n";

    return 0;
}
