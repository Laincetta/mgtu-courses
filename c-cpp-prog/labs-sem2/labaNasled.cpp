#include <cstdio>
#include <cstring>
#include <clocale>
#pragma warning(disable:4996)

class car;
class bus;

class transport {
private:
    char name[50];
protected:
    double cost;
    double price;
public:
    transport(char* name, double cost, double price) {
        strcpy(this->name, name);
        this->cost = cost;
        this->price = price;
    }
    transport() {
        this->name[0] = '\0';
        this->cost = 0.0;
        this->price = 0.0;
    }
    ~transport() {
        printf("Деструктор transport для сработал\n");
    }
    friend void printCar(car& c);
    friend void printBus(bus& b);
};

class car : public transport {
public:
    int year;
    int quantity;
    car(char* name, double cost, double price, int year, int quantity)
        : transport(name, cost, price)
    {
        this->year = year;
        this->quantity = quantity;
    }
    car() : transport() {
        this->year = 0;
        this->quantity = 0;
    }
    ~car() {
        printf("Деструктор car сработал\n");
    }
    double profit_all() {
        return (this->price - this->cost) * this->quantity;
    }
};

class bus : public transport {
public:
    int col;
    bus(char* name, double cost, double price, int col)
        : transport(name, cost, price)
    {
        this->col = col;
    }
    bus() : transport() {
        this->col = 0;
    }
    ~bus() {
        printf("Деструктор bus сработал\n");
    }
    double profit() {
        return this->price - this->cost;
    }
};

void printCar(car& c) {
    printf("Машина:\n");
    printf("Название      : %s\n", c.name);
    printf("Себестоимость : %.2f\n", c.cost);
    printf("Цена продажи  : %.2f\n", c.price);
    printf("Год выпуска   : %d\n", c.year);
    printf("Количество    : %d\n", c.quantity);
    printf("Общая прибыль : %.2f\n\n", c.profit_all());
}

void printBus(bus& b) {
    printf("Автобус:\n");
    printf("Название       : %s\n", b.name);
    printf("Себестоимость  : %.2f\n", b.cost);
    printf("Цена продажи   : %.2f\n", b.price);
    printf("Количество мест: %d\n", b.col);
    printf("Прибыль за ед. : %.2f\n\n", b.profit());
}

int main() {
    setlocale(LC_ALL, "ru");

    // Задание 1: Локальный transport
    printf("ЗАДАНИЕ 1:\n");
    char trName[50] = "Грузовик";
    double trCost = 15000.0;
    double trPrice = 20000.0;
    transport tLocal(trName, trCost, trPrice);
    printf("Объект transport: name=%s, cost=%.2f, price=%.2f\n\n",
        trName, trCost, trPrice);

    // Задание 2: Динамический car
    printf("ЗАДАНИЕ 2:\n");
    char carName[50] = "Легковушка";
    double carCost = 20000.0;
    double carPrice = 25000.0;
    int    carYear = 2021;
    int    carQuantity = 5;
    car* cDyn = new car(carName, carCost, carPrice, carYear, carQuantity);
    printf("Объект car: name=%s, cost=%.2f, price=%.2f, year=%d, quantity=%d, profit=%.2f\n\n",
        carName, carCost, carPrice, carYear, carQuantity, cDyn->profit_all());

    // Задание 3: Динамический массив bus
    printf("ЗАДАНИЕ 3:\n");
    printf("Введите число автобусов: ");
    int n;
    scanf("%d", &n);
    bus* buses = new bus[n];
    for (int i = 0; i < n; i++) {
        char nameBuf[50];
        double costBuf, priceBuf;
        int colBuf;
        printf("Автобус %d (name cost price col): ", i + 1);
        scanf("%49s %lf %lf %d", nameBuf, &costBuf, &priceBuf, &colBuf);
        buses[i] = bus(nameBuf, costBuf, priceBuf, colBuf);
    }
    printf("\n  Все автобусы:\n\n");
    for (int i = 0; i < n; i++) {
        printf("  [%d] ", i + 1);
        printBus(buses[i]);
    }

    // Задание 4: Поиск по условию
    printf("ЗАДАНИЕ 4:\n");
    printf("Введите минимальное число мест: ");
    int minCol;
    scanf("%d", &minCol);
    printf("\nАвтобусы с местами > %d:\n\n", minCol);
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (buses[i].col > minCol) {
            printf("[%d] ", i + 1);
            printBus(buses[i]);
            found = true;
        }
    }
    if (!found) {
        printf("Нет автобусов, соответствующих условию.\n\n");
    }

    delete[] buses;
    delete cDyn;
    return 0;
}
