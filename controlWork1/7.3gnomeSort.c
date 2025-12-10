#include <stdio.h>

void gnomeSort(int rowOfPots[], int countOfPots)
{
    for (int i = 1; i < countOfPots;) {
        if (rowOfPots[i] >= rowOfPots[i - 1]) {
            i++;
        } else {
            int temp = rowOfPots[i];
            rowOfPots[i] = rowOfPots[i - 1];
            rowOfPots[i - 1] = temp;

            if (i > 1) {
                i--;
            }
        }
    }
}

int main(void)
{
    int countOfPots = 0;
    printf("Write the length of the array: ");
    scanf("%d", &countOfPots);
    int rowOfPots[countOfPots];

    printf("Write the array element separated by enter: ", countOfPots);
    scanf("%d", &rowOfPots[i]);

    gnomeSort(rowOfPots, countOfPots);

    printf("Result: ");
    for (int i = 0; i < countOfPots; i++)
        printf("%d", rowOfPots[i]);
    printf("\n");

    return 0;
}