#include <iostream>
#include <cstdio>

// Ввод
void inputArray(double A[10][10], int n, int m) {
    printf("Введите элементы массива %ix%i через пробел:\n", n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%lf", &A[i][j]);
        }
    }
}

// Вывод
void outputArray(double A[10][10], int n, int m) {
    printf("Массив %ix%i:\n", n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%8.2lf", A[i][j]);
            if (j != m - 1) printf(", ");
        }
        printf("\n");
    }
}

// Задание 1
void printMaxElement(double A[10][10], int n, int m) {
    double maxElement = A[0][0];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i][j] > maxElement) maxElement = A[i][j];
        }
    }
    printf("Максимальный элемент массива %ix%i: %8.2lf\n", n, m, maxElement);
}

// Задание 2
void printMinElement(double A[10][10], int n, int m) {
    double minElement = A[0][0];
    int minElementIndexI = 0;
    int minElementIndexJ = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i][j] < minElement) {
                minElement = A[i][j];
                minElementIndexI = i;
                minElementIndexJ = j;
            }
        }
    }
    printf("Минимальный элемент массива %ix%i: %8.2lf; его индекс: A[%i][%i]\n", n, m, minElement, minElementIndexI + 1, minElementIndexJ + 1);
}

// Задание 3
double getLastStringMaxElement(double A[10][10], int n, int m) {
    double maxLastStringElement = A[n - 1][0];
    for (int i = 1; i < m; i++) {
        if (A[n - 1][i] > maxLastStringElement) maxLastStringElement = A[n - 1][i];
    }
    return maxLastStringElement;
}

// Задание 4
double getStringAverage(double A[10][10], int index, int m) {
    double stringSum = 0;
    for (int i = 0; i < m; i++) {
        stringSum += A[index - 1][i];
    }
    return stringSum / m;
}

// Задание 5
int getColumnEvenElements(double A[10][10], int n, int index) {
    int countEvenElements = 0;
    for (int i = 0; i < n; i++) {
        if ((int)(A[i][index - 1]) % 2 == 0) countEvenElements++;
    }
    return countEvenElements;
}

int main() {
    double A[10][10];
    int n, m;

    do {
        printf("Введите мерность массива (n и m):\n");
        scanf("%i %i", &n, &m);
    } while (n <= 0 || n > 10 || m <= 0 || m > 10);

    inputArray(A, n, m);
    outputArray(A, n, m);

    // Задание 1: Найти максимальный элемент
    printMaxElement(A, n, m);

    // Задание 2: Найти минимальный элемент и его индекс
    printMinElement(A, n, m);

    // Задание 3: Найти максимальный элемент последней строки
    double maxLastRow = getLastStringMaxElement(A, n, m);
    printf("Максимальный элемент последней строки массива %ix%i: %8.2lf\n", n, m, maxLastRow);

    // Задание 4: Среднее арифметическое строки по индексу
    int index;
    do {
        printf("Введите индекс строки для среднего арифметического (1 <= индекс <= %i):\n", n);
        scanf("%i", &index);
    } while (index <= 0 || index > n);
    printf("Среднее арифметическое для %i-й строки массива %ix%i: %8.2lf\n", index, n, m, getStringAverage(A, index, m));

    // Задание 5: Количество четных элементов в столбце по индексу
    do {
        printf("Введите индекс столбца для подсчета четных элементов (1 <= индекс <= %i):\n", m);
        scanf("%i", &index);
    } while (index <= 0 || index > m);
    printf("Количество четных элементов для %i-го столбца массива %ix%i: %i\n", index, n, m, getColumnEvenElements(A, n, index));

    return 0;
}