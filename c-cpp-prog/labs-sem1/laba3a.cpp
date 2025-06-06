    #include <stdio.h>
    #include <locale.h>
    #include <math.h>

    int main()
    {
        setlocale(LC_ALL, "Rus");

        double sum = 0, eps;
        int i = 1;

        printf("Введите точность, с которой найти сумму ряда:\n");
        scanf("%lf", &eps);

        double el = 1. / (4 * i + pow(5, i + 2));
        while (el > eps)
        {
            sum += el;
            printf("Номер итерации: %i, текущий элемент суммы: %lf, общая сумма: %lf\n", i, el, sum);
            ++i;
            el = 1. / (4 * i + pow(5, i + 2));
        }
        printf("Заданная точность: %lf; \nИтоговая сумма: %lf\n", eps, sum);
    }