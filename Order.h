#ifndef ORDER_H
#define ORDER_H

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Order {
private:
    struct OrderLineItem {
        int prodId;
        string prodName;
        int qty;
        double price;
        double weight;
    };

    int id;
    int supplierId;
    string status;
    int courierId;
    string courierName;
    vector<OrderLineItem> items;
    static int nextId;

public:
    Order();
    Order(int suppId);

    void addItem(int pId, string pName, int q, double pr, double w);
    void assignCourier(int cId, string cName);

    // FUNCTION OVERLOADING ORNEGI
    void setStatus(string s);
    void setStatus(int statusCode); // Overload edilmis fonksiyon

    int getId() const;
    string getStatus() const;

    friend ostream& operator<<(ostream& os, const Order& o);

    static void updateNextId(int loadedId);
    string toFileString() const;
    static Order fromFileString(string data);
};

#endif
