#include <stdio.h>
#include <string.h>

struct Product
{
    char name[50];
    int price;
    int number;
};

// 1 + 2
void inputInfo(Product *product)
{
    printf("\nВведите название товара: ");
    scanf("%s", product->name);
    printf("Введите цену одного товара: ");
    scanf("%d", &product->price);
    printf("Введите количество товара: ");
    scanf("%d", &product->number);
}

void printInfo(Product product)
{
    printf("Название товара: %s, Цена товара: %d, Количество товара: %d\n", product.name, product.price, product.number);
}

// 3.0
int countStrings(FILE *file)
{
    int count = 0;
    char *tempString = new char[100];
    while (fgets(tempString, 100, file) != 0)
    {
        count++;
    }
    rewind(file);
    return count;
}

void fillProductArray(Product *product, int size, FILE *file)
{
    for (int i = 0; i < size; i++)
    {
        fscanf(file, "%s", product[i].name);
        fscanf(file, "%d", &product[i].price);
        fscanf(file, "%d", &product[i].number);
    }
    rewind(file);
}

void printProductArray(Product *product, int size)
{
    for (int i = 0; i < size; i++)
    {
        printInfo(product[i]);
    }
}

// 3.1
int getTotalProductPrice(Product product)
{
    int totalPrice = product.price * product.number;
    return totalPrice;
}

int getSumTotalProductPrice(Product *product, int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += getTotalProductPrice(product[i]);
    }
    return sum;
}

void printSumTotalProductPrice(int value)
{
    printf("\nСтоимость всех товаров равна: %d", value);
}

// 3.2
void printTotalPriceEachProduct(Product* product, int size)
{
    for (int i = 0; i < size; i++)
    {
        int curTotalPrice = getTotalProductPrice(product[i]);
        printf("Стоимость товара <<%s>>: %d\n", product[i].name, curTotalPrice);
    }
}

// 3.3
void printInfoCurrentProduct(Product *product, int size, char *productName)
{
    for (int i = 0; i < size; i++)
    {
        if (strncmp(product[i].name, productName, 50) == 0)
            printInfo(product[i]);
    }
}

void printTotalCurrentProductPrice(int value, char* product)
{
    printf("\nСтоимость товара <<%s>>: %d", product, value);
}

// 3.4
int getMinNumberProduct(Product* product, int size)
{
    int min = product[0].number;
    for (int i = 1; i < size; i++)
    {
        if (product[i].number < min)
            min = product[i].number;
    }
    return min;
}

void printAllMinsProduct(Product* product, int size, int min)
{
    for (int i = 1; i < size; i++)
    {
        if (product[i].number == min)
            printf("Название товара: %s\n", product[i].name);
    }
}

int main()
{
    // 1
    printf("\n(1)");
    Product product;
    inputInfo(&product);
    printInfo(product);

    // 2
    printf("\n(2)");
    Product *dynamicProduct = new Product;
    inputInfo(dynamicProduct);
    printInfo(*dynamicProduct);

    // 3
    printf("\n(3.0)");
    char *fileName = new char[50];
    printf("\nВведите название файла: ");
    scanf("%s", fileName);
    FILE *file = fopen(fileName, "r");
    if (file == NULL)
    {
        printf("\nОшибка открытия файла!\n");
        return 0;
    }

    int n = countStrings(file);
    printf("Количество различных товаров в магазине: %d", n);

    Product *productArray = new Product[n];
    printf("\nТовары из файла:\n");
    fillProductArray(productArray, n, file);
    printProductArray(productArray, n);

    // 3.1
    printf("\n(3.1)");
    int sumTotalProductPrice = getSumTotalProductPrice(productArray, n);
    printSumTotalProductPrice(sumTotalProductPrice);
    rewind(file);
    
    // 3.2
    printf("\n\n(3.2)\n");
    printTotalPriceEachProduct(productArray, n);

    // 3.3
    printf("\n(3.3)");
    char *findProduct = new char[50];
    printf("\nВведите название товара, инфу о котором вывести: ");
    scanf("%s", findProduct);
    printInfoCurrentProduct(productArray, n, findProduct);

    // 3.4
    printf("\n(3.4)\n");
    int min = getMinNumberProduct(productArray, n);
    printAllMinsProduct(productArray, n, min);
}