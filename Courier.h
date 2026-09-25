#ifndef COURIER_H
#define COURIER_H

#include "Person.h" // Miras icin gerekli
#include <string>
#include <iostream>
using namespace std;

// INHERITANCE KULLANIMI
class Courier : public Person {
private:
    int id;
    double maxVolume;
    double maxWeight;
    static int nextId;

public:
    Courier();
    Courier(string n, string p, string e, double v, double w);

    int getId() const;

    // Friend Function
    friend void upgradeCourierCapacity(Courier& c);
    // Operator Overloading
    friend ostream& operator<<(ostream& os, const Courier& c);

    static void updateNextId(int loadedId);
    string toFileString() const;
    static Courier fromFileString(string data);
};

// Global friend function
void upgradeCourierCapacity(Courier& c);

#endif
