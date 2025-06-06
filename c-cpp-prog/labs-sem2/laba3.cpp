#include <stdio.h>


struct Queue
{
    struct Queue* next;
    char fam[20];
    int gr;
};

Queue* first = NULL;

void createQueue()
{
    int flag = 1;
    printf("Будете ли вводить первый элемент (0 - нет/ 1 - да): ");
    scanf("%d", &flag);

    if (flag == 1)
    {
        first = new Queue;
        printf("Введите фамилию: ");
        scanf("%s", first->fam);
        printf("Введите группу: ");
        scanf("%d", &first->gr);
        printf("\n");
    }

    first->next=NULL;
    printf("Будете ли вводить следующий элемент (0 - нет/ 1 - да): ");
    scanf("%d", &flag);
    Queue* cur = first;

    while (flag == 1)
    {
        cur->next = new Queue;
        cur = cur->next;
        printf("Введите фамилию: ");
        scanf("%s", cur->fam);

        printf("Введите группу: ");
        scanf("%d", &cur->gr);

        printf("Будете ли вводить следующий элемент (0 - нет/ 1 - да): ");
        scanf("%d", &flag);

        printf("\n");
    }

    cur->next = NULL;
}

void printQueue()
{
    Queue* temp = first;
    while (temp != NULL)
    {
        printf("Фамилия: %s;\tГруппа: %d\n", temp->fam, temp->gr);
        temp = temp->next;
    }
}

//1
void printStudentGroup(int group)
{
    Queue* temp = first;
    bool flag = false;
    while (temp != NULL)
    {
        if (temp->gr == group)
        {
            printf("Фамилия: %s;\tГруппа: %d\n", temp->fam, temp->gr);
            flag = true;
        }
        temp = temp->next;
    }
    
    if (!flag) printf("Введенная группа не найдена!\n");
}

//2
int getCountStudentA()
{
    Queue* temp = first;
    int count = 0;
    while (temp != NULL)
    {
        if (temp->fam[0] == 'A' || temp->fam[0] == 'a')
        {
            count++;
        }
        temp = temp->next;
    }
    return count;
}

//3
void changeGroup(int group)
{
    Queue* temp = first;
    while (temp != NULL)
    {
        if (temp->gr == 1)
        {
            temp->gr = group;
        }
        temp = temp->next;
    }
}

//4
Queue* getForth() 
{
    Queue* temp = first;
    int count = 1;
    while (temp != NULL) 
    {
        if (count == 4) return temp;
        temp = temp->next;
        count++;
    }
    return NULL;
}

//5
Queue* getLast() 
{
    Queue* temp = first;
    while (temp->next != NULL) 
    {
        temp = temp->next;
    }
    return temp;
}


int main()
{
    createQueue();
    printQueue();

    //1
    printf("\n");
    int group;
    printf("Введите группу, которую найти: ");
    scanf("%d", &group);
    printStudentGroup(group);

    //2
    printf("\n");
    printf("Количество студентов, фамилия которых начинается на 'A': %d\n", getCountStudentA());

    //3
    printf("\n");
    printf("Введите группу, на которую поменять первую группу: ");
    scanf("%d", &group);
    changeGroup(group);
    printQueue();

    //4
    printf("\n");
    Queue* four = getForth();
    if (four == NULL)
    {
        printf("Такого элемента нет\n");
    }
    else printf("Адрес 4-го элемента: %d\n", four);

    //5
    printf("\n");
    Queue* last = getLast();
    printf("Адрес последнего элемента: %d\n", last);
}