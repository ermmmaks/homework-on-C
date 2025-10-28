#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <../lists.h>

void printMenu() {
    printf("\n=== Меню сортированного списка ===\n");
    printf("0 - Выйти\n");
    printf("1 - Добавить значение в сортированный список\n");
    printf("2 - Удалить значение из списка\n");
    printf("3 - Распечатать список\n");
    printf("Выберите операцию: ");
}

int main(void)
{
    SortedList* list = new();
    int choice;
    int value;

    printMenu();
    scanf("%d", &choice);

    while (choice != 0) {
        switch (choice) {
            case 0:
                printf("Выход...\n");
                break;
            case 1:
                printf("Добавление вашего элемента\n");
                scanf("%d", &value);
                if (insert(list, value)) {
                    printf("Добавлено!\n");
                } else {
                    printf("Ошибка!\n");
                }
                break;
            case 3:
                printList(list);
                break;
        }
        scanf("%d", &choice);
    }
    freeList(list);

    return 0;
}