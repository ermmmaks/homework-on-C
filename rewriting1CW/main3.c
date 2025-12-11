#include "3.h"
#include <stdio.h>

void helper(List* input, List* expected)
{
    List* resultList = reverseList(input);
    if (isEqual(resultList, expected)) {
        printf("Test passed\n");
    } else {
        printf("Test failed: result -- %p, expected -- %p\n", resultList, expected);
    }
}

int main(void)
{
    printf("Tests running ...\n");
    //first quick test
    List* quickList = createList();
    insertList(quickList, 0, 1);
    insertList(quickList, 0, 3);
    insertList(quickList, 0, 2);

    List* expected1 = createList();
    insertList(expected1, 0, 2);
    insertList(expected1, 0, 3);
    insertList(expected1, 0, 1);

    helper(quickList, expected1);

    //second test with mirrored list
    List* mirroredList = createList();
    insertList(mirroredList, 0, 5);
    insertList(mirroredList, 0, 5);
    insertList(mirroredList, 0, 5);

    List* expected2 = createList();
    insertList(expected2, 0, 5);
    insertList(expected2, 0, 5);
    insertList(expected2, 0, 5);

    helper(mirroredList, expected2);

    printf("Tests ended\n");



    deleteList(quickList);
    deleteList(mirroredList);
    deleteList(expected1);
    deleteList(expected2);

    return 0;
}