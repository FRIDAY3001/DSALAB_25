//menu driven program to sort an array in ascending order

#include <iostream>
#include "sortmethod.h"

int main() {
    int n;
    std::cout << "Enter size of array: ";
    std::cin >> n;
    int arr[n];
    std::cout << "Enter " << n << " elements:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

while (1) {
    int option;
    std::cout << "Select sorting method for the array: 1. Bubble Sort\n 2. Insertion Sort\n 3. Selection Sort\n 4.Exit\n";
    std::cin >> option;
    
    if ( option == 1 ) {
        bubble_sort(arr,n);
    }

    if ( option == 2) {
        insertion_sort(arr,n);
    }
    
    if ( option == 3 ) {
        selection_sort(arr,n);
    }

    if ( option == 4) {
        break;
    }
}

std::cout << "The sorted list: ";
for ( int i = 0;i < n;i++) {
    std::cout << arr[i] << " ";
}
std::cout << std::endl;

    return 0;
}