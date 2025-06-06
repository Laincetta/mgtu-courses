#include <cstdio>
#include <clocale>

int main()
{
    setlocale(LC_ALL, "ru");
    int A[20], size;

    // Ввод размера массива и проверка
    do {
        printf("Введите размер массива (от 1 до 20): ");
        scanf("%i", &size);
    } while (size < 1 || size > 20);

    // Ввод элементов массива
    printf("Введите элементы массива:\n");
    for (int i = 0; i < size; i++) {
        scanf("%i", &A[i]);
    }

    // Вывод массива в формате [1, 2, 3]
    printf("Исходный массив: [");
    for (int i = 0; i < size; i++) {
        printf("%i", A[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n\n");

    // Задание 1. Посчитать кол-во минимальных эл-тов. Вывести их индексы
    printf("Задание 1. Посчитать кол-во минимальных эл-тов. Вывести их индексы:\n");
    int min_el = A[0];
    for (int i = 1; i < size; i++)
    {
        if (A[i] < min_el)
        {
            min_el = A[i];
        }
    }
    int count_mins = 0;
    printf("Индексы минимальных: ");
    for (int i = 0; i < size; i++)
    {
        if (A[i] == min_el)
        {
            count_mins++;
            printf("%i ", i+1);
        }
    }
    printf("\tКоличество минимальных: %i\n", count_mins);

    // Задание 2. Вывести первый положительный эл-нт и его индекс
    printf("\nЗадание 2. Вывести первый положительный эл-нт и его индекс:\n");
    bool found_positive = false;
    for (int i = 0; i < size; i++)
    {
        if (A[i] > 0)
        {
            found_positive = true;
            printf("Значение элемента: %i\tИндекс элемента: %i\n", A[i], i+1);
            break;
        }
    }
    if (!found_positive)
    {
        printf("Нет положительных элементов\n");
    }

    // Задание 3. Поменять местами элементы максимальный, и индекс которого введен с клавиатуры
    printf("\nЗадание 3. Поменять местами элементы максимальный, и индекс которого введен с клавиатуры:\n");
    int max_el = A[0];
    int max_index = 0;
    int swap_index = 0;
    printf("Введите индекс элемента, который поменять с максимальным: ");
    scanf("%i", &swap_index);
    swap_index--;
    for (int i = 1; i < size; i++)
    {
        if (A[i] > max_el)
        {
            max_el = A[i];
            max_index = i;
        }
    }
    // Проверка на корректность введенного индекса
    if (swap_index >= 0 && swap_index < size) {
        int temp = A[swap_index];
        A[swap_index] = max_el;
        A[max_index] = temp;
    }
    else {
        printf("Некорректный индекс для замены.\n");
    }

    printf("Массив после преобразований: [");
    for (int i = 0; i < size; i++) {
        printf("%d", A[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n\n");

    //Задание 4. Удалить из массива элементы большие 5
    printf("\nЗадание 4. Удалить из массива элементы большие 5:\n");
    int new_size = size;
    for (int i = 0; i < new_size; i++)
    {
        if (A[i] > 5)
        {
            if (i != new_size - 1)
            {
                for (int j = i; j < new_size - 1; j++)
                {
                    int temp = A[j + 1];
                    A[j + 1] = A[j];
                    A[j] = temp;
                }
            }
            new_size--;
            i--;
        }
    }
    printf("Массив после преобразований: [");
    for (int i = 0; i < new_size; i++) {
        printf("%d", A[i]);
        if (i < new_size - 1) printf(", ");
    }
    printf("]\n\n");

    //Задание 5. Отсортировать массив по убыванию
    printf("\nЗадание 5. Отсортировать массив по убыванию:\n");
    int i = 0;
    int countSwaps = 1;
    while (i < new_size - 1 && countSwaps > 0)
    {
        countSwaps = 0;
        for (int j = 0; j < new_size - 1 - i; j++)
        {
            if (A[j] < A[j + 1])
            {
                int temp = A[j + 1];
                A[j + 1] = A[j];
                A[j] = temp;
                countSwaps++;
            }
        }
        i++;
    }
    printf("Массив после преобразований: [");
    for (int i = 0; i < new_size; i++) {
        printf("%d", A[i]);
        if (i < new_size - 1) printf(", ");
    }
    printf("]\n\n");
}