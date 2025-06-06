#include <cstdio>
#include <cstring>
#include <clocale>
#include <cmath>
#pragma warning(disable:4996)


class circle;
class cylinder;
class cone;


class point {
protected:
    double x;
    double y;
public:
    point(double x, double y) {
        printf("Сработал конструктор point с параметрами\n");
        this->x = x;
        this->y = y;
    }
    point() {
        printf("Сработал конструктор point без параметров\n");
        this->x = 0.0;
        this->y = 0.0;
    }
    ~point() {
        printf("Сработал деструктор point\n");
    }
};

class circle : public point {
private:
    double r;
public:
    circle(double x, double y, double r) : point(x, y)
    {
        printf("Сработал конструктор circle с параметрами\n");
        this->r = r;
    }
    circle() : point()
    {
        printf("Сработал конструктор circle без параметров\n");
        this->r = 0.0;
    }
    ~circle() {
        printf("Сработал деструктор circle\n");
    }

    double getR()
    {
        return r;
    }

    void setR(double r)
    {
        this->r = r;
    }

    double distans() {
        return sqrtf(powf(this->x, 2) + powf(this->y, 2));
    }

    double S() {
        return 3.14 * pow(getR(), 2);
    }

    friend void printCylinder(cylinder &cyl);
    friend void printCone(cone &con);
};

class cylinder : public circle {
public:
    double h;
    cylinder(double x, double y, double r, double h)
    {
        printf("Сработал конструктор cylinder с параметрами\n");
        this->x = x;
        this->y = y;
        setR(r);
        this->h = h;
    }
    cylinder() : circle()
    {
        printf("Сработал конструктор cylinder без параметров\n");
        this->h = 0.0;
    }
    ~cylinder() {
        printf("Сработал деструктор cylinder\n");
    }
    double V() {
        return 3.14 * pow(getR(), 2) * h;
    }
};

class cone : public circle {
    public:
        double h;
        cone(double x, double y, double r, double h) : circle(x, y, r)
        {
            printf("Сработал конструктор cone с параметрами\n");
            this->h = h;
        }
        cone() : circle()
        {
            printf("Сработал конструктор cone без параметров\n");
            this->h = 0.0;
        }
        ~cone() {
            printf("Сработал деструктор cone\n");
        }
        double V() {
            return 1/3 * 3.14 * pow(getR(), 2) * h;
        }
    };

void printCylinder(cylinder &cyl) {
    printf("Цилиндр:\n");
    printf("Координата X  : %.2lf\n", cyl.x);
    printf("Координата Y  : %.2lf\n", cyl.y);
    printf("Радиус R      : %.2lf\n", cyl.r);
    printf("Высота H      : %.2lf\n", cyl.h);
    printf("Площадь       : %.2lf\n", cyl.S());
    printf("Объем V       : %.2lf\n", cyl.V());
}

void printCone(cone &con) {
    printf("Конус:\n");
    printf("Координата X  : %.2lf\n", con.x);
    printf("Координата Y  : %.2lf\n", con.y);
    printf("Радиус R      : %.2lf\n", con.r);
    printf("Высота H      : %.2lf\n", con.h);
    printf("Площадь S     : %.2lf\n", con.S());
    printf("Объем V       : %.2lf\n", con.V());
}

int main() {
    setlocale(LC_ALL, "ru");

    //1
    printf("Задание 1.\n");

    FILE* file1 = fopen("cyl.txt", "r");
    if (file1 == NULL)
    {
        printf("Ошибка открытия файла cyl.txt\n");
        return 0;
    }

    int n1;
    fscanf(file1, "%d", &n1);
    cylinder** cylinders = new cylinder*[n1];
    
    for (int i = 0; i < n1; i++)
    {
        double x;
        double y;
        double r;
        double h;
        fscanf(file1, "%lf %lf %lf %lf", &x, &y, &r, &h);
        cylinders[i] = new cylinder(x, y, r, h);
    }

    for (int i = 0; i < n1; i++)
    {
        printCylinder(*cylinders[i]);
    }
    
    //2
    printf("Задание 2.\n");
    FILE* file2 = fopen("con.txt", "r");
    if (file2 == NULL)
    {
        printf("Ошибка открытия файла con.txt\n");
        return 0;
    }

    int n2;
    fscanf(file2, "%d", &n2);
    cone** cones = new cone*[n2];
    for (int i = 0; i < n2; i++)
    {
        double x;
        double y;
        double r;
        double h;
        fscanf(file2, "%lf %lf %lf %lf", &x, &y, &r, &h);
        cones[i] = new cone(x, y, r, h);
    }

    for (int i = 0; i < n2; i++)
    {
        printCone(*cones[i]);
    }

    //3
    printf("Задание 3.\n");
    double maxVolume = cones[0]->V();

    for (int i = 1; i < n2; i++)
    {
        if (cones[i]->V() > maxVolume)
        {
            maxVolume = cones[i]->V();
        }
    }

    for (int i = 0; i < n1; i++)
    {
        if (cylinders[i]->V() > maxVolume)
        {
            maxVolume = cylinders[i]->V();
        }
    }
    
    printf("Максимальный объем среди цилиндров и конусов: %lf\n", maxVolume);

    //4
    printf("Задание 4.\n");
    double S;
    printf("Введите площадь основания: ");
    scanf("%lf", &S);
    
    printf("Цилиндры и конусы основания с площадью больше введенной:\n");
    for (int i = 0; i < n2; i++)
    {
        if (cones[i]->S() > S)
        {
            printCone(*cones[i]);
        }
    }

    for (int i = 0; i < n1; i++)
    {
        if (cylinders[i]->S() > S)
        {
            printCylinder(*cylinders[i]);
        }
    }

    //5
    printf("Задание 5.\n");
    double h;
    printf("Введите высоту: ");
    scanf("%lf", &h);
    
    printf("Цилиндры с измененной высотой:\n");
    for (int i = 0; i < n1; i++)
    {
        if (cylinders[i]->h > h)
        {
            cylinders[i]->h = h * 0.9;
            printCylinder(*cylinders[i]);
        }
    }
}