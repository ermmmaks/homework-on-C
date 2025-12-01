#include <stdbool.h>
#include <stdio.h>

int comparison(bool* num1, bool* num2, int len)
{
    for (int i = 0; i < len; i++) {
        if (num1[i] != num2[i]) {
            if (num1[i] == true) {
                return 1;
            } else {
                return -1;
            }
        }
    }
    return 0;
}