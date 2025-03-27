#include "funct_cr.h"

void add(tovar &p1, tovar &p2){
    p1.grn += p2.grn;
    p1.cop += p2.cop;
}
void multiply(tovar &p1, int qual) {
    p1.grn *= qual;
    p1.cop *= qual;
}
void round(tovar &p1) {
    if (p1.cop >= 100){
        p1.grn = p1.grn + (p1.cop / 100);
        p1.cop = p1.cop % 100;
    }
    if (p1.cop % 10 > 5) {
        p1.cop += (10 - (p1.cop % 10));
    } else if( p1.cop % 10 < 5) {
        p1.cop -= p1.cop % 10;
    }
}

void print(){ 
    // Оформив відкриття та читання файлу
    ifstream file("test.txt");
    if (!file) {
        cout << "Помилка відкриття файлу!" << endl;
        return;
    }

    string name;
    int grn, quantity;
    short int kop;
    tovar total = { 0, 0};

    while (file >> name >> grn >> kop >> quantity) {
    // вивів значення з файлу
    cout << name << " " << grn << " грн. " << kop << " коп. " << quantity << " шт." << endl;
    
    tovar temp;
    temp.grn = grn;
    temp.cop = kop;

    multiply(temp, quantity);
    add(total, temp);
    }
    file.close();
    // вивів загальну суму
    cout << "Сума до оплати до заокруглення: " << total.grn << " грн. " << total.cop << " коп." << endl;
    
    round(total);
    cout << "Сума всіх товарів після округлення: " << total.grn << " грн. " << total.cop << " коп." << endl;
}
