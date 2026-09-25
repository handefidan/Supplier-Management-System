#ifndef SUPPLIER_H
#define SUPPLIER_H

#include "Person.h" // Miras icin gerekli
#include <string>
#include <iostream>
using namespace std;

// INHERITANCE KULLANIMI (Supplier, Person'dan miras alir)
class Supplier : public Person {
private:
    int id;
    string category;
    string contactName;
    string address;
    static int nextId;

public:
    Supplier();
    Supplier(string n, string cat, string cName, string p, string e, string addr);

    int getId() const;

    // Operator Overloading
    friend ostream& operator<<(ostream& os, const Supplier& s);

    static void updateNextId(int loadedId);
    string toFileString() const;
    static Supplier fromFileString(string data);
};

#endif
