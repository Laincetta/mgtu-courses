#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct dlList
{
    int value;
    struct dlList* next;
    struct dlList* prev;
};

void inputList(dlList* &first, dlList* &last)
{
    printf("Введите первый элемент (enter - если не собираетесь вводить): \n");
    char tempStr[20];
    fgets(tempStr, 20, stdin);
    if (strcmp(tempStr, "\n") != 0)
        first = new dlList;
        first->value = atoi(tempStr);
        first->prev = NULL;
    dlList* tPtr = first;
    printf("Введите следующий элемент (enter - если не собираетесь вводить): \n");
    fgets(tempStr, 20, stdin);

    while (strcmp(tempStr, "\n") != 0)
    {
        tPtr->next = new dlList;
        dlList* save = tPtr;
        tPtr = tPtr->next;
        tPtr->prev = save;
        tPtr->value = atoi(tempStr);
        printf("Введите следующий элемент (enter - если не собираетесь вводить): \n");
        fgets(tempStr, 20, stdin);
    }
    tPtr->next = NULL;
    last = tPtr;
}

void printListAsQueue(dlList* first)
{
    printf("Двунаправленный-список (вывод как очередь):\n");
    dlList* tempPtr = first;
    while (tempPtr != NULL)
    {
        printf("value: %d\tcurrent ptr: %p\tnext ptr: %p\t prev ptr: %p\n", tempPtr->value, tempPtr, tempPtr->next, tempPtr->prev);
        tempPtr = tempPtr->next;
    }
}

void printListAsStack(dlList* last)
{
    printf("Двунаправленный-список (вывод как стек):\n");
    dlList* tempPtr = last;
    while (tempPtr != NULL)
    {
        printf("value: %d\tcurrent ptr: %p\tnext ptr: %p\t prev ptr: %p\n", tempPtr->value, tempPtr, tempPtr->next, tempPtr->prev);
        tempPtr = tempPtr->prev;
    }
}

//1
void popFirst(dlList* &first)
{
    dlList* save = first->next;
    delete first;
    save->prev = NULL;
    first = save;
}

//2
void pushFirst(dlList* &first)
{
    dlList* newEl = new dlList;
    printf("Введите новый элемент:\n");
    scanf("%d", &newEl->value);
    newEl->next = first;
    newEl->prev = NULL;
    first->prev = newEl;
    first = newEl;
}

//3
void pop(dlList* &first, int number)
{
    dlList* tempPtr = first;
    int maxCount = 0;
    while (tempPtr != NULL)
    {
        maxCount++;
        tempPtr = tempPtr->next;
    }

    int count = 1;
    tempPtr = first;
    dlList* pTemp = first;
    while (count < number)
    {
        count++;
        pTemp = tempPtr;
        tempPtr = tempPtr->next;
    }

    if (count == 1)
    {
        popFirst(first);
    }
    
    else if (count == maxCount)
    {
        delete tempPtr;
        pTemp->next = NULL;
    }

    else
    {
        dlList* save = tempPtr->next;
        delete tempPtr;
        pTemp->next = save;
        save->prev = pTemp;
    }
}

int main()
{
    dlList* first = NULL, *last = NULL;

    inputList(first, last);
    printListAsQueue(first);
    printf("\n");
    printListAsStack(last);

    //1 
    printf("\n(1)Удалить первый элемент\n");
    popFirst(first);
    printListAsQueue(first);
    printf("\n");
    printListAsStack(last);

    //2
    printf("\n(2)Перед первым элементом добавить новый элемент\n");
    pushFirst(first);
    printListAsQueue(first);
    printf("\n");
    printListAsStack(last);

    //3
    printf("\n(3)Удалить элемент, номер которого ввел пользователь с клавиатуры\n");
    int number;
    printf("Введите номер элемента, который нужно удалить: ");
    scanf("%d", &number);
    pop(first, number);
    printListAsQueue(first);
    printf("\n");
    printListAsStack(last);
}