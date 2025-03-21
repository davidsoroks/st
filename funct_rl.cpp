#include "funct_cr.h"

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
    if (p1.cop >= 100){
        p1.grn = p1.grn + (p1.cop / 100);
        p1.cop = p1.cop % 100;
    }
}
void round(tovar &p1) {
    if (p1.cop % 10 > 5) {
        p1.cop += (10 - (p1.cop % 10));
    } else if( p1.cop % 10 < 5) {
        p1.cop -= p1.cop % 10;
    }
}

void print_res() {
    // Оформив відкриття та читання файлу
    ifstream file("test.txt");
    if (!file) {
        cout << "Помилка відкриття файлу!" << endl;
        return;
    }

    string name;
    int grn, kop, quantity;
    tovar total = {"Загальна вартість:", 0, 0, 0};

    while (file >> name >> grn >> kop >> quantity) {
    // вивів значення з файлу
    cout << name << " " << grn << " грн. " << kop << " коп. " << quantity << " шт." << endl;
    
    tovar temp;
    temp.name = name;
    temp.grn = grn;
    temp.cop = static_cast<short int>(kop); // перетворення int в short int 
    temp.quantity = quantity;

    multiply(temp, quantity);
    add(total, temp);
    }
    file.close();
    // вивів загальну суму
    cout << "Сума до оплати до заокруглення: " << total.grn << " грн. " << total.cop << " коп." << endl;
    
    round(total);
    cout << "Сума всіх товарів після округлення: " << total.grn << " грн. " << total.cop << " коп." << endl;
}
