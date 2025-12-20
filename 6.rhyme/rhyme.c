#include "cycleLists.h"
#include <stdio.h>

int trick(int n, int m) {
    if (n <= 0 || m <= 0) {
        return -1;
    }

    List* list = createNew();
    for (int i = 1; i < n + 1; i++) {
        if (!insert(list, i - 1, i)) {
            printf("Error adding\n");
        }
    }

    ListNode* curr = list->tail;

    while (list->tail->next != list->tail) {
        for (int i = 0; i < m - 1; i++) {
            curr = curr->next;
        }
        removeNext(list, curr);
    }

    int survivor = list->tail->value;
    deleteList(list);
    return survivor;
}

int main() {
    int warriors;
    int orderOfMurder;

    scanf("%d", &warriors);
    scanf("%d", &orderOfMurder);

    printf("%d\n", trick(warriors, orderOfMurder));

    return 0;
}