#include <stdio.h>
#include <math.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Rus");

    double x;
    printf("Введите x:\n");
    scanf("%lf", &x);

    bool sect1 = (x < 10 && x >= -5);
    bool sect2 = (x > -15 && x < -5 && x != -10);
    
    if (sect1)
    {
        double y = cbrt(cos(x));
        printf("y = %lf\n", y);
    }
    else if (sect2)
    {
        double y = sin(x) / (x + 10);
        printf("y = %lf\n", y);
    }
    else
    {
        printf("Указанный x вне необходимого диапазона\n");
    }

    return 0;
}