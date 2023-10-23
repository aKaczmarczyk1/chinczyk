#include <iostream>
#include <string>

using namespace std;

struct Product {
    string name;
    float price;
};

void sort(Product* arr) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 9; j++) {
            if (arr[j].price < arr[j + 1].price) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    Product products[10];
    for (int i = 0; i < 10; i++) {
        Product newProduct;
        cout << "Podaj nazwe " << i + 1 << " produktu: ";
        cin >> newProduct.name;
        cout << "Podaj cene " << i + 1 << " produktu: ";
        cin >> newProduct.price;
        products[i] = newProduct;
    }
    sort(products);
    cout << endl << "Posortowana tablica: " << endl;
    for (int i = 0; i < 10; i++) {
        cout << products[i].name << " " << products[i].price << endl;
    }
    return 0;
}