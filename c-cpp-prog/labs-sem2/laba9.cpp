#include <stdio.h>
#include <string.h>
#include <cmath>

class Product {
private:
    int quantity;
public:
    double cost; // закупка
    double price; // продажа
    char name[20];

    Product(int quantity, double cost, char name[20]) {
        this->quantity = quantity;
        this->cost = cost;
        this->price = cost * 1.1;
        strcpy(this->name, name);
    }

    Product(int quantity, double cost, double price, char name[20]) {
        this->quantity = quantity;
        this->cost = cost;
        this->price = price;
        strcpy(this->name, name);
    }

    ~Product()
    {
        printf("\nСработал деструктор!\n");
    }

    double getTotalCost() {
        return quantity * cost;
    }

    double getProfit() {
        return price - cost;
    }

    double getTotalProfit() {
        return getProfit() * quantity;
    }

    void setQuantity(int quantity) {
        this->quantity = quantity;
    }

    int getQuantity() {
        return quantity;
    }

    friend void printInfo(Product a);
};

void printInfo(Product a) {
    printf("Name: %-10s Quantity: %-3d Cost: %-8.2lf Price: %-8.2lf Profit/unit: %-7.2lf Total Cost: %-8.2lf Total Profit: %-8.2lf\n",
           a.name, a.quantity, a.cost, a.price, a.getProfit(), a.getTotalCost(), a.getTotalProfit());
}

void printArr(Product** products, int n) {
    printf("\nЗАДАНИЕ 2. Список товаров из файла:\n\n");
    for (int i = 0; i < n; i++) {
        printInfo(*products[i]);
    }
}

Product* inputVar() {
    int quantity;
    double cost, price;
    char name[20];
    printf("\nЗАДАНИЕ 1. Введите товар (кол-во, цена закупки, цена продажи, имя): ");
    scanf("%d %lf %lf %s", &quantity, &cost, &price, name);
    Product* a = new Product(quantity, cost, price, name);
    printf("Введённый товар:\n");
    printInfo(*a);
    return a;
}

int countN(char fileName[20]) {
    FILE* f = fopen(fileName, "r");
    if (f == NULL) {
        printf("Не удалось открыть файл!\n");
        return 0;
    }
    int n = 0;
    int quantity;
    double cost;
    char name[20];
    while (fscanf(f, "%s %d %lf", name, &quantity, &cost) == 3) {
        n++;
    }
    fclose(f);
    return n;
}

Product** inputArr(char fileName[20], int n) {
    FILE* f = fopen(fileName, "r");
    if (f == NULL) {
        printf("Не удалось открыть файл!\n");
        return nullptr;
    }
    Product** products = new Product * [n];
    int quantity;
    double cost;
    char name[20];
    for (int i = 0; i < n; i++) {
        fscanf(f, "%s %d %lf", name, &quantity, &cost);
        products[i] = new Product(quantity, cost, name);
    }
    fclose(f);
    printArr(products, n);
    return products;
}

void searchByName(Product** a, int n) {
    printf("\nЗАДАНИЕ 3. Изменение количества товара по названию.\n");
    char name[20];
    int newQuantity;
    printf("Введите название товара: ");
    scanf("%s", name);
    printf("Введите новое количество: ");
    scanf("%d", &newQuantity);
    for (int i = 0; i < n; i++) {
        if (strcmp(a[i]->name, name) == 0) {
            a[i]->setQuantity(newQuantity);
            printf("Обновлённый товар:\n");
            printInfo(*a[i]);
        }
    }
}

void printTotalProfit(Product** a, int n) {
    printf("\nЗАДАНИЕ 4. Общая прибыль со всех товаров (формула: (price - cost) * quantity):\n");
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i]->getTotalProfit();
    }   
    printf("Общая прибыль: %.2lf\n", sum);
}

void printTotalCost(Product** a, int n) {
    printf("\nЗАДАНИЕ 5. Общая стоимость закупки всех товаров (формула: cost * quantity):\n");
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i]->getTotalCost();
    }
    printf("Общая стоимость закупки: %.2lf\n", sum);
}

int main() {
    // Задание 1
    Product* p = inputVar();

    // Задание 2
    char fileName[20] = "shop.txt";
    int n = countN(fileName);
    if (n == 0) return 1;
    Product** arr = inputArr(fileName, n);

    // Задание 3
    searchByName(arr, n);

    // Задание 4 и 5
    printTotalProfit(arr, n);
    printTotalCost(arr, n);

    // Очистка
    delete p;
    for (int i = 0; i < n; i++) {
        delete arr[i];
    }
    delete[] arr;
    return 0;
}
