#include <stdio.h>
#include <string.h>

const char myString[] = "я иду с мечем судия";
const int lenStr = strlen(string) int elements[lenStr];

int is_palindrome(const string)
{
    char stringNoSpaces[lenStr];

    for (int i = 0; i < lenStr; i++) {
        if (string[i] != ' ') {
            strcat(stringNoSpaces, string[i]);
        }
    }

    int halfLenNewStr = strlen(stringNoSpaces) / 2

        printf("%s", stringNoSpaces);
    int countRight = 0;

    for (int i = 0; i <= halfLenNewStr; i++) {
        if (stringNoSpaces[i] == stringNoSpaces[-i]) {
            countRight++;
        }
    }

    if (countRight == halfLenNewStr) {
        return 1;
    }
    return 0;
}

int main(void)
{
    if (is_palindrome(myString)) == 1
        {
            printf("PALINDROME!!!");
        }
    return 0;
}