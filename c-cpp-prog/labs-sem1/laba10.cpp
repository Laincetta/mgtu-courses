#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

int main()
{
    setlocale(LC_ALL, "ru");

    // 1
    char* str = new char[21];
    printf("Введите строку str (максимум 20 символов): ");
    scanf("%20s", str);

    printf("Введите символ: ");
    char charToCount;
    scanf(" %c", &charToCount);

    int count = 0;
    for (char* strPtr = str; *strPtr != '\0'; strPtr++)
    {
        if (*strPtr == charToCount) count++;
    }
    printf("Введенный символ '%c' встретился в строке %d раз(-а).\n", charToCount, count);

    char* str1 = new char[21];
    char* strPtr1 = str1;
    bool found = false;

    for (char* strPtr = str; *strPtr != '\0'; strPtr++)
    {
        *strPtr1 = *strPtr;
        strPtr1++;

        if (*strPtr == charToCount)
        {
            found = true;
            break;
        }
    }
    if (found) *strPtr1 = '\0';
    else str1[0] = '\0';

    printf("Введенная строка до первого символа '%c': %s\n", charToCount, str1);

    delete[] str;
    delete[] str1;

    // 2
    char* s1 = new char[11];
    printf("Введите строку s1 (максимум 10 символов): ");
    scanf("%10s", s1);

    char* s2 = new char[11];
    printf("Введите строку s2 (максимум 10 символов): ");
    scanf("%10s", s2);

    char* s3 = new char[21];
    printf("Введите строку s3 (максимум 20 символов): ");
    scanf("%20s", s3);

    strcpy(s3, s1);
    printf("Копирование s1 в s3: %s\n", s3);

    strcpy(s3, s2);
    printf("Копирование s2 в s3: %s\n", s3);

    s3[0] = '\0';
    printf("Очистка строки s3: '%s'\n", s3);

    strncat(s3, s1, 2);
    strncat(s3, s2, 2);
    printf("s3 после конкатенации: %s\n", s3);

    printf("Длины строк: s1 = %zu, s2 = %zu, s3 = %zu\n", strlen(s1), strlen(s2), strlen(s3));

    if (strcmp(s1, s2) < 0)
        printf("Строки в алфавитном порядке: %s, %s\n", s1, s2);
    else
        printf("Строки в алфавитном порядке: %s, %s\n", s2, s1);

    delete[] s1;
    delete[] s2;
    delete[] s3;

    // 3
    char* STR = new char[51];
    printf("Введите строку (максимум 50 символов, разделённую пробелом): ");
    puts(STR);

    char* STR1 = new char[51];
    char* STR2 = new char[51];
    char* STRptr = STR;
    char* STRptr1 = STR1;
    char* STRptr2 = STR2;

    
    while (*STRptr != ' ' && *STRptr != '\0')
    {
        *STRptr1 = *STRptr;
        STRptr++;
        STRptr1++;
    }
    *STRptr1 = '\0';

    if (*STRptr == ' ') STRptr++;
    
    while (*STRptr != '\0')
    {
        *STRptr2 = *STRptr;
        STRptr++;
        STRptr2++;
    }
    *STRptr2 = '\0';

    printf("Первая часть строки: %s\n", STR1);
    printf("Вторая часть строки: %s\n", STR2);

    delete[] STR;
    delete[] STR1;
    delete[] STR2;

    return 0;
}