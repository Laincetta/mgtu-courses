#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Queue
{
    int value;
    struct Queue* next;
};

Queue* inputList()
{
    Queue* first = NULL;
    Queue* tempPointer = NULL;
    char tempString[20];
    printf("Введите значение для первого элемента (если вводить элемент не собираетесь - enter): ");
    fgets(tempString, 20, stdin);
    if (tempString[0] == '\n')
        return NULL;
    else
    {   
        tempPointer = new Queue;
        tempPointer->value = atoi(tempString);
        first = tempPointer;
        printf("Введите значение для следующего элемента (если вводить элемент не собираетесь - enter): ");
        fgets(tempString, 20, stdin);
        while (tempString[0] != '\n')
        {
            tempPointer->next = new Queue;
            tempPointer = tempPointer->next;
            tempPointer->value = atoi(tempString);
            printf("Введите значение для следующего элемента (если вводить элемент не собираетесь - enter): ");
            fgets(tempString, 20, stdin);
            tempPointer->next = NULL;
        }
    }
    return first;
}

void printList(Queue* first)
{
    Queue* tempPointer = first;
    printf("\nСписок:\n");
    if (tempPointer == NULL)
    {
        printf("Список пуст.\n");
        return;
    }
    while(tempPointer != NULL)
    {
        printf("adress: %p; value: %d; next: %p\n", tempPointer, tempPointer->value, tempPointer->next);
        tempPointer = tempPointer->next;
    }
}

//1
Queue* popFirst(Queue* first)
{
    if (first == NULL)
    {
        printf("Список пуст. Удаление первого элемента невозможно.\n");
        return NULL;
    }
    Queue* newFirst = first->next;
    delete first;
    printf("Первый элемент успешно удален.\n");
    return newFirst;
}

//2
void push2Last(Queue* first)
{
    Queue* tempPointer = first;
    while(tempPointer->next != NULL)
    {
        tempPointer = tempPointer->next;
    }
    tempPointer->next = new Queue;
    tempPointer = tempPointer->next;
    printf("Введите значение 1-го добавляемого элемента с конца: ");
    scanf("%d", &tempPointer->value);
    tempPointer->next = new Queue;
    tempPointer = tempPointer->next;
    printf("Введите значение 2-го добавляемого элемента с конца: ");
    scanf("%d", &tempPointer->value);
    tempPointer->next = NULL;
}

//3
Queue* pushFirst(Queue* first)
{
    Queue* newFirst = new Queue;
    newFirst->next = first;
    printf("Введите значение нового первого элемента: ");
    scanf("%d", &newFirst->value);
    return newFirst;
}

//4
Queue* pop(int elNumber, Queue* first)
{
    if (first == NULL)
    {
        printf("Список пуст. Удаление элемента невозможно.\n");
        return NULL;
    }
    int count = 1;
    Queue* temp = first;
    Queue* pTemp = first;
    Queue* newFirst;
    while (count != elNumber)
    {
        if (temp == NULL) {
            printf("Элемента с таким номером не существует.\n");
            return first;
        }
        pTemp = temp;
        temp = temp->next;
        count++;
    }

    if (count == 1)
    {
        newFirst = first->next;
        delete first;
        return newFirst;
    }

    else if (temp->next == NULL)
    {
        pTemp->next = NULL;
        delete temp;
    }

    else
    {
        pTemp->next = temp->next;
        delete temp;
    }
    return first;
}

//5
Queue* push(int elNumber, Queue* first)
{
    int count = 1;
    Queue* temp = first;
    Queue* pTemp = first;
    while (count != elNumber)
    {
        if (temp == NULL) {
            printf("Элемента с таким номером не существует.\n");
            return first;
        }
        pTemp = temp;
        temp = temp->next;
        count++;
    }

    if (count == 1)
    {
        first = pushFirst(first);
    }

    else if (temp->next == NULL)
    {
        temp->next = new Queue;
        temp = temp->next;
        printf("Введите новый элемент: ");
        scanf("%d", &temp->value);
        temp->next = NULL;
    }
    else
    {
        Queue* save = temp->next;
        temp->next = new Queue;
        temp = temp->next;
        printf("Введите новый элемент: ");
        scanf("%d", &temp->value);
        temp->next = save;
    }
    return first;
}

//6
Queue* popByValue(int usValue, Queue* first)
{
    if (first == NULL)
    {
        printf("Список пуст. Удаление элементов невозможно.\n");
        return NULL;
    }
    Queue* tempPointer = first;
    int count = 1;
    while(tempPointer != NULL)
    {
        if (tempPointer->value == usValue)
        {
            first = pop(count, first);
            tempPointer = first;
            count = 1;
            continue;
        }
        tempPointer = tempPointer->next;
        count++;
    }
    return first;
}


int main()
{
    Queue* first = NULL;

    first = inputList();
    printList(first);

    // //1
    // printf("\n(1): Список после удаления первого\n");
    // first = popFirst(first);
    // printList(first);

    // //2
    // printf("\n(2): Список после добавления 2х элементов\n");
    // push2Last(first);
    // printList(first);

    // //3
    // printf("\n(3): Список после добавления нового элемента в начало:\n");
    // first = pushFirst(first);
    // printList(first);

    // //4
    // printf("\n(4): Список после удаления элемента введенного пользователем:\n");
    int number;
    // printf("Введите номер элемента, который необходимо удалить: ");
    // scanf("%d", &number);
    // first = pop(number, first);
    // printList(first);

    // //5
    // printf("\n(5): Список после добавления элемента введенного пользователем:\n");
    // printf("Введите номер элемента, после которого добавить новый: ");
    // scanf("%d", &number);
    // first = push(number, first);
    // printList(first);

    //6
    printf("\n(6): Список после удаления элементов равным по значению числу введенному пользователем:\n");
    printf("Введите число: ");
    scanf("%d", &number);
    first = popByValue(number, first);
    printList(first);
}