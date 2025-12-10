#include <stdbool.h>
#include <stdio.h>
#include <string.h>

const char string[] = "я иду с мечем судия";

bool isPalindrome(const char* string)
{
    int leftPointer = 0;
    int rightPointer = strlen(string) - 1;

    printf("%s\n", string[leftPointer]);

    while (leftPointer <= rightPointer) {
        while (string[leftPointer] != ' ') {
            leftPointer++;
        }
        while (string[rightPointer] != ' ') {
            rightPointer--;
        }

        if (string[leftPointer] != string[rightPointer]) {
            return false;
        }
    }

    return true;
}

int main(void)
{
    if (isPalindrome(string)) {
        printf("YAY, PALINDROME!!! ^^ :DD\n");
    } else {
        printf("not palindrooome :(\n");
    }
    return 0;
}