#include "2.h"
#include <stdio.h>

void helper(long long input, long long expected)
{
    long long result = smallestNum(input);
    if (result == expected) {
        printf("Test passed\n");
    } else {
        printf("Test failed: expected -- %lld\n", expected);
    }
}

int main(void)
{
    printf("Tests running ...\n");
    
    helper(1234, 1234);
    helper(100, 100);
    helper(555, 555);
    helper(1, 1);
    helper(9876, 6789);
    helper(50301, 10035);

    printf("Tests ended\n");

    return 0;
}