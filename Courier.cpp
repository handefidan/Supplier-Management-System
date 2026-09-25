#include "Courier.h"
#include <vector>

int Courier::nextId = 1;

Courier::Courier() : Person() { id = 0; maxVolume = 0; maxWeight = 0; }

// Constructor'da Person(n, p, e) cagriliyor
Courier::Courier(string n, string p, string e, double v, double w)
    : Person(n, p, e) {
    id = nextId++;
    maxVolume = v;
    maxWeight = w;
}

int Courier::getId() const { return id; }

void Courier::updateNextId(int loadedId) {
    if (loadedId >= nextId) nextId = loadedId + 1;
}

ostream& operator<<(ostream& os, const Courier& c) {
    os << "ID: " << c.id << " | " << c.name << " | Cap: " << c.maxWeight << "kg";
    return os;
}

void upgradeCourierCapacity(Courier& c) {
    c.maxWeight = c.maxWeight * 1.10;
    cout << "Success: Courier " << c.name << " capacity upgraded to " << c.maxWeight << "kg!\n";
}

string Courier::toFileString() const {
    return "COURIER|" + to_string(id) + "|" + name + "|" + phone + "|" + email + "|" + to_string(maxVolume) + "|" + to_string(maxWeight);
}

Courier Courier::fromFileString(string data) {
    string tokens[7]; int t=0; string temp = "";
    for(char c : data) { if(c == '|') { if(t<7) tokens[t++] = temp; temp=""; } else temp+=c; }
    tokens[t] = temp;
    Courier c;
    if(t >= 6) {
        c.id = stoi(tokens[1]);
        c.name = tokens[2];
        c.phone = tokens[3];
        c.email = tokens[4];
        c.maxVolume = stod(tokens[5]);
        c.maxWeight = stod(tokens[6]);
    }
    return c;
}
