#include <stdio.h>
#include <string.h>
void test(char *str)
{
    str[1] = '9';
    printf("%s", str);
}

int main()
{
    char *s1 = "1234567";
    char s2[10];
    strcpy(s2, s1);
    test(s2);
}