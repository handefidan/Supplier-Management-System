#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <iostream>
using namespace std;

class Product {
private:
    int id;
    string name;
    string category;
    double price;
    double weight;
    static int nextId;

public:
    Product();
    Product(string n, string cat, double p, double w);

    int getId() const;
    string getName() const;
    double getPrice() const;
    double getWeight() const;

    friend ostream& operator<<(ostream& os, const Product& p);

    static void updateNextId(int loadedId);
    string toFileString() const;
    static Product fromFileString(string data);
};

#endif
