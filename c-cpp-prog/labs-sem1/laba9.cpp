#include <iostream>
#include <stdio.h>
#include <locale.h>
#pragma warning(disable : 4996)

// 4
char* getAndPrintNewArray(int size)
{
    char* str = new char[size];
    printf("Введите элементы str2: ");
    for (int i = 0; i < size; i++)
    {
        scanf("\n%c", &str[i]);
    }
    printf("Введённая строка: ");
    for (int i = 0; i < size; i++)
    {
        printf("%c", str[i]);
    }
    printf("\nКоды символов: ");
    for (int i = 0; i < size; i++)
    {
        printf("%i ", (int)str[i]);
    }
    printf("\n");
    return str;
}

// 5
char** getNewArray(int size_i, int size_j)
{
    char** str = new char*[size_i];
    for (int i = 0; i < size_i; i++)
    {
        str[i] = new char[size_j];
    }
    
    printf("Введите элементы str3: ");
    for (int i = 0; i < size_i; i++)
    {
        for (int j = 0; j < size_j; j++)
        {
            scanf("\n%c", &str[i][j]);
        }
    }

    return str;
}

int main()
{
    setlocale(LC_ALL, "ru");

    // 1
    char var;
    printf("Введите значение переменной var: ");
    scanf("%c", &var);
    printf("var = '%c', ее код: %i\n", var, var);

    // 2
    char* ptrdvar = new char;
    printf("Введите значение переменной dvar: ");
    scanf("\n%c", ptrdvar);
    printf("dvar = '%c', ее адрес: %p\n", *ptrdvar, (void*)ptrdvar);
    delete ptrdvar;

    // 3
    int size1;
    printf("Введите размер массива символов str1: ");
    scanf("%i", &size1);

    char* str1 = new char[size1];
    printf("Введите элементы str1: ");
    for (int i = 0; i < size1; i++)
    {
        scanf("\n%c", &str1[i]);
    }

    int countA = 0;
    for (int i = 0; i < size1; i++)
    {
        if (str1[i] == 'a')
            countA++;
    }
    printf("Кол-во символов 'a': %i\n", countA);

    delete[] str1;

    // 4
    int size2;
    printf("Введите размер массива символов str2: ");
    scanf("%i", &size2);

    char* str2 = getAndPrintNewArray(size2);
    int countAbcCombs = 0;
    for (int i = 0; i < size2 - 2; i++)
    {
        if (*(str2 + i) == 'a' && *(str2 + i + 1) == 'b' && *(str2 + i + 2) == 'c')
        {
            countAbcCombs++;
        }
    }
    printf("Количество комбинаций abc в str2: %i\n", countAbcCombs);

    delete[] str2;

    // 5
    int size3i, size3j;
    printf("Введите размеры двумерного массива символов str3 (строки и столбцы): ");
    scanf("%i %i", &size3i, &size3j);

    char** str3 = getNewArray(size3i, size3j);

    printf("Введённый массив строк:\n");
    for (int i = 0; i < size3i; i++)
    {
        for (int j = 0; j < size3j; j++)
        {
            printf("%c ", str3[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < size3i; i++)
    {
        char temp = str3[i][size3j - 1];
        str3[i][size3j - 1] = str3[i][0];
        str3[i][0] = temp;
    }

    printf("Массив строк после смены столбцов:\n");
    for (int i = 0; i < size3i; i++)
    {
        for (int j = 0; j < size3j; j++)
        {
            printf("%c ", str3[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < size3i; i++)
    {
        delete[] str3[i];
    }
    delete[] str3;

    return 0;
}