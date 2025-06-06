#include <stdio.h>
#include <locale.h>
#include <math.h>

int main()
{
    int n;
    double x1, x2, a, xn;

    printf("Введите значение первого члена ряда x1, значение второго члена ряда x2, параметр a, номер члена n, соответственно, через enter:\n");
    scanf("%lf%lf%lf%i", &x1, &x2, &a, &n);

    if (n == 1)
    {
        printf("Значение %i-ого элемента последовательности: %lf\n", n, x1);
    }
    else if (n == 2)
    {
        printf("Значение %i-ого элемента последовательности: %lf\n", n, x2);
    }
    else
    {
        for (int i = 3; i <= n; i++)
        {
            xn = a * sin(x2) / x1;
            x2 = x1;
            x1 = xn;
        }
        printf("Значение %i-ого элемента последовательности: %lf\n", n, xn);
    }
}