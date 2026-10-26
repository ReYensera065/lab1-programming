# # Вывод приветствия
# print("Hello, World!")
# # Вывод имени студента
# name = "Иван Иванов"
# print(f"Студент: {name}")
# # Вывод даты
# print("Дата: 2026-09-10")


# Функция вычисления квадрата числа
def square(x: int) -> int:
    return x * x


# Динамическая типизация
number = 7
# Вызов функции
result = square(number)
print(f"Число: {number}")
print(f"Квадрат: {result}")
