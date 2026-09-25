#include "Product.h"
#include <vector>

int Product::nextId = 1;

Product::Product() { id = 0; price = 0; weight = 0; }

Product::Product(string n, string cat, double p, double w) {
    id = nextId++;
    name = n;
    category = cat;
    price = p;
    weight = w;
}

int Product::getId() const { return id; }
string Product::getName() const { return name; }
double Product::getPrice() const { return price; }
double Product::getWeight() const { return weight; }

ostream& operator<<(ostream& os, const Product& p) {
    os << "ID: " << p.id << " | " << p.name << " (" << p.category << ") | " << p.price << " TL";
    return os;
}

void Product::updateNextId(int loadedId) {
    if (loadedId >= nextId) nextId = loadedId + 1;
}

string Product::toFileString() const {
    return "PRODUCT|" + to_string(id) + "|" + name + "|" + category + "|" + to_string(price) + "|" + to_string(weight);
}

Product Product::fromFileString(string data) {
    string tokens[6]; int t=0; string temp = "";
    for(char c : data) { if(c == '|') { if(t<6) tokens[t++] = temp; temp=""; } else temp+=c; }
    tokens[t] = temp;
    Product p;
    if(t >= 5) {
        p.id = stoi(tokens[1]); p.name = tokens[2]; p.category = tokens[3];
        p.price = stod(tokens[4]); p.weight = stod(tokens[5]);
    }
    return p;
}
