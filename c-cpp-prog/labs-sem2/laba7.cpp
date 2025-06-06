#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string>

#pragma warning(disable : 4996)

class Student
{
private:
    char fam[50];
    int gr;
    int mark[3];

public:
    int ege[3];

    char* getFam()
    {
        return fam;
    }

    void setFam(const char fam[50])
    {
        strcpy(this->fam, fam);
    }

    int getGr()
    {
        return gr;
    }

    void setGr(int gr)
    {
        this->gr = gr;
    }

    int* getMark()
    {
        return mark;
    }

    void setMark(int mark[3])
    {
        for (int i = 0; i < 3; i++)
            this->mark[i] = mark[i];
    }

    int* getEge()
    {
        return ege;
    }

    void setEge(int ege[3])
    {
        for (int i = 0; i < 3; i++)
            this->ege[i] = ege[i];
    }

    int sumEge()
    {
        int sum = 0;
        for (int i = 0; i < 3; i++)
            sum += ege[i];
        return sum;
    }

    int sumMark()
    {
        int sum = 0;
        for (int i = 0; i < 3; i++)
            sum += mark[i];
        return sum;
    }

    double srMark()
    {
        return sumMark() / 3.0;
    }

    friend void inputStudents(Student* st, int n, FILE* f);
    friend void passedStudents(Student* st, int n);
};

// Ввод из файла
void inputStudents(Student* st, int n, FILE* f)
{
    for (int i = 0; i < n; i++)
    {
        fscanf(f, "%s %d %d %d %d %d %d %d",
            st[i].fam, &st[i].gr,
            &st[i].mark[0], &st[i].mark[1], &st[i].mark[2],
            &st[i].ege[0], &st[i].ege[1], &st[i].ege[2]);
    }
}

// Вывод списка студентов
void outputStudents(Student* st, int n)
{
    printf("\n--- Список студентов ---\n");
    for (int i = 0; i < n; i++)
    {
        printf("Фамилия: %s | Группа: %d | Оценки: %d %d %d | ЕГЭ: %d %d %d | Сумма ЕГЭ: %d | Средний балл: %.2f\n",
            st[i].getFam(), st[i].getGr(),
            st[i].getMark()[0], st[i].getMark()[1], st[i].getMark()[2],
            st[i].getEge()[0], st[i].getEge()[1], st[i].getEge()[2],
            st[i].sumEge(), st[i].srMark());
    }
}

// Студенты, сдавшие сессию на 4 и 5
void passedStudents(Student* st, int n)
{
    printf("\n--- Студенты, сдавшие сессию на 4 и 5 ---\n");
    for (int i = 0; i < n; i++)
    {
        if (st[i].srMark() > 4.0)
            printf("%s\n", st[i].getFam());
    }
}

// Студенты с неудовлетворительными оценками
void badStudents(Student* st, int n)
{
    printf("\n--- Студенты с неудовлетворительными оценками ---\n");
    for (int i = 0; i < n; i++)
    {
        int* marks = st[i].getMark();
        if (marks[0] < 3 || marks[1] < 3 || marks[2] < 3)
            printf("%s\n", st[i].getFam());
    }
}

// Помещение студентов с средним баллом > 4 в 10-ю группу
void moveToGroup10(Student* st, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (st[i].srMark() > 4.0)
            st[i].setGr(10);
    }
}

// Студент с минимальным средним баллом
void minSrMarkStudent(Student* st, int n)
{
    double minSr = st[0].srMark();
    int index = 0;
    for (int i = 1; i < n; i++)
    {
        if (st[i].srMark() < minSr)
        {
            minSr = st[i].srMark();
            index = i;
        }
    }

    printf("\n--- Студент с минимальным средним баллом ---\n");
    printf("Фамилия: %s | Группа: %d | Средний балл: %.2f\n",
        st[index].getFam(), st[index].getGr(), st[index].srMark());
}

// Группы с минимальными средними баллами
void minSrMarkInGroups(Student* st, int n)
{
    int groupCount = 0;
    int* groupNumbers = new int[n];
    double* groupAvgMarks = new double[n];

    for (int i = 0; i < n; i++)
    {
        int gr = st[i].getGr();
        bool found = false;

        for (int j = 0; j < groupCount; j++)
        {
            if (groupNumbers[j] == gr)
            {
                found = true;
                break;
            }
        }

        if (!found)
        {
            groupNumbers[groupCount] = gr;

            double sum = 0.0;
            int count = 0;

            for (int k = 0; k < n; k++)
            {
                if (st[k].getGr() == gr)
                {
                    sum += st[k].srMark();
                    count++;
                }
            }

            groupAvgMarks[groupCount] = sum / count;
            groupCount++;
        }
    }

    double minAvg = groupAvgMarks[0];
    int minGroup = groupNumbers[0];

    for (int i = 1; i < groupCount; i++)
    {
        if (groupAvgMarks[i] < minAvg)
        {
            minAvg = groupAvgMarks[i];
            minGroup = groupNumbers[i];
        }
    }

    printf("\n--- Средние баллы по группам ---\n");
    for (int i = 0; i < groupCount; i++)
    {
        printf("Группа %d: %.2f\n", groupNumbers[i], groupAvgMarks[i]);
    }
    printf("Минимальный средний балл у группы %d: %.2f\n", minGroup, minAvg);

    delete[] groupNumbers;
    delete[] groupAvgMarks;
}

int main()
{
    setlocale(LC_ALL, "ru");

    int n = 0;
    char str[100];
    FILE* f = fopen("student.txt", "r");
    if (f == NULL)
    {
        printf("Ошибка открытия файла\n");
        getchar();
        return 1;
    }

    while (fgets(str, 100, f) != 0)
        n++;

    printf("Количество записей: %d\n", n);
    rewind(f);

    Student* st = new Student[n];
    inputStudents(st, n, f);
    outputStudents(st, n);

    passedStudents(st, n);
    badStudents(st, n);
    moveToGroup10(st, n);
    outputStudents(st, n);

    minSrMarkStudent(st, n);
    minSrMarkInGroups(st, n);

    fclose(f);
    delete[] st;

    getchar();
    return 0;
}
