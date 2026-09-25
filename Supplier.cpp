#include "Supplier.h"
#include <vector>

int Supplier::nextId = 1;

Supplier::Supplier() : Person() { id = 0; }

// Constructor'da Person(n, p, e) cagriliyor (Inheritance)
Supplier::Supplier(string n, string cat, string cName, string p, string e, string addr)
    : Person(n, p, e) {
    id = nextId++;
    category = cat;
    contactName = cName;
    address = addr;
}

int Supplier::getId() const { return id; }

ostream& operator<<(ostream& os, const Supplier& s) {
    os << "ID: " << s.id << " | " << s.name << " (" << s.category << ") | " << s.phone;
    return os;
}

void Supplier::updateNextId(int loadedId) {
    if (loadedId >= nextId) nextId = loadedId + 1;
}

string Supplier::toFileString() const {
    // Person'dan gelen name, phone, email verilerini de kaydediyoruz
    return "SUPPLIER|" + to_string(id) + "|" + name + "|" + category + "|" + contactName + "|" + phone + "|" + email + "|" + address;
}

Supplier Supplier::fromFileString(string data) {
    string tokens[8]; int t=0; string temp = "";
    for(char c : data) {
        if(c == '|') { if(t<8) tokens[t++] = temp; temp=""; }
        else temp+=c;
    }
    tokens[t] = temp;

    Supplier s;
    if(t >= 7) {
        s.id = stoi(tokens[1]);
        s.name = tokens[2]; // Person member
        s.category = tokens[3];
        s.contactName = tokens[4];
        s.phone = tokens[5]; // Person member
        s.email = tokens[6]; // Person member
        s.address = tokens[7];
    }
    return s;
}
