#include <stdio.h>
#include <string.h>

void reverse_string(char* str)
{
    char* end = str + strlen(str) - 1;
    char temp;

    while (str < end)
    {
        temp = *str;
        *str = *end;
        *end = temp;
        str++;
        end--;
    }
}

int main()
{
    char s1[100];    

    printf("문자열을 입력하세요: ");
    scanf_s("%s", s1, (unsigned)sizeof(s1));     //scanf_sㄹㄹ 사용해야하ㅡ는듯 ?

    reverse_string(s1); 

    printf("뒤집어진 문자열: %s\n", s1);  

    return 0;
}