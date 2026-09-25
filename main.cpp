#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Supplier.h"
#include "Product.h"
#include "Courier.h"
#include "Order.h"

using namespace std;

const int MAX_ITEM = 100;

Supplier suppliers[MAX_ITEM];
int supplierCount = 0;

Product products[MAX_ITEM];
int productCount = 0;

Order orders[MAX_ITEM];
int orderCount = 0;

Courier couriers[MAX_ITEM];
int courierCount = 0;

int findSupplierIndex(int id) { for (int i = 0; i < supplierCount; i++) if (suppliers[i].getId() == id) return i; return -1; }
int findProductIndex(int id) { for (int i = 0; i < productCount; i++) if (products[i].getId() == id) return i; return -1; }
int findOrderIndex(int id) { for (int i = 0; i < orderCount; i++) if (orders[i].getId() == id) return i; return -1; }
int findCourierIndex(int id) { for (int i = 0; i < courierCount; i++) if (couriers[i].getId() == id) return i; return -1; }

void saveAll() {
    ofstream f1("suppliers.txt"); for(int i=0; i<supplierCount; i++) f1 << suppliers[i].toFileString() << endl; f1.close();
    ofstream f2("products.txt"); for(int i=0; i<productCount; i++) f2 << products[i].toFileString() << endl; f2.close();
    ofstream f3("couriers.txt"); for(int i=0; i<courierCount; i++) f3 << couriers[i].toFileString() << endl; f3.close();
    ofstream f4("orders.txt"); for(int i=0; i<orderCount; i++) f4 << orders[i].toFileString() << endl; f4.close();
    cout << "All data saved.\n";
}

void loadAll() {
    cout << "--- LOADING DATA ---\n";
    string line; int maxId;

    ifstream f1("suppliers.txt"); maxId=0; if(f1.is_open()) { while(getline(f1, line)) { if(line.empty()) continue; suppliers[supplierCount] = Supplier::fromFileString(line); if(suppliers[supplierCount].getId()>maxId) maxId=suppliers[supplierCount].getId(); supplierCount++; } Supplier::updateNextId(maxId); f1.close(); }
    ifstream f2("products.txt"); maxId=0; if(f2.is_open()) { while(getline(f2, line)) { if(line.empty()) continue; products[productCount] = Product::fromFileString(line); if(products[productCount].getId()>maxId) maxId=products[productCount].getId(); productCount++; } Product::updateNextId(maxId); f2.close(); }
    ifstream f3("couriers.txt"); maxId=0; if(f3.is_open()) { while(getline(f3, line)) { if(line.empty()) continue; couriers[courierCount] = Courier::fromFileString(line); if(couriers[courierCount].getId()>maxId) maxId=couriers[courierCount].getId(); courierCount++; } Courier::updateNextId(maxId); f3.close(); }
    ifstream f4("orders.txt"); maxId=0; if(f4.is_open()) { while(getline(f4, line)) { if(line.empty()) continue; orders[orderCount] = Order::fromFileString(line); if(orders[orderCount].getId()>maxId) maxId=orders[orderCount].getId(); orderCount++; } Order::updateNextId(maxId); f4.close(); }
    cout << "Data loaded.\n";
}

void sortProductsByPrice() {
    for (int i = 0; i < productCount - 1; i++) {
        for (int j = 0; j < productCount - i - 1; j++) {
            if (products[j].getPrice() < products[j + 1].getPrice()) {
                Product temp = products[j]; products[j] = products[j + 1]; products[j + 1] = temp;
            }
        }
    }
    cout << "Products sorted by Price (High -> Low).\n";
}

void algorithmAssignOrders() {
    cout << "\n--- AUTO-ASSIGN ---\n";
    int cnt = 0;
    for (int i = 0; i < orderCount; i++) {
        if (orders[i].getStatus() == "Pending" || orders[i].getStatus() == "Waiting") {
            for (int j = 0; j < courierCount; j++) {
                orders[i].assignCourier(couriers[j].getId(), couriers[j].getName());
                cout << "Order " << orders[i].getId() << " -> " << couriers[j].getName() << endl;
                cnt++; break;
            }
        }
    }
    if (cnt == 0) cout << "No orders to assign.\n";
}

