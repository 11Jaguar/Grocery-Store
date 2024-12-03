#include <stdio.h>
#include <string.h>

// Structure to store product information
typedef struct {
    char name[20];
    float price;
    int quantity;
} Product;

// Recursive function to calculate total price for each product
float calculate_total(Product products[], int index, int count) {
    if (index >= count) {
        return 0; // Base case: no more products to process
    }
    // Calculate the total price for the current product
    products[index].quantity = products[index].quantity > 0 ? products[index].quantity : 0; // Ensure quantity is non-negative
    float product_total = products[index].price * products[index].quantity;
    printf("%-15s %5d x Rs.%6.2f = Rs.%7.2f\n", products[index].name, products[index].quantity, products[index].price, product_total);
    // Recursive call for the next product
    return product_total + calculate_total(products, index + 1, count);
}

int main() {
    // Array of products
    Product products[10] = {
        {"Apple", 150.00, 0},
        {"Banana", 50.00, 0},
        {"Milk", 60.00, 0},
        {"Bread", 20.50, 0},
        {"Jackfruit", 20.00, 0},
        {"Cheese", 50.00, 0},
        {"Rice", 40.20, 0},
        {"Fenugreek", 100.00, 0},
        {"Pumpkin", 80.00, 0},
        {"Coriander", 10.00, 0}
    };

    int count = sizeof(products) / sizeof(products[0]);
    printf("Welcome to the Grocery Billing System!\n");
    printf("Enter the quantity for the following products:\n");

    // Input quantities for each product
    for (int i = 0; i < count; i++) {
        printf("%-15s (Rs.%.2f): ", products[i].name, products[i].price);
        scanf("%d", &products[i].quantity);
    }

    // Print the bill
    printf("\n--- BILL ---\n");
    printf("%-15s %5s   %-6s   %-8s\n", "Product", "Qty", "Price", "Total");
    printf("---------------------------------------------\n");
    float grand_total = calculate_total(products, 0, count);
    printf("---------------------------------------------\n");
    printf("Grand Total: Rs.%.2f\n", grand_total);
    printf("-------------------------\n");
    printf("Thank you for shopping!\n");

    return 0;
}