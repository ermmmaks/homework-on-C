#include <stdio.h>

int countZeros(int arr[], int size) {
    //На вход получает массив и его размер, а выдает кол-во нулевых элементов
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == 0)
            count++;
    }

    return count;
}

int main()
{
    int lenArr = 0;
    printf("Write the length of the array: ");
    scanf("%d", &lenArr);
    int arr[lenArr];

    printf("Write the array element separated by enter: ", lenArr);
    for (int userNumber = 0; userNumber < lenArr; userNumber++) {
        scanf("%d", &arr[userNumber]);
    }

    int zerosCount = countZeros(arr, lenArr);

    printf("Count of zeros in array: %d\n", zerosCount);

    return 0;
}