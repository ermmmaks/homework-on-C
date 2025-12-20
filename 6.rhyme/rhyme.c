#include "cycleLists.h"
#include <stdio.h>

int main()
{
    int warriors = 0;
    int orderOfMurder = 0;

    scanf("%d", &warriors);
    scanf("%d", &orderOfMurder);

    printf("%d\n", trick(warriors, orderOfMurder));

    return 0;
}