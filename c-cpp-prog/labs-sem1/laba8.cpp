#include <stdio.h>
#include <iostream>
#include <locale.h>
#pragma warning(disable:4996)

//3
void fillArray1(int* arr, int size)
{
    printf("Введите элементы массива:\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%i", &arr[i]);
    }
}

void printArrayDetails1(int* arr, int size)
{
    printf("Адрес массива: %p\n", arr);
    for (int i = 0; i < size; i++)
    {
        printf("arr[%i] = %i, адрес: %p\n", i + 1, arr[i], &arr[i]);
    }
    printf("\n");
}

//4
void fillArray2(int** arr, int size)
{
    printf("Введите элементы массива:\n");
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            scanf("%i", &arr[i][j]);
        }
    }
}

void printArrayDetails2(int** arr, int size)
{
    printf("Адрес массива: %p\n", arr);
    printf("\n");

    for (int i = 0; i < size; i++)
    {
        printf("arr[%i] = %p, адрес: %p\n", i + 1, arr[i], &arr[i]);
    }
    printf("\n");

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("arr[%i][%i] = %i, aдрес: %p\n", i  + 1, j + 1, arr[i][j], &(arr[i][j]));
        }
        printf("\n");
    }
    printf("\n");
}

//5
void fillArray3(int arr[2][3])
{
    int N = 2, M = 3;
    printf("Введите элементы массива d3:\n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf("%i", &arr[i][j]);
        }
    }
}

void printArrayDetails3(int arr[2][3])
{
    int N = 2, M = 3;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            printf("arr[%i][%i] = %i, aдрес: %p\n", i + 1, j + 1, arr[i][j], &(arr[i][j]));
        }
        printf("\n");
    }
    printf("Адрес массива: %p\n", arr);
    printf("\n");
}


int main()
{
    setlocale(LC_ALL, "ru");

    //1
    int a;
    printf("Введите значение переменной a: ");
    scanf("%i", &a);

    printf("Адрес переменной a: %p, ее значение: %i\n\n", &a, a);

    //2
    int c;
    printf("Значение указателя для переменной c: %p\n", &c);

    int* ptrC = &c;
    printf("Введите значение переменной c:\n");
    scanf("%i", ptrC);
    printf("Адрес переменной c: %p, ее значение: %i\n\n", ptrC, c);

    //3
    int size1;
    printf("Введите размер массива d1: ");
    scanf("%i", &size1);

    int* d1 = new int[size1];
    fillArray1(d1, size1);
    printArrayDetails1(d1, size1);
    delete[] d1;

    //4
    int size2;
    printf("Введите размер массива d2: ");
    scanf("%i", &size2);

    int** d2 = new int*[size2];
    for (int i = 0; i < size2; i++) {
        d2[i] = new int[size2];
    }

    fillArray2(d2, size2);
    printArrayDetails2(d2, size2);


    for (int i = 0; i < size2; i++) {
        delete[] d2[i];
    }
    delete[] d2;

    //5
    int d3[2][3];

    fillArray3(d3);
    printArrayDetails3(d3);

    return 0;
}