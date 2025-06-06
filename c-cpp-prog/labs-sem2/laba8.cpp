#include <stdio.h>
#include <string.h>
#include <cmath>

class Circle
{
private:
    double centre[2]; // [x, y]
public:
    double r;
    char color[20];

    Circle()
    {
        centre[0] = 0;
        centre[1] = 0;
        r = 0;
        strcpy(color, "undefined");
    }

    Circle(double x, double y, double r, char color[20])
    {
        centre[0] = x;
        centre[1] = y;
        this->r = r;
        strcpy(this->color, color);
    }

    ~Circle()
    {
        printf("Сработал деструктор для окружности %s\n", color);
    }

    void setCentre(double x, double y)
    {
        centre[0] = x;
        centre[1] = y;
    }

    double getCentreX()
    {
        return centre[0];
    }

    double getCircleLen()
    {
        double PI = 3.141592653589793;
        return 2 * PI * r;
    }

    friend void printInfo(Circle& okr);
};

void printInfo(Circle& okr)
{
    printf("Centre (x, y): %.2lf %.2lf\nRadius: %.2lf\nColor: %s\n", 
        okr.centre[0], okr.centre[1], okr.r, okr.color);
}

// Задание 1 — ввод 3 окружностей с клавиатуры
void inputCircles(Circle a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        double x, y;
        printf("Введите координаты центра, длину радиуса и цвет окружности (%d): ", i + 1);
        scanf("%lf %lf %lf %s", &x, &y, &a[i].r, a[i].color);
        a[i].setCentre(x, y);
    }

    printf("\nВведённые окружности:\n");
    for (int i = 0; i < size; i++)
    {
        printInfo(a[i]);
    }
}

// Задание 2 — загрузка окружностей из файла
Circle** loadCirclesFromFile(char* filename, int& n)
{
    FILE* file = fopen(filename, "r");
    if (!file)
    {
        printf("Не удалось открыть файл!\n");
        n = 0;
        return nullptr;
    }

    n = 0;
    double x, y, r;
    char color[20];
    while (fscanf(file, "%lf %lf %lf %s", &x, &y, &r, color) == 4)
    {
        n++;
    }

    rewind(file);

    Circle** circles = new Circle * [n];
    for (int i = 0; i < n; i++)
    {
        fscanf(file, "%lf %lf %lf %s", &x, &y, &r, color);
        circles[i] = new Circle(x, y, r, color);
    }

    fclose(file);

    printf("\nОкружности из файла:\n");
    for (int i = 0; i < n; i++)
    {
        printInfo(*circles[i]);
    }

    return circles;
}

// Задание 3 — поиск по цвету
void searchByColor(Circle a[], int aSize, Circle* b[], int bSize)
{
    char colorToFind[20];
    printf("\nВведите цвет окружности для поиска: ");
    scanf("%s", colorToFind);

    printf("\nОкружности с цветом %s:\n", colorToFind);

    for (int i = 0; i < aSize; i++)
    {
        if (strcmp(a[i].color, colorToFind) == 0)
        {
            printInfo(a[i]);
        }
    }

    for (int i = 0; i < bSize; i++)
    {
        if (strcmp(b[i]->color, colorToFind) == 0)
        {
            printInfo(*b[i]);
        }
    }
}

// Задание 4 — поиск максимального X
void findMaxX(Circle* b[], int n)
{
    if (n == 0) return;

    double maxX = b[0]->getCentreX();
    for (int i = 1; i < n; i++)
    {
        if (b[i]->getCentreX() > maxX)
        {
            maxX = b[i]->getCentreX();
        }
    }

    printf("\nМаксимальный X: %.2lf\n", maxX);
}

// Задание 5 — сортировка по радиусу по возрастанию
void sortCirclesByRadius(Circle* okr[], int n)
{
    bool ifSorted = false;
    while (!ifSorted)
    {
        ifSorted = true;
        for (int i = 0; i < n - 1; i++)
        {
            if (okr[i]->r > okr[i + 1]->r)
            {
                Circle* temp = okr[i + 1];
                okr[i + 1] = okr[i];
                okr[i] = temp;
                ifSorted = false;
            }
        }
    }

    printf("\nМассив после сортировки по радиусу (по возрастанию):\n");
    for (int i = 0; i < n; i++)
    {
        printInfo(*okr[i]);
    }
}

// Очистка памяти
void deleteCircles(Circle* b[], int n)
{
    for (int i = 0; i < n; i++)
    {
        delete b[i];
    }
    delete[] b;
}

int main()
{
    int aSize = 3;
    Circle a[aSize];
    int bSize;

    inputCircles(a, aSize);

    Circle** b = loadCirclesFromFile((char*)"circle.txt", bSize);

    if (b)
    {
        searchByColor(a, aSize, b, bSize);
        findMaxX(b, bSize);
        sortCirclesByRadius(b, bSize);
        deleteCircles(b, bSize);
    }

    return 0;
}
