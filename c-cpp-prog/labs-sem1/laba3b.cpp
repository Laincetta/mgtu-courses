#include <stdio.h>
#include <locale.h>
#include <math.h>

int main()
{
    double a, b, h;
    setlocale(LC_ALL, "ru");

    printf("Введите интервал x через enter, x определен на [-15; -10) ∪ (-10; 10) (левую границу a и правую границу b):\n");
    scanf("%lf%lf", &a, &b);

    printf("Введите шаг, с которым будет вычисляться y на выбранном интервале (h > 0):\n");
    scanf("%lf", &h);
    
    while (h <= 0)
    {
        printf("Ошибка: шаг должен быть больше 0.\n");
        printf("Введите шаг, с которым будет вычисляться y на выбранном интервале (h > 0):\n");
        scanf("%lf", &h);
    }


    for (double x = a; x <= b; x += h)
    {
        bool sect1 = (x < 10 && x >= -5);
        bool sect2 = (x > -15 && x < -5 && x != -10);

        if (sect1)
        {
            double y = cbrt(cos(x));
            printf("x = %lf;\ty = %lf\n", x, y);
        }
        else if (sect2)
        {
            double y = sin(x) / (x + 10);
            printf("x = %lf;\ty = %lf\n", x, y);
        }
        else
        {
            printf("x = %lf;\ty - не определен\n", x);
        }
    }
    return 0;
}