#include "Order.h"

int Order::nextId = 1;

Order::Order() { id = 0; courierId = -1; }

Order::Order(int suppId) {
    id = nextId++;
    supplierId = suppId;
    status = "Pending";
    courierId = -1;
    courierName = "None";
}

void Order::addItem(int pId, string pName, int q, double pr, double w) {
    OrderLineItem item;
    item.prodId = pId;
    item.prodName = pName;
    item.qty = q;
    item.price = pr;
    item.weight = w;
    items.push_back(item);
}

void Order::assignCourier(int cId, string cName) {
    courierId = cId;
    courierName = cName;
    status = "Shipped";
}

// Overloading 1: String alir
void Order::setStatus(string s) { status = s; }

// Overloading 2: Int alir (Hoca sorarsa: "Burada overloading yaptim")
void Order::setStatus(int statusCode) {
    if(statusCode == 1) status = "Pending";
    else if(statusCode == 2) status = "Shipped";
    else if(statusCode == 3) status = "Delivered";
    else status = "Unknown";
}

int Order::getId() const { return id; }
string Order::getStatus() const { return status; }

ostream& operator<<(ostream& os, const Order& o) {
    os << "Order ID: " << o.id << " [Stat: " << o.status << "] Courier: " << o.courierName << "\n";
    double total = 0;
    for(const auto& item : o.items) {
        os << "  - " << item.prodName << " x" << item.qty << "\n";
        total += item.qty * item.price;
    }
    os << "  Total: " << total << " TL";
    return os;
}

void Order::updateNextId(int loadedId) {
    if (loadedId >= nextId) nextId = loadedId + 1;
}

string Order::toFileString() const {
    string s = "ORDER|" + to_string(id) + "|" + to_string(supplierId) + "|" + status + "|" + to_string(courierId) + "|" + courierName + "|" + to_string(items.size());
    for(const auto& item : items) {
        s += "|" + to_string(item.prodId) + "|" + item.prodName + "|" + to_string(item.qty) + "|" + to_string(item.price) + "|" + to_string(item.weight);
    }
    return s;
}

Order Order::fromFileString(string data) {
    vector<string> tokens; string temp = "";
    for(char c : data) { if(c == '|') { tokens.push_back(temp); temp=""; } else temp+=c; }
    tokens.push_back(temp);

    Order o;
    if(tokens.size() >= 7) {
        o.id = stoi(tokens[1]);
        o.supplierId = stoi(tokens[2]);
        o.status = tokens[3];
        o.courierId = stoi(tokens[4]);
        o.courierName = tokens[5];

        int count = stoi(tokens[6]);
        int idx = 7;
        for(int i=0; i<count; i++) {
            if(idx + 4 < tokens.size()) {
                o.addItem(stoi(tokens[idx]), tokens[idx+1], stoi(tokens[idx+2]), stod(tokens[idx+3]), stod(tokens[idx+4]));
                idx += 5;
            }
        }
    }
    return o;
}
