#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool balance(const char* text)
{
    char stack[100];
    int head = -1;
    
    for (int i = 0; text[i] != '\0'; i++) {
        char c = text[i];

        if (c == '(' || c == '{' || c == '[') {
            stack[++head] = c;
        } else if (c == ')' || c == '}' || c == ']') {
            if (head == -1) {
                return false; //проверка количества скобок
            }
            
            if ((c == ')' && stack[head--] != '(') ||
                (c == '}' && stack[head--] != '{') ||
                (c == ']' && stack[head--] != '[')) {
                return false; //проверка вложенности скобок
            }
        }
    }
    
    return head == -1;
}

int main(void)
{
    char userStr[100];
    printf("Write your string: ");
    fgets(userStr, sizeof(userStr), stdin);

    if (balance(userStr)) {
        printf("Balance saved\n");
    } else {
        printf("Balance isnt saved\n");
    }

    return 0;
}
