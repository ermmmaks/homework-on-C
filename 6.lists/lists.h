#pragma once
#include <stdbool.h>

typedef struct ListNode ListNode;

typedef struct SortedList SortedList;

// создает список с одной нодой-головой

SortedList* createList(void);

//два условия пустоты - не существование и указатель на голову == NULL

bool isEmpty(SortedList* list);

// вставка значения в сортированный список

bool insertList(SortedList* list, int value);

// удаление элемента по значению

bool removeValue(SortedList* list, int value);

/* status отвечает за успех/неудачу операции (есть защита от нулевого указателя)
если список не существует, пуст или индекс отрицательный - даем статус false
ищем ноду по индексу. Если нашли - возвращаем значение
если нет и индекс больше размеров списка, то даем статус false
(при неудаче неважно что return'ить. Это сделано, чтобы можно было и -1, к примеру, получить из списка без конфликта)
*/

int get(SortedList* list, int index, bool* status);

/*если список пуст, говорим об этом
иначе поочередно с головы начинаем print'ить каждое значение
*/

void printList(SortedList* list);

/*если список не существует - false
иначе, начиная с головы и до конца удаляем элементы и очищаем память - true
*/
bool deleteList(SortedList* list);
