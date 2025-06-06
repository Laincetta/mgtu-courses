#include <stdio.h>
#include <locale.h>
#include <math.h>

int main()
{
    setlocale(LC_ALL, "Rus");

    double x, y;
    printf("Введите координаты точки (x, y) через enter:\n");
    scanf("%lf%lf", &x, &y);

    bool y1 = (y > sqrt(3) / 3. * x);
    bool y2 = (y < sqrt(3) * x);
    bool y3 = (y < -1 * sqrt(3) / 3. * x + 5);
    
    if ( y1 && y2 && y3 )
    {
        printf("Точка подходит\n");
    }
    else
    {
        printf("Точка не подходит\n");
    }

    return 0;
}