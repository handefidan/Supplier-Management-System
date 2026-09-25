<div align="center">

# 📦 Supplier & Logistics Management System (SMS)
### Tedarikçi ve Lojistik Yönetim Sistemi

[![Language](https://img.shields.io/badge/Language-C%2B%2B17-blue.svg)](https://isocpp.org/)
[![Paradigm](https://img.shields.io/badge/Paradigm-OOP-green.svg)](#)

*A modular, algorithm-driven supply chain and inventory management console application built with modern C++ Object-Oriented Programming (OOP) principles.*

[English](#-english) | [Türkçe](#-türkçe)

---

</div>

## 🌐 English

### 📖 Overview
The **Supplier Management System (SMS)** is an enterprise-oriented console software designed to coordinate suppliers, product inventories, customer orders, and courier logistics. The system demonstrates practical implementations of core software architecture patterns, algorithmic optimization, and persistent file-based storage.

### ✨ Key Features
- **Supplier & Catalog Management:** Register suppliers, catalog items, and maintain live inventory metrics.
- **Order Pipeline & Courier Logistics:** Manage incoming orders and distribute assignments according to courier capacities.
- **Price & Priority Sorting:** In-memory dataset arrangement using deterministic sorting algorithms (e.g., Bubble Sort).
- **Logistics Load Optimization (Knapsack Problem):** Maximize delivery efficiency and payload capacities per courier run.
- **File Persistence:** Complete transactional state preservation via disk I/O, allowing persistent sessions across system restarts.

### 🛠️ Architecture & OOP Design Patterns
- **Separation of Concerns:** Rigid segregation between header interface files (`.h`) and implementation files (`.cpp`).
- **Encapsulation & Data Hiding:** Strict private state control with guarded accessors and mutators.
- **Inheritance & Polymorphism:** Extensible class hierarchies representing participants across the supply chain.
- **Advanced Operator & Function Overloading:** Streamlined I/O operations and comparative logic through custom operators.
- **Friend Components:** Controlled internal coupling for specialized data operations.

### 📂 Project Structure
```plaintext
supplier-management-system/
├── include/              # Header files (.h)
│   ├── Supplier.h
│   ├── Product.h
│   ├── Order.h
│   ├── Courier.h
│   └── SystemManager.h
├── src/                  # Implementation files (.cpp)
│   ├── Supplier.cpp
│   ├── Product.cpp
│   ├── Order.cpp
│   ├── Courier.cpp
│   ├── SystemManager.cpp
│   └── main.cpp
├── data/                 # Serialized database records (.txt / .dat)
├── CMakeLists.txt        # Build automation config
└── README.md
```

### ⚙️ Build and Run

#### Prerequisites
- A modern C++ compiler supporting **C++17** or higher (GCC, Clang, or MSVC).
- *(Optional)* CMake 3.15+

#### Using GCC / g++
```bash
# Clone the repository
git clone https://github.com/your-username/supplier-management-system.git
cd supplier-management-system

# Compile the application
g++ -std=c++17 -Iinclude src/*.cpp -o supplier_system

# Launch
./supplier_system
```

#### Using CMake
```bash
mkdir build && cd build
cmake ..
cmake --build .
./supplier_system
```

---

## 🇹🇷 Türkçe

### 📖 Genel Bakış
**Tedarikçi Yönetim Sistemi (SMS)**; tedarikçi profillerini, ürün stoklarını, sipariş süreçlerini ve kurye lojistiğini tek bir yapı altında koordine eden C++ konsol uygulamasıdır. Temiz kod (clean code) prensiplerine uygun, modüler nesne yönelimli mimari ve algoritmik optimizasyon yaklaşımları temel alınarak geliştirilmiştir.

### ✨ Temel Özellikler
- **Tedarikçi ve Envanter Yönetimi:** Tedarikçi profilleri oluşturma, ürün kataloğu tanımlama ve stok takibi.
- **Sipariş ve Kurye Atamaları:** Gelen siparişlerin işlenmesi ve kuryelerin yük sınırlarına göre lojistik atamaları.
- **Fiyat ve Stok Sıralama:** Ürünlerin fiyat ve önceliklerine göre sıralanmasını sağlayan algoritmik çözümler (örn. Bubble Sort).
- **Yük ve Kapasite Optimizasyonu (Knapsack / Sırt Çantası):** Kurye taşıma kapasitesini ve teslimat verimini maksimize eden dağıtım algoritması.
- **Kalıcı Veri Depolama (File I/O):** Sistem durumunun dosya sistemine aktarılması ve program yeniden başlatıldığında verilerin eksiksiz yüklenmesi.

### 🛠️ Mimari ve OOP Prensipleri
- **Modüler Yapı:** Arayüz (`.h`) ve uygulama mantığının (`.cpp`) net sınırlarla ayrılması.
- **Kapsülleme (Encapsulation):** Güvenli veri erişimi ve denetimli metotlar.
- **Kalıtım ve Polimorfizm (Inheritance & Polymorphism):** Tedarik zinciri bileşenleri arasında mantıksal hiyerarşi ve genişletilebilirlik.
- **Operatör ve Fonksiyon Aşırı Yükleme (Overloading):** Akış ve karşılaştırma işlemleri için özelleştirilmiş operatörler.
- **Arkadaş Fonksiyonlar (Friend Functions):** Özel üye verilere kontrollü dış erişim.

### ⚙️ Derleme ve Çalıştırma

#### Gereksinimler
- **C++17** standartlarını destekleyen bir derleyici (g++, clang++, msvc).

#### g++ ile Derleme
```bash
# Depoyu yerel ortama kopyalayın
git clone https://github.com/kullanici-adiniz/supplier-management-system.git
cd supplier-management-system

# Projeyi derleyin
g++ -std=c++17 -Iinclude src/*.cpp -o supplier_system

# Çalıştırın
./supplier_system
```
