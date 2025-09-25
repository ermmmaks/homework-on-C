#include <stdio.h>

int main()
{
    int count_tickets = 0;
    int sums[28] = {0};

    for (int a = 0; a <= 9; a++)
    {
        for (int b = 0; b <= 9; b++) 
        {
            for (int c = 0; c <= 9; c++)
            {
                int sum_num = a + b + c;
                sums[sum_num]++;
            }
        }
    }

    for (int count_sum_num = 0; count_sum_num <= 27; count_sum_num++)
    {
        count_tickets += sums[count_sum_num] * sums[count_sum_num];
    }

    printf("Count of lucky tickets: %d\n", count_tickets);

    return 0;
}