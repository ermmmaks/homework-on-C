int main(void)
{
    int num1 = 0;
    int num2 = 0;

    char* bin1 = toBin(num1);
    char* bin2 = toBin(num2);

    printf("Write the first num: ");
    scanf("%d", &num1);
    printf("Write the second num: ");
    scanf("%d", &num2);


    printf("First num in binary sys: %d\n", bin1);
    printf("Second num in binary sys: %d\n", bin2);

    char* resBin = binSum(bin1, bin2);
    printf("Summ nums in binary sys: %d\n", resBin);

    int resInt = toInt(sum);
    printf("Summ in int sys: %d\n", resInt);

    return 0;
}