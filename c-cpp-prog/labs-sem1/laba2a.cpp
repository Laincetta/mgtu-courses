    #include <stdio.h>
    #include <locale.h>
    #include <math.h>

    int main()
    {
        setlocale(LC_ALL, "Rus");

        double sum = 0;
        int lim, i = 1;

        printf("Введите количество элементов последовательности:\n");
        scanf("%i", &lim);

        while (i <= lim)
        {
            double el = 1. / (4 * i + pow(5, i + 2));
            sum += el;
            printf("Номер итерации: %i, текущий элемент суммы: %lf, общая сумма: %lf\n", i, el, sum);
            i ++;
        }
        printf("Итоговая сумма: %lf\n", sum);
    }