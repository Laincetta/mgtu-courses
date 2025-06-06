#include <stdio.h>
#include <locale.h>
#pragma warning(disable:4996)

void readArrFromFile(FILE* file, int** arr, int size)
{
    if (file == NULL)
    {
        printf("Ошибка чтения файла.\n");
        return;
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            fscanf(file, "%d", &arr[i][j]);
        }
    }
}

int getSize(FILE* file)
{
    int value;
    fscanf(file, "%d", &value);
    return value;
}

void printArr(int** arr, int size)
{
    printf("\nМассив:\n");
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%4d", arr[i][j]);
        }
        printf("\n");
    }
}

// 1. Найти максимальный элемент в массиве и индексы первого максимального
int getMaxAndInd(int** arr, int size, int* iI, int* iJ)
{
    int max = arr[0][0];
    *iI = 0;
    *iJ = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (arr[i][j] > max)
            {
                max = arr[i][j];
                *iI = i;
                *iJ = j;
            }
        }
    }
    return max;
}

// 2. Найти минимальный элемент на главной диагонали и индекс последнего минимального
int getMinAndInd(int** arr, int size, int* I)
{
    int min = arr[0][0];
    *I = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i][i] <= min)
        {
            min = arr[i][i];
            *I = i;
        }
    }
    return min;
}

// 3. Найти первый отрицательный элемент на побочной диагонали и его индекс
int getNegAndInd(int** arr, int size, int* I)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i][size - 1 - i] < 0)
        {
            *I = i;
            return arr[i][size - 1 - i];
        }
    }
    *I = -1; // Если отрицательного элемента нет
    return 0;
}

int main()
{
    setlocale(LC_ALL, "ru");

    char name[20];
    printf("Введите имя файла: ");
    scanf("%s", name);

    FILE* f = fopen(name, "r");
    if (f == NULL)
    {
        printf("Ошибка открытия файла.\n");
        return 1;
    }

    int size = getSize(f);

    int** arr = new int* [size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = new int[size];
    }

    readArrFromFile(f, arr, size);
    fclose(f);

    printArr(arr, size);

    // 1. Максимальный элемент и его индексы
    int max, indI, indJ;
    max = getMaxAndInd(arr, size, &indI, &indJ);
    printf("\nМаксимальный элемент: %d (индексы: [%d][%d])\n", max, indI + 1, indJ + 1);

    // 2. Минимальный элемент на главной диагонали и его индексы
    int min, ind;
    min = getMinAndInd(arr, size, &ind);
    printf("Минимальный элемент на главной диагонали: %d (индексы: [%d][%d])\n", min, ind + 1, ind + 1);

    // 3. Первый отрицательный элемент на побочной диагонали и его индексы
    int neg, indNeg;
    neg = getNegAndInd(arr, size, &indNeg);
    if (indNeg == -1)
    {
        printf("Отрицательных элементов на побочной диагонали нет.\n");
    }
    else
    {
        printf("Первый отрицательный элемент на побочной диагонали: %d (индексы: [%d][%d])\n", neg, indNeg + 1, size - indNeg);
    }

    for (int i = 0; i < size; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}
