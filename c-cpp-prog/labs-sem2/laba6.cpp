#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Student
{
    char surname[20];
    char name[20];
    int group;
    int points;

    struct Student *next;
    struct Student *prev;
};

void inputList(Student *&first, Student *&last, int number)
{
    if (number == 0)
        return;

    first = new Student;
    first->prev = NULL;
    printf("\nВведите фамилию студента: ");
    scanf("%s", first->surname);
    printf("Введите имя студента: ");
    scanf("%s", first->name);
    printf("Введите группу студента: ");
    scanf("%d", &first->group);
    printf("Введите сумму баллов ЕГЭ студента: ");
    scanf("%d", &first->points);
    printf("\n");
    Student *prev = first;
    Student *tPtr = first;

    for (int i = 1; i < number; i++)
    {
        tPtr->next = new Student;
        prev = tPtr;
        tPtr = tPtr->next;
        tPtr->prev = prev;
        printf("\nВведите фамилию студента: ");
        scanf("%s", tPtr->surname);
        printf("Введите имя студента: ");
        scanf("%s", tPtr->name);
        printf("Введите группу студента: ");
        scanf("%d", &tPtr->group);
        printf("Введите сумму баллов ЕГЭ студента: ");
        scanf("%d", &tPtr->points);
        printf("\n");
    }
    tPtr->next = NULL;
    last = tPtr;
}

void printListAsQueue(Student *first, Student *last)
{
    if (first == NULL || last == NULL)
    {
        printf("Список пуст\n");
        return;
    }

    printf("Двунаправленный-список (вывод как очередь):\n");
    printf("| Фамилия | Имя | Группа | Баллы ЕГЭ| current ptr | next ptr | prev ptr |\n");
    printf("‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\n");
    Student *tempPtr = first;
    while (tempPtr != NULL)
    {
        printf("| %8s | %8s | %8d | %8d | %8p | %8p | %8p |\n", tempPtr->surname, tempPtr->name, tempPtr->group, tempPtr->points, tempPtr, tempPtr->next, tempPtr->prev);
        tempPtr = tempPtr->next;
    }
}

void printListAsStack(Student *first, Student *last)
{
    if (first == NULL || last == NULL)
    {
        printf("Список пуст\n");
        return;
    }

    printf("Двунаправленный-список (вывод как стек):\n");
    printf("| Фамилия | Имя | Группа | Баллы ЕГЭ| current ptr | next ptr | prev ptr |\n");
    printf("‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\n");
    Student *tempPtr = last;
    while (tempPtr != NULL)
    {
        printf("| %8s | %8s | %8d | %8d | %8p | %8p | %8p |\n", tempPtr->surname, tempPtr->name, tempPtr->group, tempPtr->points, tempPtr, tempPtr->next, tempPtr->prev);
        tempPtr = tempPtr->prev;
    }
}

// 1
void printInfo(Student *first, Student *last, char surname[20])
{
    if (first == NULL || last == NULL)
    {
        printf("Список пуст\n");
        return;
    }

    Student *tPtr = first;
    bool flag = true;
    while (tPtr != NULL)
    {
        if (strcmp(tPtr->surname, surname) == 0)
        {
            flag = false;
            printf("Информация о %s(ове/овой):\nФамилия: %s\nИмя: %s\nГруппа: %d\nБаллы ЕГЭ: %d\n", surname, tPtr->surname, tPtr->name, tPtr->group, tPtr->points);
        }
        tPtr = tPtr->next;
    }
    if (flag)
        printf("Студент с введенной вами фамилией не найден!\n");
}

// 2
void printMaxPoints(Student *first, Student *last)
{
    if (first == NULL || last == NULL)
    {
        printf("Список пуст\n");
        return;
    }

    int max = 0;
    Student *tPtr = first;
    while (tPtr != NULL)
    {
        if (tPtr->points > max)
        {
            max = tPtr->points;
        }
        tPtr = tPtr->next;
    }
    printf("Максимальный балл: %d", max);
}

