# 🛒 Supermarket Management System

A comprehensive desktop application for managing supermarket operations, built with C++ and Qt framework. This system provides both administrative and user interfaces for efficient supermarket management.

## ✨ Features

### 👨‍💼 Administrative Features
- Category Management
  - Add new product categories
  - Remove existing categories
- Product Management
  - Add new products with details (name, price, quantity)
  - Remove products from inventory
  - Update product information
- Order Management
  - View and process customer orders
  - Track order history
  - Manage order status

### 👤 User Features
- User Authentication
  - Secure login system
  - User registration
- Shopping Experience
  - Browse products by categories
  - Search products using Trie data structure
  - View product details
- Shopping Cart
  - Add/remove items
  - Update quantities
  - View cart summary
- Order Processing
  - Checkout functionality
  - Order history
  - Order status tracking

## 🛠️ Technical Details

### 🏗️ Built With
- C++
- Qt Framework
- Data Structures
  - Trie (for efficient product search)
  - Custom data structures for inventory management

### 📁 Project Structure
```
supermarket-manager/
├── src/           # Source files
├── include/       # Header files
├── gui/          # GUI implementation
├── data/         # Data storage
├── ds-templates/ # Data structure templates
└── third-party/  # Third-party dependencies
```

## 📋 Prerequisites

- C++ compiler (C++11 or higher)
- Qt Framework (5.x or higher)
- CMake (for building)

## 🚀 Building and Running

1. Clone the repository:
```bash
git clone [repository-url]
cd supermarket-manager
```

2. Build the project:
```bash
mkdir build
cd build
cmake ..
make
```

3. Run the application:
```bash
./supermarket-manager
```

## Team
- Youssef Ashour
- Patrick Boules
- Ahmed Yasser
- Youssef Wael
- Youssef Ashoush
