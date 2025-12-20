#include "lists.h"
#include <stdio.h>

void printMenu(void) {
    printf("\n=== Меню сортированного списка ===\n");
    printf("0 - Выйти\n");
    printf("1 - Добавить значение в сортированный список\n");
    printf("2 - Удалить значение из списка\n");
    printf("3 - Распечатать список\n");
    printf("4 - Показать это окно\n");
}

int main(void)
{
    SortedList* list = createList();
    int choice;
    int value;

    printMenu();
    printf("= Выберите операцию:\n");
    scanf("%d", &choice);

    while (choice != 0) {
        switch (choice) {
            case 1:
                printf("Добавление вашего элемента: \n");
                scanf("%d", &value);
                if (insertList(list, value)) {
                    printf("Добавлено!\n");
                } else {
                    printf("Список не существует или ошибка при выделении памяти!\n");
                }
                break;

            case 2:
                printf("Значение элемента, который хотите удалить: \n");
                scanf("%d", &value);
                if (removeValue(list, value)) {
                    printf("Удалено!\n");
                } else {
                    printf("Элемент не найден или список не существует!\n");
                }
                break;

            case 3:
                if (!isEmpty(list)) {
                    printf("Ваш список: ");
                    printList(list);
                } else {
                    printf("Ваш список пуст!\n");
                }
                break;

            case 4:
                printMenu();
                break;
        }
        printf("= Что-то еще? (4 - справка)\n");
        scanf("%d", &choice);
    }
    printf("Выход...\n");
    deleteList(list);

    return 0;
}