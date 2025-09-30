#include <stdio.h>
#include <string.h>

int stringSearch(const char *S, const char *S1) {
    //Функция "Поиск строки" принимает две строки, а выдает кол-во вхождений второй в первую
    int count = 0;
    int lenS1 = strlen(S1);

    if (lenS1 == 0)
        return 0;

    const char *point = S; //заводим поинтер на основе строки S для её просмотра

    while ((point = strstr(point, S1)) != NULL) { //поиск подстроки при помощи перемещения поинтера
        count++;
        point += lenS1; //перемещаем поинтер на длину подстроки
    }

    return count;
}

int main()
{
    char S[1000], S1[1000];

    printf("Write the string S: ");
    fgets(S, sizeof(S), stdin);
    S[strcspn(S, "\n")] = '\0'; //для корректного вывода убираем все переходы на новые строки
    
    printf("Write the substring S1: ");
    fgets(S1, sizeof(S1), stdin);
    S1[strcspn(S1, "\n")] = '\0'; //для корректного вывода убираем все переходы на новые строки

    int result = stringSearch(S, S1);
    printf("Count of occurrences '%s' в '%s': %d\n", S1, S, result);

    return 0;
}
