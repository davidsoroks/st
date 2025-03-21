#ifndef FUNCT_CR_H
#define FUNCT_CR_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct tovar{
    string name;
    int grn, quantity;
    short int cop;
};

void add(tovar &p1, tovar &p2);
void multiply(tovar &p1, int qual);
void round(tovar &p1);
void print_res();

#endif //FUNCT_CR.H
