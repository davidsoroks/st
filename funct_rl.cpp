#include <iostream>
#include <fstream>
#include "funct_cr.h"

using namespace std;

void add(tovar &p1, tovar &p2){
    p1.grn += p2.grn;
    p1.cop += p2.cop;
    if (p1.cop >= 100) {
        p1.grn += p1.cop / 100;
        p1.cop %= 100;
    }
}
void multiply(tovar &p1, int qual) {
    p1.grn *= qual;
    p1.cop *= qual;
    p1.grn += p1.cop / 100;
    p1.cop %= 100;
}
void round(tovar &p1) {
    if (p1.cop % 10 >= 5) {
        p1.cop += (10 - p1.cop % 10); // Округлення вгору
    } else {
        p1.cop -= p1.cop % 10; // Округлення вниз
    }
    if (p1.cop >= 100) {
        p1.grn += p1.cop / 100;
        p1.cop %= 100;
    }
}

void print_res() {
    ifstream file("test.txt");
    if (!file) {
        cout << "Помилка відкриття файлу!" << endl;
        return;
    }

    string name;
    int grn, kop, quantity;
    tovar total = {"Загальна вартість:", 0, 0, 0};
    while (file >> name >> grn >> kop >> quantity) {
    tovar temp;
    temp.name = name;
    temp.grn = grn;
    temp.cop = static_cast<short int>(kop);
    temp.quantity = quantity;

        round(temp);
        multiply(temp, quantity);
        add(total, temp);
    }
    file.close();
    cout << "Вартість всіх товарів: " << total.grn << " грн. " << total.cop << " коп." << endl;

}
