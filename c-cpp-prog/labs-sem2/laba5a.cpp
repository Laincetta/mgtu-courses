#include <stdio.h>


struct Stack
{
    int value;
    struct Stack* prev;
};

Stack* inputStack(Stack* last, int N)
{
    printf("Введите список из %d элементов:\n", N);
    if (N != 0)
        last = new Stack;
        last->prev = NULL;
        scanf("%d", &last->value);
    for (int i = 1; i < N; i++)
    {
        Stack* newEl = new Stack;
        scanf("%d", &newEl->value);
        newEl->prev = last;
        Stack* save = last;
        last = newEl;
        newEl = save;
    }
    return last;
}

void printStack(Stack* last)
{
    printf("Список-стек:\n");
    Stack* tempPtr = last;
    while (tempPtr != NULL)
    {
        printf("value: %d\t current ptr: %p\tprev ptr: %p\n", tempPtr->value, tempPtr, tempPtr->prev);
        tempPtr = tempPtr->prev;
    }
}

//1
Stack* popFirst(Stack* last, int &N)
{
    Stack* tempPtr = last;
    if (N > 2)
    {
        for (int i = 0; i < N - 2; i++)
        {
            tempPtr = tempPtr->prev;         
        }
    
        delete tempPtr->prev;
        tempPtr->prev = NULL;
    }
    else if (N == 2)
    {
        delete tempPtr->prev;
        tempPtr->prev = NULL;
    }
    else if (last->prev == NULL)
    {
        delete tempPtr;
        tempPtr = NULL;
    }
    else
        printf("Список пуст\n");

    N--;

    return last;
}

//2
Stack* popLast(Stack* last, int &N)
{
    Stack* tempPtr = last;
    if (N == 1)
    {
        last = NULL;
        return last;
    }
    else if (N == 0)
    {
        printf("Список пуст");
    }
    else
    {
        tempPtr = tempPtr->prev;
        delete last;
        last = tempPtr;
    }

    N--;

    return last;
}

int main()
{
    Stack* last = NULL;

    int N;
    printf("Введите N (кол-во элементов стека): ");
    scanf("%d", &N);

    last = inputStack(last, N);
    printStack(last);

    printf("\n(1)\n");
    last = popFirst(last, N);
    printStack(last);

    printf("\n(2)\n");
    last = popLast(last, N);
    printStack(last);
}