#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <set>
#include <ctime>
#include "order.h"
#include "customer.h"
#include "product.h"
#include "createDate.h"

using namespace std;

int main() {
    Customer customer(1);

    std::set<Product> products1;
    products1.insert(Product(1, "Candy", "Sweets", 5.0));
    products1.insert(Product(2, "Chocolate", "Sweets", 10.0));
    products1.insert(Product(3, "Cooke", "Sweets", 35.0));

    std::set<Product> products2;
    products2.insert(Product(4, "Bread", "Bakery", 6.0));
    products2.insert(Product(5, "Bun with cheese", "Bakery", 8.0));
    products2.insert(Product(6, "Water", "Drinks", 5.0));

    Order order1(1, createDate(2020, 2, 16), createDate(2020, 2, 20), "completed", customer, products1);
    Order order2(2, createDate(2020, 4, 15), createDate(2020, 4, 20), "completed", customer, products2);
    Order order3(3, createDate(2020, 3, 14), createDate(2020, 3, 18), "completed", customer, products2);
    Order order4(4, createDate(2020, 2, 14), createDate(2020, 2, 18), "completed", customer, products2);

    double sum = 0.0;

    for (const Order& order : { order1, order2, order3, order4 }) {
        time_t orderTime = order.getOrderDate();
        tm* orderDate = localtime(&orderTime);

        if (orderDate->tm_year == 2020 - 1900 && orderDate->tm_mon == 1) {
            for (const Product& product : order.getProducts()) {
                sum += product.getPrice();
            }
        }
    }

    cout << "Sum of product prices in February 2020 orders: " << sum << endl;

    return 0;
}