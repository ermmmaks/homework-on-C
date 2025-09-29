#include <stdio.h>

void reverse(int arr[], int start, int end)
{
    while (start < end) {
        int transit = arr[start];
        arr[start] = arr[end];
        arr[end] = transit;
        start++;
        end--;
    }
}

void swapParts(int arr[], int m, int n)
{
    reverse(arr, 0, m - 1 );
    reverse(arr, m, m + n - 1);
    reverse(arr, 0, m + n - 1);
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

    int m = 0;
    int n = 0;
    printf("Write the length of the first segment (m): ");
    scanf("%d", &m);
    n = lenArr - m;
    printf("The lenght of the second segment: (n)", n);

    swap_parts(arr, m, n);

    printf("Result: ");
    for (int i = 0; i < lenArr; i++) printf("%d", arr[i]);
    printf("\n");

    return 0;
}