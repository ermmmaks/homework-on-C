#include <stdio.h>

void reverse(int arr[], int start, int end)
{
    while (start < end)
    {
        int transit = arr[start];
        arr[start] = arr[end];
        arr[end] = transit;
        start++;
        end++;
    }
}

void swap_parts(int arr[], int m, int n)
{
    reverse(arr, 0, m - 1 );
    reverse(arr, m, m + n - 1);
    reverse(arr, 0, m + n - 1);
}

int main()
{
    int len_arr;
    printf("Write the length of the array: ");
    scanf("%d", &len_arr);
    int arr[len_arr];

    printf("Write the array element separated by spaces: ", len_arr);
        for (int user_number = 0; user_number < len_arr; user_number++)
        {
            scanf("%d", &arr[user_number]);
        }

    int m, n;
    printf("Write the length of the first segment (m): ");
    scanf("%d", &m);
    printf("The lenght of the second segment (n): ", len_arr);

    swap_parts(arr, m, n);

    printf("Result: ");
    for (int i = 0; i < len_arr; i++) printf("%d", arr[i]);
    printf("\n");

    return 0;
}