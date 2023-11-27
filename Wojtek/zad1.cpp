#include <iostream>
using std::cout;
using std::cin;

class Produkt {
private: 
	std::string name;
	int cena;
public: 
	Produkt(std::string n, int c) {
		name = n;
		cena = c;
	}
	void WypiszProdukt() {
		cout << name << "'s price: " << cena << "\n";
	}
	int getCena(){
		return cena;
	}
};

int partition(int arr[], int start, int end)
{
 
    int pivot = arr[start];
 
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] >= pivot)
            count++;
    }
 
    // Giving pivot element its correct position
    int pivotIndex = start + count;
    std::swap(arr[pivotIndex], arr[start]);
 
    // Sorting left and right parts of the pivot element
    int i = start, j = end;
 
    while (i < pivotIndex && j > pivotIndex) {
 
        while (arr[i] >= pivot) {
            i++;
        }
 
        while (arr[j] < pivot) {
            j--;
        }
 
        if (i < pivotIndex && j > pivotIndex) {
            std::swap(arr[i++], arr[j--]);
        }
    }
 
    return pivotIndex;
}
 
void quickSort(int arr[], int start, int end)
{
 
    // base case
    if (start >= end)
        return;
 
    // partitioning the array
    int p = partition(arr, start, end);
 
    // Sorting the left part
    quickSort(arr, start, p - 1);
 
    // Sorting the right part
    quickSort(arr, p + 1, end);
}

int main() {

	/*
	przechowaj nazwe i cene -> pobierz od uzytkownika info o 10 produktach i wypisz od najdrozszych do najtanszych
	*/
	const int size = 10;
	Produkt produkty[size] = {
		 Produkt("A", 4), 
		 Produkt("B", 5),
		 Produkt("C", 12),
		 Produkt("D", 192),
		 Produkt("E", 2),
		 Produkt("F", 43),
		 Produkt("G", 14),
		 Produkt("H", 19),
		 Produkt("I", 1),
		 Produkt("J", 6)
		 };
	int* ceny = new int[size];
	for(int i = 0; i < size; i++){
		ceny[i] = produkty[i].getCena();
	}

	quickSort(ceny, 0, size-1);
	for(int i = 0; i < size; i++){
		for(int elem = 0; elem < size; elem++){
			if(produkty[elem].getCena() == ceny[i])
				produkty[elem].WypiszProdukt();
		}
	}
	delete ceny;
	return 0;
}
