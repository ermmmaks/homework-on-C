#include "queue.h"
#include <assert.h>
#include <stdio.h>

void testList()
{
    List* empty = newList();
    assert(isEmpty(empty));

    List* single = insert(1, empty);
    assert(single->head->value == 1);

    List* some = insert(2, single);
    assert(some->head->next->value == 2);

    List* reversed = reverse(some);
    assert(reversed->head->value == 2);
    assert(reversed->head->next->value == 1);

    deleteList(empty);
    deleteList(single);
    deleteList(come);
    deleteList(reversed);
}
