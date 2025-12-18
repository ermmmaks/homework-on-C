#pragma once
#include <stdbool.h>
#include <stdint.h>

typedef struct Bin32 {
    bool bits[32];
    bool overflow;
} Bin32;

/* Просто строит число в двоичной системе счисления
путем сдвигания в край каждого бита и сравнения с 1
*/

Bin32 toBin(int32_t num);

/* получает на вход два массива битов двоичных чисел
возвращает их сумму
*/

Bin32 binSum(Bin32 bin1, Bin32 bin2);

/* принимает двоичное 32-битное число
возвращает 32-битное десятичное число
*/

int32_t toInt(Bin32 num);

/* выводит полную форму двоичного 32-битного числа
*/

void printFull(Bin32 num);

/* выводит компактную форму двоичного 32-битного числа
*/

void printCompact(Bin32 num);

/* побитовое сравнение числа в двоичном представлении в структуре со строкой (для тестов)
*/

bool compareBinWithStr(Bin32 num1, char* num2);