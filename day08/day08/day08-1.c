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

    printf("���ڿ��� �Է��ϼ���: ");
    scanf_s("%s", s1, (unsigned)sizeof(s1));     //scanf_s���� ����ؾ��ϤѴµ� ?

    reverse_string(s1); 

    printf("�������� ���ڿ�: %s\n", s1);  

    return 0;
}