// 3
void pushLast(Student* first, Student *&last)
{
    if (first == NULL || last == NULL)
    {
        printf("Список пуст\n");
        return;
    }

    printf("Введите данные о новом студенте:");
    Student *newEl = new Student;
    newEl->prev = last;
    newEl->next = NULL;
    printf("\nВведите фамилию студента: ");
    scanf("%s", newEl->surname);
    printf("Введите имя студента: ");
    scanf("%s", newEl->name);
    printf("Введите группу студента: ");
    scanf("%d", &newEl->group);
    printf("Введите сумму баллов ЕГЭ студента: ");
    scanf("%d", &newEl->points);
    printf("\n");

    last->next = newEl;
    last = newEl;
}

// 4
void createFile(Student *first, Student *last)
{
    if (first == NULL || last == NULL)
        return;

    FILE *file = fopen("EGE.txt", "w");
    fprintf(file, "Двунаправленный-список (вывод как очередь):\n");
    fprintf(file, "| Фамилия | Имя | Группа | Баллы ЕГЭ| current ptr | next ptr | prev ptr |\n");
    fprintf(file, "‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\n");
    Student *tempPtr = first;
    while (tempPtr != NULL)
    {
        fprintf(file, "| %8s | %8s | %8d | %8d | %8p | %8p | %8p |\n", tempPtr->surname, tempPtr->name, tempPtr->group, tempPtr->points, tempPtr, tempPtr->next, tempPtr->prev);
        tempPtr = tempPtr->next;
    }
}

// 5
void pop(Student *&first, Student *&last, int number)
{
    if (first == NULL || last == NULL)
        return;

    Student *tempPtr = first;
    int maxCount = 0;
    while (tempPtr != NULL)
    {
        maxCount++;
        tempPtr = tempPtr->next;
    }

    int count = 1;
    tempPtr = first;
    Student *pTemp = first;
    while ((tempPtr != NULL) && (count < number))
    {
        count++;
        pTemp = tempPtr;
        tempPtr = tempPtr->next;
    }

    if (maxCount == 1)
    {
        delete first;
        first = NULL;
        last = NULL;
        return;
    }

    else if (count == 1)
    {
        Student *save = first->next;
        delete first;
        save->prev = NULL;
        first = save;
    }

    else if (count == maxCount)
    {
        delete tempPtr;
        pTemp->next = NULL;
        last = pTemp;
    }

    else
    {
        Student *save = tempPtr->next;
        delete tempPtr;
        pTemp->next = save;
        save->prev = pTemp;
    }
}

void popExactPoints(Student *&first, Student *&last, int points)
{
    if (first == NULL || last == NULL) return;

    Student *tPtr = first;
    int count = 1;

    while (tPtr != NULL)
    {
        Student *nextPtr = tPtr->next;
        if (tPtr->points == points)
        {
            pop(first, last, count);
            count--;
        }
        else
        {
            count++;
        }
        tPtr = nextPtr;
    }
}


// 6
void swap(Student *&first, Student *&last)
{
    if (first == NULL || last == NULL || first == last) return;

    Student *tempPtr = first;
    int maxCount = 0;
    while (tempPtr != NULL)
    {
        maxCount++;
        tempPtr = tempPtr->next;
    }

    if (maxCount < 2)
        return;

    Student *saveFirst = first;
    Student *afterFirst = first->next;
    Student *prevLast = last->prev;

    afterFirst->prev = last;
    prevLast->next = first;

    first->next = NULL;
    first->prev = prevLast;

    last->prev = NULL;
    last->next = afterFirst;

    first = last;
    last = saveFirst;
}

int main()
{
    Student *first = NULL, *last = NULL;

    int number;
    printf("Введите кол-во студентов:\n");
    scanf("%d", &number);

    inputList(first, last, number);
    printf("\n");
    printListAsStack(first, last);
    printf("\n");
    printListAsQueue(first, last);

    // 1
    char surname[20];
    printf("\n(1)");
    printf("Введите фамилию по которой найти информацию:\n");
    scanf("%s", surname);
    printf("\n");
    printInfo(first, last, surname);

    // 2
    printf("\n(2)");
    printMaxPoints(first, last);
    printf("\n");

    // 3
    printf("\n(3)");
    pushLast(first, last);
    printListAsQueue(first, last);

    // 4
    createFile(first, last);

    // 5
    printf("\n(5)");
    int points;
    printf("Введите студентов с какими баллами исключить: ");
    scanf("%d", &points);
    popExactPoints(first, last, points);
    printListAsQueue(first, last);

    // 6
    printf("\n(6)");
    swap(first, last);
    printListAsQueue(first, last);
}