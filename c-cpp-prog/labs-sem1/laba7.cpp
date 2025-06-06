#include <stdio.h>
#include <iostream>
#include <locale.h>
#pragma warning(disable:4996)

void printArray(int arr[10][10], int size)
{
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      printf("%4i ", arr[i][j]);
    }
    printf("\n");
  }
}

void fillArray(int arr[10][10], int size)
{
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      scanf("%i", &arr[i][j]);
    }
  }
}

//1
int getPosMain(int arr[10][10], int size)
{
  int count = 0;
  
  for (int i = 0; i < size; i++)
  {
    if (arr[i][i] > 0) count++;
  }

  return count;
}

//2
int getMinSide(int arr[10][10], int size)
{
  int minEl = arr[0][size - 1];

  for (int i = 1; i < size; i++)
  {
    if (arr[i][size - 1 - i] < minEl) minEl = arr[i][size - 1 - i];
  }

  return minEl;
}

//3
void printMinMainRight(int arr[10][10], int size)
{
  int minEl = arr[0][0];
  int minIndI = 0, minIndJ = 0;
  for (int i = 0; i < size; i++)
  {
    for (int j = i; j < size; j++)
    {
      if (arr[i][j] < minEl) { 
        minEl = arr[i][j];
        minIndI = i;
        minIndJ = j;
      }
    }
  }
  printf("Минимальный элемент и индексы первого минимального в области от главной диагонали и правее: arr[%i][%i]=%i\n", minIndI + 1, minIndJ + 1, minEl);
}

//4
void swapRows(int arr[10][10], int size, int i1, int i2)
{
  if (i1 < 1 || i1 > size || i2 < 1 || i2 > size) {
    printf("Ошибка: некорректные номера строк\n");
    return;
  }
  i1--;
  i2--;
  for (int i = 0; i < size; i++)
  {
    int t = arr[i2][i];
    arr[i2][i] = arr[i1][i];
    arr[i1][i] = t;
  }
}

//5
void sortColumn(int arr[10][10], int size, int c)
{
  if (c < 1 || c > size) {
    printf("Ошибка: некорректный номер столбца\n");
    return;
  }
  c--;
  int i = 0;
  bool ifSwapped = false;
  do
  {
    for (int j = 0; j < size - i - 1; j++)
    {
      if (arr[j][c] > arr[j + 1][c])
      {
        int temp = arr[j][c];
        arr[j][c] = arr[j + 1][c];
        arr[j + 1][c] = temp;
        ifSwapped = true;
      }
    }
    i++;
  } while (ifSwapped && i < size - 1);
}

int main()
{
  setlocale(LC_ALL, "ru");
  int size;
  do {
    printf("Введите размер массива (1–10):\n");
    scanf("%i", &size);
    if (size <= 0 || size > 10) printf("Ошибка: размер должен быть от 1 до 10\n");
  } while (size <= 0 || size > 10);
  
  int arr[10][10];
  printf("Введите элементы массива:\n");
  fillArray(arr, size);
  printf("\n");
  printArray(arr, size);

  //1
  printf("Кол-во положительных элементов на главной диагонали: %i\n", getPosMain(arr, size));

  //2
  printf("Значение минимального элемента на побочной диагонали: %i\n", getMinSide(arr, size));

  //3
  printMinMainRight(arr, size);

  //4
  int i1, i2;
  printf("Введите номера строк для смены мест:\n");
  scanf("%i%i", &i1, &i2);
  swapRows(arr, size, i1, i2);
  printArray(arr, size);

  //5
  int j;
  printf("Введите номер столбца для сортировки:\n");
  scanf("%i", &j);
  sortColumn(arr, size, j);
  printArray(arr, size);
}