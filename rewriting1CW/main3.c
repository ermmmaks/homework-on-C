#include "3.h"
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
    
    List* myList = new();
    insertList(myList, 0, 1);
    insertList(myList, 0, 3);
    insertList(myList, 0, 2);
    
    helper(myList, reverseList(myList));

    printf("Tests ended\n");

    return 0;
}