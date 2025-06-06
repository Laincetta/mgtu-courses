#include <cstdio>

int main() {
    int A[20], size;

    // Ввод размера массива и проверка
    do {
        printf("Введите размер массива (от 1 до 20): ");
        scanf("%d", &size);
    } while (size < 1 || size > 20);

    // Ввод элементов массива
    printf("Введите элементы массива:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &A[i]);
    }

    // Вывод массива в формате [1, 2, 3]
    printf("Исходный массив: [");
    for (int i = 0; i < size; i++) {
        printf("%d", A[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n\n");

    // Задание 1: Элементы массива, кратные трём
    printf("Задание 1. Элементы массива, кратные трём:\n");
    printf("[");
    bool first = true;
    for (int i = 0; i < size; i++) {
        if (A[i] % 3 == 0) {
            if (!first) printf(", ");
            printf("%d", A[i]);
            first = false;
        }
    }
    printf("]\n\n");

    // Задание 2: Увеличение чётных элементов в два раза
    printf("Задание 2. Увеличение чётных элементов в два раза:\n");
    for (int i = 0; i < size; i++) {
        if (A[i] % 2 == 0) {
            A[i] *= 2;
        }
    }
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", A[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n\n");

    // Задание 3: Сумма положительных элементов
    printf("Задание 3. Сумма положительных элементов:\n");
    int sum_pos = 0;
    for (int i = 0; i < size; i++) {
        if (A[i] > 0) {
            sum_pos += A[i];
        }
    }
    printf("%d\n\n", sum_pos);

    // Задание 4: Поменять местами первый и последний элементы
    printf("Задание 4. Поменять местами первый и последний элементы:\n");
    int temp = A[0];
    A[0] = A[size - 1];
    A[size - 1] = temp;
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", A[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n\n");

    // Задание 5: Поменять местами элементы по индексам, введённым с клавиатуры
    int index1, index2;
    printf("Задание 5. Введите два индекса для обмена (нумерация с 1):\n");
    scanf("%d %d", &index1, &index2);
    temp = A[index1 - 1];
    A[index1 - 1] = A[index2 - 1];
    A[index2 - 1] = temp;
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", A[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n\n");

    // Задание 6: Среднее арифметическое всех элементов
    printf("Задание 6. Среднее арифметическое всех элементов:\n");
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += A[i];
    }
    printf("%.2f\n\n", sum / (float)size);

    // Задание 7: Найти значение максимального элемента
    printf("Задание 7. Максимальный элемент:\n");
    int max_elem = A[0];
    for (int i = 1; i < size; i++) {
        if (A[i] > max_elem) {
            max_elem = A[i];
        }
    }
    printf("%d\n\n", max_elem);

    // Задание 8: Найти значение минимального элемента и его индекс
    printf("Задание 8. Минимальный элемент и его индекс:\n");
    int min_elem = A[0], min_index = 0;
    for (int i = 1; i < size; i++) {
        if (A[i] < min_elem) {
            min_elem = A[i];
            min_index = i;
        }
    }
    printf("%d (индекс %d)\n\n", min_elem, min_index + 1);

    // Задание 9: Подсчитать количество минимальных элементов
    printf("Задание 9. Количество минимальных элементов:\n");
    int min_count = 0;
    for (int i = 0; i < size; i++) {
        if (A[i] == min_elem) {
            min_count++;
        }
    }
    printf("%d\n\n", min_count);

    // Задание 10: Найти минимальный элемент среди чётных элементов
    printf("Задание 10. Минимальный элемент среди чётных элементов:\n");
    
    int min_even = 0;
    bool found_even = false;

    for (int i = 0; i < size; ++i)
    {
        if (A[i] % 2 == 0)
        {
            min_even = A[i];
            found_even = true;
            break;
        }
    }

    if (found_even)
    {
        for (int i = 0; i < size; ++i)
        {
            if (A[i] % 2 == 0 && A[i] < min_even)
            {
                min_even = A[i];
            }
        }
        printf("%d\n\n", min_even);
    }
    else
    {
        printf("Нет чётных элементов\n\n");
    }

    // Задание 11: Среднее арифметическое элементов, кратных пяти
    printf("Задание 11. Среднее арифметическое элементов, кратных пяти:\n");
    int sum_div5 = 0, count_div5 = 0;
    for (int i = 0; i < size; i++) {
        if (A[i] % 5 == 0) {
            sum_div5 += A[i];
            count_div5++;
        }
    }
    if (count_div5 > 0) {
        printf("%.2f\n", sum_div5 / (float)count_div5);
    } else {
        printf("Нет элементов, кратных пяти\n");
    }

    return 0;
}