void menuSupplier() {
    cout << "\n1.Create 2.List 0.Back: "; int c; cin >> c;
    if (c == 1 && supplierCount < MAX_ITEM) {
        string name, cat, contact, phone, email, addr;
        cout << "Name: "; cin >> name; cout << "Category: "; cin >> cat;
        cout << "Contact: "; cin >> contact; cout << "Phone: "; cin >> phone;
        cout << "Email: "; cin >> email; cout << "Address: "; cin >> addr;
        suppliers[supplierCount++] = Supplier(name, cat, contact, phone, email, addr);
    } else if (c == 2) {
        for(int i=0; i<supplierCount; i++) {
            cout << suppliers[i] << endl;
            // Default argument test (Hoca sorarsa: Base class fonksiyonunu kullaniyorum)
            // suppliers[i].printBasicInfo();
        }
    }
}

void menuProduct() {
    cout << "\n1.Create 2.List 3.SORT(Price) 0.Back: "; int c; cin >> c;
    if (c == 1 && productCount < MAX_ITEM) {
        string name, cat; double p, w;
        cout << "Name: "; cin >> name; cout << "Cat: "; cin >> cat;
        cout << "Price: "; cin >> p; cout << "Weight: "; cin >> w;
        products[productCount++] = Product(name, cat, p, w);
    } else if (c == 2) {
        for(int i=0; i<productCount; i++) cout << products[i] << endl;
    } else if (c == 3) {
        sortProductsByPrice();
        for(int i=0; i<productCount; i++) cout << products[i] << endl;
    }
}

void menuCourier() {
    cout << "\n1.Create 2.List 3.Upgrade Capacity (Friend) 0.Back: "; int c; cin >> c;
    if (c == 1 && courierCount < MAX_ITEM) {
        string name, phone, email; double vol, w;
        cout << "Name: "; cin >> name; cout << "Phone: "; cin >> phone;
        cout << "Email: "; cin >> email; cout << "MaxVol: "; cin >> vol; cout << "MaxWeight: "; cin >> w;
        couriers[courierCount++] = Courier(name, phone, email, vol, w);
    } else if (c == 2) {
        for(int i=0; i<courierCount; i++) cout << couriers[i] << endl;
    } else if (c == 3) {
        int id; cout << "Courier ID to Upgrade: "; cin >> id;
        int idx = findCourierIndex(id);
        if(idx != -1) upgradeCourierCapacity(couriers[idx]);
        else cout << "Courier not found.\n";
    }
}

void menuOrder() {
    cout << "\n1.Create 2.List 3.Status (String) 4.Status (Int-Overload) 5.AUTO-ASSIGN 0.Back: "; int c; cin >> c;
    if (c == 1) {
        int sid; cout << "Sup ID: "; cin >> sid;
        if(findSupplierIndex(sid) != -1) {
            Order newOrd(sid);
            while(true) {
                int op; cout << "Add Item (1:Yes 0:No): "; cin >> op; if(op==0) break;
                int pid; cout << "Prod ID: "; cin >> pid; int pidx = findProductIndex(pid);
                if(pidx != -1) {
                    int q; cout << "Qty: "; cin >> q;
                    newOrd.addItem(products[pidx].getId(), products[pidx].getName(), q, products[pidx].getPrice(), products[pidx].getWeight());
                } else cout << "Not Found.\n";
            }
            if(orderCount < MAX_ITEM) orders[orderCount++] = newOrd;
        } else cout << "Supplier Not Found.\n";
    } else if (c == 2) {
        for(int i=0; i<orderCount; i++) cout << orders[i] << endl;
    } else if (c == 3) {
        int id; cout << "ID: "; cin >> id; int idx = findOrderIndex(id);
        if(idx != -1) { string s; cout << "Status: "; cin >> s; orders[idx].setStatus(s); }
    } else if (c == 4) {
        // FUNCTION OVERLOADING TEST
        int id; cout << "ID: "; cin >> id; int idx = findOrderIndex(id);
        if(idx != -1) {
            int s; cout << "Status Code (1:Pending 2:Shipped): "; cin >> s;
            orders[idx].setStatus(s); // Int parametreli fonksiyon cagirilir
            cout << "Status updated via Overload.\n";
        }
    } else if (c == 5) algorithmAssignOrders();
}

int main() {
    loadAll();
    while(true) {
        cout << "\n--- SYSTEM ---\n1.Supplier 2.Product 3.Order 4.Courier 0.Exit\nChoice: ";
        int ch; cin >> ch;
        if(ch == 0) { saveAll(); break; }
        else if(ch == 1) menuSupplier();
        else if(ch == 2) menuProduct();
        else if(ch == 3) menuOrder();
        else if(ch == 4) menuCourier();
    }
    return 0;
}
