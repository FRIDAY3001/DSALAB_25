#include <iostream>
#include "sortmethod.h"

int LinearSearch(int arr[],int n,int key) {
    int status = 1;

    for (int i = 0;i < n;i++) {
        if (arr[i] == key) {
            std::cout << "The element is present in the array.\n";

            return i;
        }
    }

    std::cout << "The element is not present in the array.\n";
    return -1;


}

int BinarySearch(int arr[],int n,int key) {

    bubble_sort(arr,n);
    
    int l = 0,u = n-1;

    while ( l<=u) {
        int m = (u + l)/2;

        if ( arr[m] == key) {
            return key;
        }

        else if (arr[m] > key) {
            u = m - 1;
        }

        else {
            l = m + 1;
        }
    }
    return -1;
}

int main() {

    int n,element;
    std::cout << "Enter size of array: ";
    std::cin >> n;
    int arr[n];
    std::cout << "Enter " << n << " elements:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    std::cout << "Enter an element to search\n";
    std::cin >> element;

while (1) {

    int option;
    std::cout << "Select search method: 1. Linear Search\n 2. Binary Search\n 3.Exit\n";
    std::cin >> option;


    
    if ( option == 1 ) {
        LinearSearch(arr,n,element);
    }

    if ( option == 2) {
        int status = BinarySearch(arr,n,element);
        std::cout << status << "\n";
    }
    
    if ( option == 3 ) {
        break;
    }
}
    return 0;
}